#include "DirectionC.h"
#include <time.h>
#include <iostream>
#include <fstream>


DirectionC::DirectionC()
{
	limit = 0.1 + TimeMgr->GetTime();
	ifstream fin("resource/Location/location.txt");
	fin >> Floor.x >> Floor.y;
	fin >> Philla.x >> Philla.y;
	fin >> Character.x >> Character.y;
	

	m_pFloor = new Sprite("resource/map/first.png");
	m_pFloor->SetPosition(Floor);
	m_pPhilla = new Sprite("resource/item/philla/philla.png");
	m_pPhilla->SetPosition(Philla);
	m_pCharacter = new Sprite("resource/character/mancharacter_base/Right/main_character.png");
	m_pCharacter->SetPosition(Character);
	m_pLight = new Sprite("resource/background/light.png");
	m_pLight->SetScale(D3DXVECTOR2(0.6, 0.6));
	m_pLight->SetPosition(m_pPhilla->GetPosition().x - 340, 0);
	m_pFire = new Animation();
	m_pFire->Create(3, 15, true);
	m_pFire->GenerateAnimation("resource/item/fire/fire_base/animation");
	Light = m_pLight->GetPosition();
	Fire = D3DXVECTOR2(m_pPhilla->GetPosition().x + 5, m_pPhilla->GetPosition().y - 85);

	m_pQueke = new CSound("resource/sound/quake4.wav",true);
	m_pQueke->Play();
	m_pQueke->Pause();
	srand((unsigned)time(NULL));
}


DirectionC::~DirectionC()
{
	m_pQueke->Stop();
}

void DirectionC::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pLight->Update(eTime);
	m_pFloor->Update(eTime);
	m_pPhilla->Update(eTime);
	m_pCharacter->Update(eTime);
	m_pFire->Update(eTime);
	TimeMgr->Update(eTime);
	m_pQueke->Resume();
	if (limit < TimeMgr->GetTime() && n<60) {
		//m_pBackground->SetPosition(0, pow(-1 * (15 / (n + 1.5)), n));
		float rd = rand() % (5 - (n - 55));
		float rd2 = rand() % (20);
		m_pLight->SetPosition(D3DXVECTOR2(Light.x + rd2, Light.y + rd));
		m_pFloor->SetPosition(D3DXVECTOR2(Floor.x + rd2, Floor.y + rd));
		m_pPhilla->SetPosition(D3DXVECTOR2(Philla.x+rd2, Philla.y+rd));
		m_pCharacter->SetPosition(D3DXVECTOR2(Character.x+rd2, Character.y+rd));
		m_pFire->SetPosition(D3DXVECTOR2(Fire.x+rd2, Fire.y+rd));
		limit = TimeMgr->GetTime() + 0.03;
		n++;
	}
	else {
		m_pLight->SetPosition(Light);
		m_pFloor->SetPosition(Floor);
		m_pPhilla->SetPosition(Philla);
		m_pCharacter->SetPosition(Character);
		m_pFire->SetPosition(Fire);

	}
	if (n >= 60) {
		m_pQueke->Resume();
		SceneMgr->changeScene(new MainScene("third"));
	}
}

void DirectionC::Render() {
	ISceneNode::Render();
	m_pLight->Render();
	m_pFloor->Render();
	m_pPhilla->Render();
	m_pCharacter->Render();
	m_pFire->Render();
}