#include "DirectionB.h"
#include <iostream>
#include <fstream>
#include "SceneManager.h"
#include "MainScene.h"

DirectionB::DirectionB()
{
	ifstream fin("resource/Location/location.txt");
	fin >> Floor.x >> Floor.y;
	fin >> Philla.x >> Philla.y;
	fin >> Character.x >> Character.y;

	m_pFloor = new Sprite("resource/map/first.png");
	m_pFloor->SetPosition(Floor);
	m_pPhilla = new Sprite("resource/item/philla/philla.png");
	m_pPhilla->SetPosition(Philla);
	m_pCharacterRight = new Animation();
	m_pCharacterRight->Create(6, 15, true);
	m_pCharacterRight->GenerateAnimation("resource/character/maincharacter_fire/Animation/Right");
	m_pCharacterRight->SetPosition(Character);


	m_pLight = new Sprite("resource/background/light.png");
	m_pLight->SetScale(D3DXVECTOR2(0.6, 0.6));
	m_pLight->SetPosition(m_pPhilla->GetPosition().x - 340, 150);
	m_pFire = new Animation();
	m_pFire->Create(3, 15, true);
	m_pFire->GenerateAnimation("resource/item/fire/fire_base/animation");

	Fire = D3DXVECTOR2(m_pCharacterRight->GetPosition().x + 50, m_pCharacterRight->GetPosition().y - 60);
	m_pFire->SetPosition(Fire);

	StartTime = TimeMgr->GetTime() + 0.5;
	m_pWalk = new CSound("resource/sound/step_2.wav", true);
	m_pWalk->Play();
	m_pWalk->Pause();
}


DirectionB::~DirectionB()
{
	m_pWalk->Stop();
}

void DirectionB::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pLight->Update(eTime);
	m_pFloor->Update(eTime);
	m_pPhilla->Update(eTime);
	m_pCharacterRight->Update(eTime);
	m_pFire->Update(eTime);
	TimeMgr->Update(eTime);

	if ((StartTime <= TimeMgr->GetTime()) && m_pCharacterRight->GetPosition().x<700  && check) {
		m_pCharacterRight->SetPosition(m_pCharacterRight->GetPosition().x + 100 * eTime, m_pCharacterRight->GetPosition().y);
		m_pFire->SetPosition(m_pCharacterRight->GetPosition().x+50, m_pFire->GetPosition().y);
		m_pLight->SetPosition(m_pLight->GetPosition().x + 100 * eTime, m_pLight->GetPosition().y);
		m_pWalk->Resume();
	}
	else if(m_pCharacterRight->GetPosition().x>=700){
		check = false;
		m_pWalk->Pause();
	}
	if (m_pCharacterRight->GetPosition().x >=300&&!check) {
			m_pCharacterRight->GenerateAnimation("resource/character/maincharacter_fire/Animation/Left");
			Fire = D3DXVECTOR2(m_pCharacterRight->GetPosition().x - 25, m_pCharacterRight->GetPosition().y - 60);
			m_pFire->SetPosition(Fire);
			m_pCharacterRight->SetPosition(m_pCharacterRight->GetPosition().x - (100 * eTime), m_pCharacterRight->GetPosition().y);
			m_pFire->SetPosition(m_pFire->GetPosition().x - (100 * eTime), m_pFire->GetPosition().y);
			m_pLight->SetPosition(m_pLight->GetPosition().x - 100 * eTime, m_pLight->GetPosition().y);
			m_pWalk->Resume();
	}
	else if (m_pCharacterRight->GetPosition().x <= 300) {
		m_pCharacterRight->GenerateAnimation("resource/character/maincharacter_fire/AnimationStop");
		m_pWalk->Pause();
		SceneMgr->changeScene(new MainScene("second"));
	}
}

void DirectionB::Render() {
	ISceneNode::Render();
	m_pLight->Render();
	m_pFloor->Render();
	m_pPhilla->Render();
	m_pCharacterRight->Render();
	m_pFire->Render();
}