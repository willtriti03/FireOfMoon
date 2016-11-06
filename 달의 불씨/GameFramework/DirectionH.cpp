#include "DirectionH.h"



DirectionH::DirectionH()
{
	m_pFire = new Animation();
	m_pFire->Create(14, 8, true);
	m_pFire->GenerateAnimation("resource/item/fire/fire_none/Animation");
	m_pFire->SetPosition(493,315);
	m_pPhilla = new Sprite("resource/item/philla/philla.png");
	m_pPhilla->SetPosition(487,400);
	m_pCharacter = new Sprite("resource/character/mancharacter_base/Right/main_character.png");
	m_pCharacter->SetPosition(420,444);

	m_pMap = new Sprite("resource/map/five.png");
	m_pMap->SetPosition(-530, 0);
	m_pLight = new Sprite("resource/background/light.png");
	m_pLight->SetPosition(m_pPhilla->GetPosition().x - 340, 0);

	m_pMoon = new Animation();
	m_pMoon->Create(6, 2, false);
	m_pMoon->GenerateAnimation("resource/item/moon/moon_animation");

	m_pCurtainCall = new CurtainCall();

	StartTime = TimeMgr->GetTime() + 6;
	StartTimePlus = TimeMgr->GetTime() + 8;
}


DirectionH::~DirectionH()
{
}

void DirectionH::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pMap->Update(eTime);
	m_pPhilla->Update(eTime);
	m_pCharacter->Update(eTime);
	m_pLight->Update(eTime);
	m_pFire->Update(eTime);
	m_pMoon->Update(eTime);
	TimeMgr->Update(eTime);
	
	if (StartTime <= TimeMgr->GetTime()) {
		check = true;
		m_pCurtainCall->Update(eTime);
	}

	if (StartTimePlus < TimeMgr->GetTime()) {
		SceneMgr->changeScene(new StartScene);
	}
	
}

void DirectionH::Render() {
	ISceneNode::Render();
	m_pMoon->Render();
	m_pLight->Render();
	m_pMap->Render();
	m_pPhilla->Render();
	m_pFire->Render();
	m_pCharacter->Render();


	if(check == true) 
		m_pCurtainCall->Render();

}