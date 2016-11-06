#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "SceneManager.h"
#include "Physical.h"
#include "Fire.h"
class Light :public ISceneNode
{
private:
	Sprite *m_pLight;
	D3DXVECTOR2		startPos;
	
	int movement;
	int half_width = 0;
	int half_height = 0;
	
	bool phillaBool = true;
public:
	Light();
	~Light();

	void Update(float eTime);
	void Render();
	void UpdateCenterPos(Fire *fire);
	void LightScale(float lightpower);
	void SetMovement(int move){ movement = move;};
	void SetLightPosition(int x, int y){ m_pLight->SetPosition(x + startPos.x, y + startPos.y);};
	void SetPhillBool(bool boolean){ phillaBool = boolean;};
	void FollowMe(){ m_pLight->SetPosition(startPos);};
	void GotoPhilla(){ UpdateCenterPos(FireMgr); };
	bool GetPhillaBool(){ return phillaBool;};


};