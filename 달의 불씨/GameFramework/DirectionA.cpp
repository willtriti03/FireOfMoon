#include "DirectionA.h"



DirectionA::DirectionA()
{

	m_pFloor = new Sprite("resource/map/first.png");
	m_pPhilla = new Sprite("resource/item/philla/philla.png");
	m_pPhilla->SetPosition(500, 450);
	m_pCharacter = new Sprite("resource/character/mancharacter_base/Right/main_character.png");
	m_pCharacter->SetPosition(575, 500);
	m_pGlove = new Sprite("resource/item/touch/touch.png");
	m_pGlove->SetPosition(660, 550);
	m_pLight = new Sprite("resource/background/light.png");
	m_pLight->SetScale(D3DXVECTOR2(0.6, 0.6));
	m_pLight->SetPosition(160, 0);
	m_pFire = new Animation();
	m_pFire->Create(3, 15, true);
	m_pFire->GenerateAnimation("resource/item/fire/fire_base/animation");
	m_pFire->SetPosition(505, 370);

	StartTime = TimeMgr->GetTime() + 3;

	checkX = (m_pLight->GetCenterPosition().x == m_pCharacter->GetCenterPosition().x);
}


DirectionA::~DirectionA()
{
}


void DirectionA::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pLight->Update(eTime);
	m_pFloor->Update(eTime);
	m_pFire->Update(eTime);
	m_pPhilla->Update(eTime);
	m_pCharacter->Update(eTime);
	m_pGlove->Update(eTime);
	TimeMgr->Update(eTime);

	if ((StartTime <= TimeMgr->GetTime()) && m_pCharacter->GetCenterPosition().x>512) {
		m_pCharacter->SetPosition(m_pCharacter->GetPosition().x - 100 * eTime, m_pCharacter->GetPosition().y);
		m_pPhilla->SetPosition(m_pPhilla->GetPosition().x - 100 * eTime, m_pPhilla->GetPosition().y);
		m_pFire->SetPosition(m_pFire->GetPosition().x - 100 * eTime, m_pFire->GetPosition().y);
		m_pGlove->SetPosition(m_pGlove->GetPosition().x - 100 * eTime, m_pGlove->GetPosition().y);
		m_pLight->SetPosition(m_pLight->GetPosition().x - 100 * eTime, m_pLight->GetPosition().y);
	}
	if (m_pCharacter->GetCenterPosition().x <= 512) {
		SceneMgr->changeScene(new MainScene("first"));
	}

}

void DirectionA::Render() {
	ISceneNode::Render();
	m_pLight->Render();
	m_pFloor->Render();
	m_pFire->Render();
	m_pPhilla->Render();
	m_pCharacter->Render();
	m_pGlove->Render();

}