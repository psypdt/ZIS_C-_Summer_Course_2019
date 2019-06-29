#include "header.h"

#include "BaseBulletObject.h"
#include "CollisionDetection.h"
#include "ImageManager.h"
#include "AutoMovingEnemyObject.h"
#include "EnemyBulletObject.h"




BaseBulletObject::BaseBulletObject(int iStartX, int iStartY, BaseEngine* pGameEngine, double dVelocityY, bool bUseTopLeft)
	: DisplayableObject(iStartX, iStartY, pGameEngine, 5, 5, bUseTopLeft), 
	m_dVelocityY(dVelocityY), m_DidCollide(false), m_HasImage(false)
{
	m_iCurrentScreenX = iStartX;
	m_iCurrentScreenY = iStartY;

	m_dPosX = m_iCurrentScreenX;
	m_dPosY = m_iCurrentScreenY;

	setVisible(true);
}



BaseBulletObject::BaseBulletObject(int iStartX, int iStartY, BaseEngine * pGameEngine, std::string spriteUrl, int iFrames, double dVelocityY, bool bUseTopLeft)
	: DisplayableObject(iStartX, iStartY, pGameEngine, 5, 5, bUseTopLeft),
	m_dVelocityY(dVelocityY), m_DidCollide(false), m_HasImage(true), m_iFrames(iFrames),
	m_Image(ImageManager::loadImage(spriteUrl, false))
{
	this->m_iDrawWidth = m_Image.getWidth();
	this->m_iDrawHeight = m_Image.getHeight() / iFrames; /*get the first frame*/

	m_iCurrentScreenX = iStartX;
	m_iCurrentScreenY = iStartY;


	m_dPosX = m_iCurrentScreenX;
	m_dPosY = m_iCurrentScreenY;

	m_pTileManager = dynamic_cast<GameEngine*>(getEngine())->m_pTileManager;

	setVisible(true);
}



BaseBulletObject::~BaseBulletObject()
{
}





void BaseBulletObject::virtDraw()
{
	if (!isVisible())
		return;

	if (m_HasImage) 
	{
		int i = (getEngine()->getModifiedTime() / 250) % m_iFrames;
		
		m_Image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, (i * m_iDrawHeight),
			m_iCurrentScreenX + m_iStartDrawPosX, 
			m_iCurrentScreenY + m_iStartDrawPosY,
			m_iDrawWidth, m_iDrawHeight);
	} 
	else 
	{
		m_pEngine->drawForegroundRectangle(
			m_iCurrentScreenX - m_iDrawWidth,
			m_iCurrentScreenY - m_iDrawHeight,
			m_iCurrentScreenX + m_iDrawWidth,
			m_iCurrentScreenY + m_iDrawHeight,
			0xFF0000);
	}

}





void BaseBulletObject::virtDoUpdate(int iCurrentTime)
{
	if (!isVisible() || getEngine()->isPaused())
		return;

	m_dPosY -= m_dVelocityY;
	
	bool tmp = virtCheckBoundary();

	if (tmp)
	{
		delete this;
		return;
	}

	tmp = virtCheckCollision();

	if (tmp)
	{
		delete this;
		return;
	}

	tmp = virtTileInteraction();

	if (tmp)
	{
		delete this;
		return;
	}

	m_iCurrentScreenX =  (int)(m_dPosX);
	m_iCurrentScreenY = (int)(m_dPosY);
}




/*Handle the collision with the tile manager*/
bool BaseBulletObject::virtTileInteraction()
{
	if (m_pTileManager->isValidTilePosition(m_iCurrentScreenX, m_iCurrentScreenY))
	{
		int iTileX = m_pTileManager->getMapXForScreenX(m_iCurrentScreenX); /*Get the X value of the tile*/
		int iTileY = m_pTileManager->getMapYForScreenY(m_iCurrentScreenY); /*Get the Y value of the tile*/
		int iCurrentTile = m_pTileManager->getMapValue(iTileX, iTileY); /*Get the tile at (X, Y)*/

		if (iCurrentTile == 0)
			return false;

		m_pEngine->removeDisplayableObject(this);
		return true;
	}

	return false;
}






bool BaseBulletObject::virtCheckCollision()
{
	/*Check if there is collision with an enemy ship*/
	for (int i = 0; getEngine()->getDisplayableObject(i) != NULL; i++)
	{
		auto pEnemyShip = dynamic_cast<AutoMovingEnemyObject*> (getEngine()->getDisplayableObject(i));

		if (pEnemyShip == NULL)
			continue;

		if (CollisionDetection::checkRectangles(
			this->getDrawingRegionLeft(), this->getDrawingRegionRight(),
			this->getDrawingRegionTop(), this->getDrawingRegionBottom(),
			pEnemyShip->getDrawingRegionLeft(), pEnemyShip->getDrawingRegionRight(),
			pEnemyShip->getDrawingRegionTop(), pEnemyShip->getDrawingRegionBottom())
			) /*If there is a collision*/
		{
			pEnemyShip->m_Health_Mutex.lock();
			pEnemyShip->m_iHealth -= 5;
			pEnemyShip->m_Health_Mutex.unlock();


			/*no other bullet has landed the killing shot*/
			if (pEnemyShip->m_iHealth <= 0 && !pEnemyShip->m_bFirstHit)
			{
				pEnemyShip->m_Hit_Mutex.lock();
					dynamic_cast<GameEngine*> (m_pEngine)->m_oScore.incrementScore();
					pEnemyShip->m_bFirstHit = true;
					pEnemyShip->m_Hit_Mutex.unlock();
			}

			m_pEngine->removeDisplayableObject(this);
			return true;
		}
	}


	/*Check if there is collision with another bullet*/
	for (int i = 0; getEngine()->getDisplayableObject(i) != NULL; i++)
	{
		auto pEnemyBullet = dynamic_cast<EnemyBulletObject*> (getEngine()->getDisplayableObject(i));

		if (pEnemyBullet == NULL)
			continue;

		if (CollisionDetection::checkRectangles(
			this->getDrawingRegionLeft(), this->getDrawingRegionRight(),
			this->getDrawingRegionTop(), this->getDrawingRegionBottom(),
			pEnemyBullet->getDrawingRegionLeft(), pEnemyBullet->getDrawingRegionRight(),
			pEnemyBullet->getDrawingRegionTop(), pEnemyBullet->getDrawingRegionBottom())
			) /*If there is a collision*/
		{
			m_pEngine->removeDisplayableObject(this);
			return true;
		}
	}

	return false;
}




/*Check if bullet has exited screen, true implies this should be deleted*/
bool BaseBulletObject::virtCheckBoundary()
{
	if (m_dPosY < 0)
	{
		//m_pEngine->drawableObjectsChanged();
		m_pEngine->removeDisplayableObject(this);
		return true;
	}
	else if (m_dPosY > m_pEngine->getWindowHeight())
	{
		m_pEngine->removeDisplayableObject(this);
		return true;
	}

	return false;
}
