#pragma once

#include "DisplayableObject.h"
#include "GameEngine.h"
#include "PlayerHealthBarObject.h"



class DisplayableCharacter : public DisplayableObject
{
	/*Member Variables*/
public:
	int m_iHealth = 100;
	int m_iTimeDeath; /*The time when the player died*/
	bool m_bIsDead = false;
	double m_dCurrentX; /*Temp var to check if a move results in a out of bound violation*/
	double m_dCurrentY; /*Temp var to check if a move results in a out of bound violation*/


protected:
	int m_iStartX;
	int m_iStartY;
	int m_iLastLaser = 900;
	int m_iCurrentFrame;
	double m_dVelocityX;
	double m_dVelocityY;
	PlayerHealthBarObject* m_pHealthBar;
	SimpleImage m_image;




	/*Constructor/ Destructors */
public:
	DisplayableCharacter(BaseEngine* pEngine, std::string strURL, bool bUseTopLeft = true, bool bVisible = true);
	DisplayableCharacter(int iStartX, int iStartY, BaseEngine* pEngine, std::string strURL, double dVelocityX, double dVelocityY, bool bUseTopLeft = true, bool bVisible = true);


	~DisplayableCharacter();


	/*Virtual Functions*/
public:

	/*Drawing function from DisplayableObject*/
	void virtDraw() override;
	void virtDoUpdate(int iCurrentTime) override; 
	void virtKeyUp(int iKeyCode) override;
	bool virtTileInteraction();



protected:
	/*Movement/ Boundary check functions*/
	virtual void virtMoveCharacter();
	virtual void virtCheckBoundary();
	virtual void virtFireBullet();
	virtual void virtFireLaser();

};

