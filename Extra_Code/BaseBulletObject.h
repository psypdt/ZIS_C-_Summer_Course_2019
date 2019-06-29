#pragma once

#include "DisplayableObject.h"
#include "GameEngine.h"
#include "PsypdtTileManager.h"


class BaseBulletObject : public DisplayableObject
{
protected:
	int m_iFrames;
	double m_dVelocityY;
	double m_dPosX;
	double m_dPosY;
	SimpleImage m_Image;
	PsypdtTileManager* m_pTileManager;
	bool m_DidCollide;
	bool m_HasImage;


public:
	BaseBulletObject(int iStartX, int iStartY, BaseEngine* pGameEngine, double dVelocityY, bool bUseTopLeft = true);
	BaseBulletObject(int iStartX, int iStartY, BaseEngine* pGameEngine, std::string spriteUrl, int iFrame, double dVelocityY, bool bUseTopLeft = true);

	~BaseBulletObject();



	/*Drawing function from DisplayableObject*/
	void virtDraw() override;
	void virtDoUpdate(int iCurrentTime) override;
	
	virtual bool virtTileInteraction(); /*True -> tile was hit, false-> no tile was hit*/
	virtual bool virtCheckCollision();
	virtual bool virtCheckBoundary();

};
