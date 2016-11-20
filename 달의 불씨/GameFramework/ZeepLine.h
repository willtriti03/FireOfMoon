#pragma once
#include "ISceneNode.h"
#include "Physical.h"
#include "Sprite.h"
#include "Pole.h"
class Character;
class ZeepLine:virtual public ISceneNode,virtual public Physical 
{
private:
	Pole *m_pPole1;
	Pole *m_pPole2;

	Character *m_pChar;
public:
	ZeepLine();
	~ZeepLine();
	
	void Update(float eTime);
	void Render();
		
	void SetPole(Pole p1, Pole p2){ m_pPole1 = &p1; m_pPole2 = &p2; };
	void SetChar(Character *character){ m_pChar = character; };
	void MakeLine();
	void ThrowCharacter(int direction);
};


