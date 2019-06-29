#include "header.h"

#include "DisplayableCharacter.h"
#include "ImageManager.h"
#include "BaseBulletObject.h"
#include "LaserObject.h"



DisplayableCharacter::DisplayableCharacter(BaseEngine * pEngine, std::string strURL, bool bUseTopLeft, bool bVisible)
	: DisplayableObject(pEngine), m_image(pEngine->loadImage(strURL, false)), m_dVelocityX(1.0), m_dVelocityY(0)
{
	this->m_iDrawWidth = m_image.getWidth();
	this->m_iDrawHeight = m_image.getHeight()/3;

	// Offset within the drawing area to draw at - need to reset since width and height changed:
	m_iStartDrawPosX = bUseTopLeft ? 0 : -m_iDrawWidth / 2;
	m_iStartDrawPosY = bUseTopLeft ? 0 : -m_iDrawHeight / 2;

	m_dCurrentX = m_iStartDrawPosX;
	m_dCurrentY = m_iStartDrawPosY;

	m_pHealthBar = new PlayerHealthBarObject(m_pEngine, this, "images/PlayerAnimation/PlayerHealth.png");

	setVisible(true);
}




DisplayableCharacter::DisplayableCharacter(int iStartX, int iStartY, BaseEngine* pGameEngine, std::string urlImage, double dVelocityX = 3, double dVelocityY = 4, bool bUseTopLeft, bool bVisible)
	: DisplayableObject(iStartX, iStartY, pGameEngine, 100, 100, bUseTopLeft), m_iStartX(iStartX), m_iStartY(iStartY), m_dVelocityX(dVelocityX), m_dVelocityY(dVelocityY),
	m_image(ImageManager::get()->getImagebyURL(urlImage, true, false))
{
	m_iDrawWidth = m_image.getWidth();
	m_iDrawHeight = m_image.getHeight()/3;

	// Offset within the drawing area to draw at - need to reset since width and height changed:
	m_iStartDrawPosX = bUseTopLeft ? 0 : -iStartX;
	m_iStartDrawPosY = bUseTopLeft ? 0 : -iStartY;
		
	m_dCurrentX = m_iStartX;
	m_dCurrentY = m_iStartY;

	m_pHealthBar = new PlayerHealthBarObject(m_pEngine, this, "images/PlayerAnimation/PlayerHealth.png");

	
	setVisible(bVisible);
}



DisplayableCharacter::~DisplayableCharacter()
{
}




/*Draw the Character*/
void DisplayableCharacter::virtDraw()
{
	/*Can resolve animation issue by having another var, call it m_iDeathTime, assign it to modified time the moment you die, do (getModifiedTime()-m_iDeathTime)/250 mod 38 for complete animation*/
	if (isVisible())
	{
		if (!m_bIsDead)
		{
			int i = (getEngine()->getModifiedTime() / 250) % 3;

			m_image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, (i*m_iDrawHeight), 
				m_iCurrentScreenX + m_iStartDrawPosX, 
				m_iCurrentScreenY + m_iStartDrawPosY, 
				m_iDrawWidth, m_iDrawHeight);
			return;
		}

		else
		{
			int j = ((getEngine()->getModifiedTime() - m_iTimeDeath)/ 250) % 38;
			m_iCurrentFrame = j;

			m_image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, (j*m_iDrawHeight),
				m_iCurrentScreenX + m_iStartDrawPosX,
				m_iCurrentScreenY + m_iStartDrawPosY,
				m_iDrawWidth, m_iDrawHeight);
		}
	}
}






/*Update the object*/
void DisplayableCharacter::virtDoUpdate(int iCurrentTime)
{
	if (!isVisible() || getEngine()->isPaused())
		return;
	
	if (m_iHealth <= 0 && !m_bIsDead) /*Die if health is 0*/
	{
		m_bIsDead = true;
		m_iTimeDeath = getEngine()->getModifiedTime();
		m_image = ImageManager::get()->getImagebyURL("images/PlayerAnimation/playerDeathSprite.png", true, false);
		m_iDrawWidth = m_image.getWidth();
		m_iDrawHeight = m_image.getHeight() / 38;
		return;
	}


	if (m_bIsDead && m_iCurrentFrame < 37)
		return;


	if (m_bIsDead && m_iCurrentFrame == 37)
	{
		m_pHealthBar->m_bDeathAnimationComplete = true;
		getEngine()->removeDisplayableObject(this);
		delete this;
		return;
	}


	virtMoveCharacter();
	virtCheckBoundary();

	/* m_iCurrentScreen... refers to the top left corner of the object*/
	m_iCurrentScreenX = (int)(m_dCurrentX);
	m_iCurrentScreenY = (int)(m_dCurrentY);
	
	redrawDisplay();
}



/*Prevent the standard firing mode from being spammed*/
void DisplayableCharacter::virtKeyUp(int iKeyCode)
{
	if (m_bIsDead)
		return;

	switch (iKeyCode)
	{
		case SDLK_e:
			virtFireBullet();

		default:
			break;
	}
}




/*Overwrite this function for the player object to controll it via keyboard input*/
void DisplayableCharacter::virtMoveCharacter()
{
	if (m_bIsDead)
		return;

	if (getEngine()->isKeyPressed(SDLK_RIGHT))
	{
		m_dCurrentX += m_dVelocityX;
	}
	if (getEngine()->isKeyPressed(SDLK_LEFT))
	{
		m_dCurrentX -= m_dVelocityX;
	}
	if (getEngine()->isKeyPressed(SDLK_UP))
	{
		m_dCurrentY -= m_dVelocityY;
	}
	if (getEngine()->isKeyPressed(SDLK_DOWN))
	{
		m_dCurrentY += m_dVelocityY;
	}

	/*Fire the Massive laser*/
	if (getEngine()->isKeyPressed(SDLK_q)) /*Fires massive the laser*/
	{
		virtFireLaser();
	}
}




/*Check that character stays within screen*/
void DisplayableCharacter::virtCheckBoundary()
{
	if (m_dCurrentX < 0)
	{
		m_dCurrentX = 0;
	}
	if (m_dCurrentX >= getEngine()->getWindowWidth() - m_iDrawWidth)
	{
		m_dCurrentX = getEngine()->getWindowWidth() - m_iDrawWidth;
	}
	if (m_dCurrentY < 0)
	{
		m_dCurrentY = 0;
	}
	if (m_dCurrentY >= getEngine()->getWindowHeight() - m_iDrawHeight)
	{
		m_dCurrentY = getEngine()->getWindowHeight() - m_iDrawHeight;
	}
}





/*Fire side cannons*/
void DisplayableCharacter::virtFireBullet()
{
	getEngine()->drawableObjectsChanged();
	getEngine()->removeDisplayableObject(false);

	getEngine()->appendObjectToArray(new BaseBulletObject(
		m_iCurrentScreenX, m_iCurrentScreenY - 5, getEngine(), 
		"images/ProjectileAnimation/bulletSprite.png", 2, 3.0, false)); /*Left cannon*/

	getEngine()->appendObjectToArray(new BaseBulletObject(
		m_iCurrentScreenX + m_image.getWidth() - 20, m_iCurrentScreenY - 5, getEngine(), 
		"images/ProjectileAnimation/bulletSprite.png", 2, 3.0, false)); /*Right cannon*/

	getEngine()->setAllObjectsVisible(true);
}




/*Fire the large laser*/
void DisplayableCharacter::virtFireLaser()
{
	if ((getEngine()->getModifiedTime() - m_iLastLaser) < 900)
		return;

	getEngine()->drawableObjectsChanged();
	getEngine()->removeDisplayableObject(false);

	getEngine()->appendObjectToArray(new LaserObject(
		this->getXCentre() - 15, this->getYCentre() - 80, 
		getEngine(), "images/ProjectileAnimation/laserSprite.png", 9, 5.0, false)); 

	getEngine()->setAllObjectsVisible(true);

	m_iLastLaser = getEngine()->getModifiedTime();
	m_dCurrentY += 30; /*Add some recoil*/
}
