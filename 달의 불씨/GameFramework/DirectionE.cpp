#include "DirectionE.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ImageF.h"
DirectionE::DirectionE()
{
	limit = 0.1 + TimeMgr->GetTime();
	timecheck = 6 + TimeMgr->GetTime();
	ifstream fin("resource/Location/location.txt");
	fin >> MapLocation.x >> MapLocation.y;
	fin >> PhillaLocation.x >> PhillaLocation.y;
	fin >> CharacterLocation.x >> CharacterLocation.y;

	m_pMap = new Sprite("resource/map/five.png");
	m_pMap->SetPosition(MapLocation);
	m_pPhilla = new Sprite("resource/item/philla/philla.png");
	m_pPhilla->SetPosition(PhillaLocation);
	m_pCharacter = new Sprite("resource/character/mancharacter_base/Right/main_character.png");
	m_pCharacter->SetPosition(CharacterLocation);
	m_pLight = new Sprite("resource/background/light.png");
	m_pLight->SetScale(D3DXVECTOR2(0.6, 0.6));
	m_pLight->SetPosition(160, 0);

	m_pFire = new Animation();
	m_pFire->Create(3, 15, true);
	m_pFire->GenerateAnimation("resource/item/fire/fire_base/animation");

	m_pText = new Sprite("resource/UI/dialogue_1.png");
	m_pText->SetPosition(187, 0);
	LightLocation = m_pLight->GetPosition();
	FireLocation = D3DXVECTOR2(m_pPhilla->GetPosition().x+5, m_pPhilla->GetPosition().y - 85);
	m_pQueke = new CSound("resource/sound/quake4.wav", true);
	m_pQueke->Play();
	m_pQueke->Pause();
}


DirectionE::~DirectionE()
{
	m_pQueke->Stop();
}

void DirectionE::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pMap->Update(eTime);
	m_pPhilla->Update(eTime);
	m_pCharacter->Update(eTime);
	m_pLight->Update(eTime);
	m_pFire->Update(eTime);
	m_pText->Update(eTime);
	TimeMgr->Update(eTime);
	m_pQueke->Resume();
	if (limit < TimeMgr->GetTime() && n<60) {
		//m_pBackground->SetPosition(0, pow(-1 * (15 / (n + 1.5)), n));
		float rd = rand() % (40 - (n - 20));
		float rd2 = rand() % (40 - (n - 20));
		m_pLight->SetPosition(D3DXVECTOR2(LightLocation.x + rd2, LightLocation.y + rd));
		m_pMap->SetPosition(D3DXVECTOR2(MapLocation.x + rd2, MapLocation.y + rd));
		m_pPhilla->SetPosition(D3DXVECTOR2(PhillaLocation.x + rd2, PhillaLocation.y + rd));
		m_pCharacter->SetPosition(D3DXVECTOR2(CharacterLocation.x + rd2, CharacterLocation.y + rd));
		m_pFire->SetPosition(D3DXVECTOR2(FireLocation.x + rd2, FireLocation.y + rd));
		limit = TimeMgr->GetTime() + 0.03;
		n++;
	}
	else {
		
		m_pLight->SetPosition(LightLocation);
		m_pMap->SetPosition(MapLocation);
		m_pPhilla->SetPosition(PhillaLocation);
		m_pCharacter->SetPosition(CharacterLocation);
		m_pFire->SetPosition(FireLocation);
	}
	
	if (n >= 60) {
		m_pQueke->Pause();
		check = true;
	}

	if (timecheck < TimeMgr->GetTime()) {
		SceneMgr->changeScene(new ImageF);
	}
}

void DirectionE::Render() {
	ISceneNode::Render();
	
	
	m_pLight->Render();
	m_pMap->Render();
	m_pPhilla->Render();
	m_pFire->Render();
	m_pCharacter->Render();
	if (check == true) {
		m_pText->Render();
		
	}
}
