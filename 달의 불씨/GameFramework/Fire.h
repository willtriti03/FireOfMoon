#pragma once
#define FireMgr Fire::GetInstance()
#include "Wind.h"
#include "ISceneNode.h"
#include "Animation.h"
#include "Wind.h"
#include "Character.h"


class Light;
class Fire :public ISceneNode
{
private:
	bool perfectFire;
	bool hang;
	float fireSize;

	float time;
	float timer;

	int upter = 0;
	int leftFire = 0;
	int times = 0;
	int timecheck = 0;

	int *playerView;

	bool charBool = false;

	RECT      m_rColl;
	Animation   *m_pAnima;
	Character   *m_pChar;
	D3DXVECTOR2 windstate;
	D3DXVECTOR2 centerpoint;
	Light *m_pLight;
public:
	Fire();
	~Fire();

	D3DXVECTOR2 GetFireCenter(){ return centerpoint; };

	float GetTime(){ return time; };

	int     GetTimer(){ return timer; };
	int     GetLeftFire(){ return leftFire; };

	bool GetHang(){ return hang; };
	bool GetPerfectFire(){ return perfectFire; };

	float GetFireSize(){ return fireSize; };

	void Update(float eTime);
	void Render();

	void Ground(){ timer = 1; };
	void Upgrade(){ fireSize += 0.1; m_pAnima->SetScale(D3DXVECTOR2(fireSize, fireSize)); };
	void DownGrade(){ fireSize -= 0.1; m_pAnima->SetScale(D3DXVECTOR2(fireSize, fireSize)); };
	void Windzone(){ timer = 2; };
	void ResetFire();
	void PickUpFire(){ hang = true; };
	void DropDownFire(){ hang = false; time = 0; };

	void setLight(Light *light) { m_pLight = light; };

	void SetPlayerView(int *watchView){ playerView = watchView; };
	void SetFirePos(int x, int y){ m_pAnima->SetPosition(x, y); };
	void SetFirePos(D3DXVECTOR2 pos){ m_pAnima->SetPosition(pos.x - (40 * (fireSize)*leftFire), pos.y); };
	void UpdateCollision();
	void GetChar(Character *chars){ m_pChar = chars; };
	void FollowChar(){ charBool = true; };
	void LostChar(){ charBool = false; };


	void LeftAni();
	void RightAni();
	void BaseAni();
	void NoneAni();
	static Fire* GetInstance();
};
