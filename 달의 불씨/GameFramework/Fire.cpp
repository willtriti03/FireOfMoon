#include "Fire.h"
#include <stdio.h>
#include <iostream>
#include "Light.h"
Fire::Fire()
{
	perfectFire = false;
	hang = false;
	fireSize = 1;

	time = 0;
	timer = 1;
	windstate = D3DXVECTOR2(0, 0);
	m_pAnima = new Animation();
	m_pAnima->Create(3, 15);
	m_pAnima->GenerateAnimation("resource/item/fire/fire_base/animation");
	m_pAnima->SetScale(D3DXVECTOR2(1, 1));
}


Fire::~Fire()
{
}

void Fire::Update(float eTime){
	windstate = WindMgr->GetWindState();
	m_pAnima->Update(eTime);
	if (hang){
		time += eTime*upter;
		if (time > 1){
			time = 0;
			times++;
			timecheck++;
		}
	}
	if (times >= 90){
		fireSize = 0;
		times = 0;
	}
	if (timecheck % 10 == 0 && timecheck != 0) {
		timecheck = 0;
		DownGrade();
	}
	if (windstate.x == 1 && *playerView*windstate.y == -1){
	}
	if (charBool){

		m_pAnima->SetPosition(m_pChar->centerPoint.x - 10 - (50 * leftFire)*(fireSize + 0.5), m_pChar->centerPoint.y - (100 * (fireSize - 0.1)) - 70);


	}
	UpdateCollision();

}
void Fire::Render(){
	ISceneNode::Render();
	m_pAnima->Render();

}

void Fire::ResetFire(){
	perfectFire = false;
	hang = false;

	fireSize = 1;
		
	time = 0;
	timer = 1;
	times = 0;
	*playerView = 0;

	windstate = D3DXVECTOR2(0, 0);
	m_pAnima->SetScale(D3DXVECTOR2(fireSize, fireSize));

}
void Fire::UpdateCollision(){
	m_rColl.left = m_pAnima->GetPosition().x;
	m_rColl.top = m_pAnima->GetPosition().y;
	m_rColl.right = m_pAnima->GetPosition().x + m_pAnima->GetNowFrameSprite()->GetRect().right;
	m_rColl.bottom = m_pAnima->GetPosition().y + m_pAnima->GetNowFrameSprite()->GetRect().bottom;
	centerpoint = D3DXVECTOR2(m_rColl.left + abs((m_rColl.right - m_rColl.left) / 2), abs((m_rColl.bottom - m_rColl.top) / 2) + m_rColl.top);
	//printf("%f %f\n", centerpoint.x, centerpoint.y);
}

void Fire::LeftAni(){
	m_pAnima->Create(3, 15);
	m_pAnima->GenerateAnimation("resource/item/fire/fire_wind/left");
	leftFire = 1;
	upter = 2;
}
void Fire::RightAni(){
	m_pAnima->Create(3, 15);
	m_pAnima->GenerateAnimation("resource/item/fire/fire_wind/right");
	leftFire = 0;
	upter = 2;
}
void Fire::BaseAni(){
	m_pAnima->Create(3, 15);
	m_pAnima->GenerateAnimation("resource/item/fire/fire_base/animation");
	leftFire = 0;
	upter = 1;
}
void Fire::NoneAni(){
	m_pAnima->Create(5, 5, false);
	m_pAnima->GenerateAnimation("resource/item/fire/fire_none");
}
Fire* Fire::GetInstance() {
	static Fire Instance;
	return &Instance;
}