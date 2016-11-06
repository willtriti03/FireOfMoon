#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "Liner.h"
class Physical : virtual public ISceneNode{
private:
	int				max;
	int				length;
	int				phyMax;
	int				phycode;
	int				address;
	int				lowRadian;
	int				spanRadian;
	
	bool			*renderbool;

	RECT			m_rColl;
	
	Sprite			*m_pObject;

	Physical		*m_pPhy;

	
	D3DXVECTOR2		crashPoint;
	D3DXVECTOR2		*elliPoint;
	D3DXVECTOR2		*m_pGroundPoint;

public:
	Physical();
	~Physical();

	RECT			GetRect(){ return m_rColl; };

	D3DXVECTOR2		startPos;
	D3DXVECTOR2		centerPoint;
	D3DXVECTOR2		*GetElli(){ return elliPoint; };
	
	int				FindPoint(int x);
	
	int				EllipseX(int x,int mp);
	int				EllipseY(int y,int mp);
	int				EllipseRX(int x, int mp){ return EllipseX(((x - centerPoint.x) - (int)(x - centerPoint.x) % 10), mp); };
	int				EllipseRY(int y, int mp){ return EllipseY(((y - centerPoint.y) - (int)(y - centerPoint.y) % 10), mp); };
	
	int				GetMax()		{ return phyMax; };
	int				GetAddress()	{ return address; };
	int				GetPhyCode()	{ return phycode; };
	int				GetLowRadian()	{ return lowRadian; };
	int				GetSpanRadian()	{ return spanRadian; };
	
	bool			GetRenderBool()	{ return *renderbool; };
	D3DXVECTOR2		GetSunPosition(){ return m_pObject->GetPosition(); };


	bool			Crush(Physical *phy1);
	bool			GroundCheck(int *move, bool stop);

	void			Update(float eTime);
	void			Render();

	void			SetTemCollison();
	void			SetCollosion(int length);
	void			SetGravityObject(Sprite* object);
	void			SetLength(int max)				{ this->max = max; };
	void			SetGround(D3DXVECTOR2 *list)	{ m_pGroundPoint = list; };
	void			SetPhyCode(int phycode)			{ this->phycode = phycode; };
	void			SetAddress(int address)			{ this->address = address; };
	void			SetSunPosition(D3DXVECTOR2 move){ move.x +=startPos.x; move.y +=startPos.y; m_pObject->SetPosition(move); };
	void			SetSunPosition(int x, int y)	{ m_pObject->SetPosition(x+startPos.x, y+startPos.y); };
	void			SetRenderBoolean(bool *boolean)	{ renderbool = boolean; };

	void			Gravity(int *move,bool stop);
};
/*
PhyCode
character	0
touch		1
philla		2
stick		3
Fan			4
npc			5
moon		6
*/
//27
//37 39