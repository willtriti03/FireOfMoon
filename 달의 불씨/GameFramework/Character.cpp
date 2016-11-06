#include "Character.h"
#include "Fire.h"
#include "MainScene.h"
#include "SpawnManager.h"
#include "Light.h"
#include "NextStageManager.h"

#define MOVE 6
Character::Character(D3DXVECTOR2 *list, int max, D3DXVECTOR2 startPos, MainScene *main, SpawnManager *sm, Light *lg, CrashManager *cm) {
	m_pSpawn = sm;
	m_pLight = lg;
	m_pCrash = cm;
	movement = 0;
	m_pMain = main;
	this->max = max;
	SetLength(max);
	SetGround(list);
	startPosition = startPos;
	SetPhyCode(0);
	FireMgr->SetPlayerView(&watchingView);

	m_pCharacter = new Sprite("resource/character/mancharacter_base/Right/main_character.png");
	m_pCharacter->SetPosition(startPosition);
	SetGravityObject(m_pCharacter);
	SetTemCollison();

	right = 1023 - m_pCharacter->GetRect().right;
	FireMgr->GetChar(this);

	m_pAnim = new Animation();
	RunAnimRight();
	m_pWalk =new CSound("resource/Sound/step_2.wav",true);
	m_pWalk->Play();
	m_pWalk->volumeUp();
	m_pWalk->Pause();
	m_pWind = new CSound("resource/Sound/wind.wav", true);
	m_pWind->Play();
	m_pWind->volumeUp();
	m_pWind->volumeUp();
	m_pWind->volumeUp();
	m_pWind->volumeUp();
	m_pWind->Pause();

}


Character::~Character()
{
	m_pWind->Stop();
	m_pWalk->Stop();

}

void Character::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pCharacter->Update(eTime);
	m_pAnim->SetPosition(m_pCharacter->GetPosition());
	m_pAnim->Update(eTime);
	gravityMode = 0;

	if (InputMgr->keyState(39) == 3 && m_pCharacter->GetPosition().x < right) {
		movement += MOVE;
		if (movement > 0 && movement < max - 1024) {
			stop = true;
			m_pMain->CharacterMoved(movement);
		}
		else if (0 > movement || movement >= max - 1024) {
			m_pCharacter->SetPosition(D3DXVECTOR2(m_pCharacter->GetPosition().x + MOVE, m_pCharacter->GetPosition().y));
			stop = false;

		}//
		SetWatchingView(1);

	}
	if (InputMgr->keyState(37) == 3 && m_pCharacter->GetPosition().x > 0) {
		movement -= MOVE;
		if (movement >= 0 && movement < max - 1024) {
			stop = true;
			m_pMain->CharacterMoved(movement);
		}
		else if (0 > movement || movement >= max - 1024) {
			m_pCharacter->SetPosition(D3DXVECTOR2(m_pCharacter->GetPosition().x - MOVE, m_pCharacter->GetPosition().y));
			stop = false;
		}
		SetWatchingView(-1);


	}
	m_pTmp = m_pCrash->CheckTest(movement);
	if (m_pTmp->GetPhyCode() != 0 && m_pTmp->GetPhyCode() != 2&& m_pTmp->GetPhyCode()!=5)
		m_pFont->Play(5);
	//printf("%d %d\n", hand, glove);
	if (InputMgr->keyState('Z') == 4) {
		m_pTmp = m_pCrash->CheckTest(movement);
		if (hand == 0 || (hand == 1 && !bring)) {
			m_pBring = m_pTmp;
			if (m_pBring->GetPhyCode() == 1) {
				m_pSpawn->ChageBool(m_pBring, false);
				hand = m_pBring->GetPhyCode();
				glove = 1;
				touchsaver = (Touch *)m_pBring->GetAddress();
				m_pFont->Play(0);
			}
			if (m_pBring->GetPhyCode() != 2) {
				m_pSpawn->ChageBool(m_pBring, false);
				hand = m_pBring->GetPhyCode();
				if (hand == 3)
					m_pFont->Play(3);
				else if (hand==4)
					m_pFont->Play(4);

			}
		}
		else if(!(hand!=1&&hand!=0)||bring){
			m_pFont->Play(2);
		}
		if (glove == 1 && hand == 0){
			hand = 1;
			m_pBring = touchsaver;
		}

	}

	if (InputMgr->keyState('X') == 4) {
		if (ItemEvent(hand, m_pCrash->CheckTest(movement)));
		
	}
	if (m_pCharacter->GetPosition().x > right) {
		m_pCharacter->SetPosition(1024 - m_pCharacter->GetRect().right, m_pCharacter->GetPosition().y);
	}
	if (m_pCharacter->GetPosition().x < 0) {
		m_pCharacter->SetPosition(0, m_pCharacter->GetPosition().y);
	}


	Gravity(&movement, stop);
	//printf("%d %f %f\n", movement, m_pCharacter->GetPosition().x,m_pCharacter->GetPosition().y);
	windstate = WindMgr->WindZoneCheck(D3DXVECTOR2(movement + 512, 0));
	if (windstate.x == 1&&bring) {
		if (windstate.y * watchingView == -1 && windstate.y == 1) {
			FireMgr->RightAni();
			m_pWind->Resume();
		}
		else if (windstate.y * watchingView == -1 && windstate.y == -1) {
			FireMgr->LeftAni();
			m_pWind->Resume();
		}
		else {
			FireMgr->BaseAni();
			m_pWind->Pause();
		}
	}
	else {
		FireMgr->BaseAni();
		m_pWind->Pause();
	}

	ImageSet();
	AniReset();
	if (InputMgr->keyState(37) == 3) {
		LeftAniSet();
		check2 = false;
		m_pWalk->Resume();
	}
	else if (InputMgr->keyState(39) == 3) {
		RightAniSet();
		check2 = false;
		m_pWalk->Resume();
	}
	else {
		check2 = true;
		m_pWalk->Pause();
	}


}

void Character::Render() {
	ISceneNode::Render();
	if (check2 == true)
		m_pCharacter->Render();
	if(check2==false)
		m_pAnim->Render();
}

void Character::SetMovement(int x, int y) {
	movement = x -495;
	if (movement < 0) {
		m_pCharacter->SetPosition(x, y);
	}
	else if (max - 1024 <= movement) {
		m_pCharacter->SetPosition(x - max + 1024, y);
		m_pMain->CharacterMoved(movement);

	}
	else {
		m_pCharacter->SetPosition(m_pCharacter->GetPosition().x , y);
		m_pMain->CharacterMoved(movement);
	}

}

bool Character::ItemEvent(int useCode, Physical *target) {
	switch (useCode) {
	case 0:
		switch (target->GetPhyCode()) {
		case 2:
			m_pFont->Play(1);
			return true;
			break;
		}
		break;
	case 1:
		switch (target->GetPhyCode()) {
		case 1:
			return true;
			break;
		case 2:
			Philla *ph;
			ph = (Philla *)target->GetAddress();
			Touch *th;
			th = (Touch *)m_pBring->GetAddress();
			if (!th->FireState() && ph->GetFireBool()) {
				if (watchingView)
					Fire_useAnimRight();
				else
					Fire_useAnimLeft();
				check2 = false;
				GageMgr->SetGage(1);
				GageMgr->Start();
				m_pMain->UpdateControl(1);

				ph->SetFire(false);
				ph->LostFire();
				th->TurnOn();
				FireMgr->FollowChar();
				FireMgr->PickUpFire();

				bring = true;
				oneTime = false;


			}
			else if (th->FireState() && !ph->GetFireBool()) {
				if (watchingView)
					Fire_useAnimRight();
				else
					Fire_useAnimLeft();
				check2 = false;
				th->TurnOff();
				FireMgr->LostChar();		
				ph->SetFire(true);
				ph->GetFire(FireMgr);

				m_pSpawn->SetFirePhilla(ph->GetPhillaPosition());
				m_pLight->FollowMe();
				FireMgr->DropDownFire();
				GageMgr->SetGage(1);
				GageMgr->Start();
				m_pMain->UpdateControl(1);
				bring = false;
				oneTime = false;
				StageMgr->PickUpGlove();

				if (ph->GetRealPhilla())
					StageMgr->RealUse();
			}
			return true;
			break;
		case 3:
			return true;
			break;
		case 4:
			return true;
			break;
		case 5:
			if (bring){
				StageMgr->MetNPC();
			}
			return true;
			break;
		default:
			return false;
		}
		break;
	case 3:
	case 4:
		switch (target->GetPhyCode()) {
		case 1:
			return true;
			break;
		case 2:
			Philla *ph;
			ph = (Philla*)target->GetAddress();
			if (ph->GetFireBool()) {
				if (watchingView)
					Fire_useAnimRight();
				else
					Fire_useAnimLeft();
				check2 = false;
				FireMgr->Upgrade();
				glove = 0;
				hand = 0;
				m_pMain->UpdateControl(3);
				GageMgr->SetGage(3);
				GageMgr->Start();
				m_pSpawn->SwitchPoint(m_pBring->startPos); 
				oneTime = false;
				StageMgr->UpgradeFire();
			
			}
			return true;
			break;
		case 3:
			return true;
			break;
		case 4:
			return true;
			break;
		case 5:
			return true;
			break;
		default:
			return false;
		}
		break;
	default:
		return false;
	}

}


void Character::FanAnimRight() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_fan/Animation/Right");

}

void Character::FanAnimLeft() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_fan/Animation/Left");


}

void Character::Fire_useAnimRight() {
	m_pAnim->Create(5, 0.5, false);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_fire_use/Animation/Right");
	m_pCharacter->SetImage("resource/character/maincharacter_fire_use/l_maincharacter_run_fire_use.png");
	check2 = true;
}

void Character::Fire_useAnimLeft() {
	m_pAnim->Create(5, 0.5, false);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_fire_use/Animation/Left");
	m_pCharacter->SetImage("resource/character/maincharacter_fire_use/r_maincharacter_run_fire_use.png");

	check2 = true;
}


void Character::FireAnimRight() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_fire/Animation/Right");

}

void Character::FireAnimLeft() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_fire/Animation/Left");

}


void Character::RunAnimLeft() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_run/Animation/Left");


}

void Character::RunAnimRight() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_run/Animation/Right");

}

void Character::StrawAnimRight() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_straw/Animation/Right");

}

void Character::StrawAnimLeft() {
	m_pAnim->Create(6, 15, true);
	m_pAnim->GenerateAnimation("resource/character/maincharacter_straw/Animation/Left");

}

void Character::ImageSet(){
	switch (hand){
	case 0:
	case 1:
		if (bring){
			if (watchingView == 1)
				m_pCharacter->SetImage("resource/character/maincharacter_fire/r_maincharacter_fire.png");
			else
				m_pCharacter->SetImage("resource/character/maincharacter_fire/l_maincharacter_fire.png");
		
		}
		else{
			if (watchingView == 1)
				m_pCharacter->SetImage("resource/character/mancharacter_base/Right/main_character.png");
			else
				m_pCharacter->SetImage("resource/character/mancharacter_base/Left/maincharacter.png");
		}
		break;
	case 3:
		if (watchingView == 1)
			m_pCharacter->SetImage("resource/character/maincharacter_straw/r_maincharacter_straw.png");
		else
			m_pCharacter->SetImage("resource/character/maincharacter_straw/l_maincharacter_straw.png");
		break;
	case 4:
		if (watchingView == 1)
			m_pCharacter->SetImage("resource/character/maincharacter_fan/r_maincharacter_fan.png");
		else
			m_pCharacter->SetImage("resource/character/maincharacter_fan/l_maincharacter_fan.png");
		break;
	}

}

void Character::RightAniSet(){
	switch (hand)
	{
	case 0:
	case 1:
		if (bring)
			FireAnimRight();
		else
			RunAnimRight();
		break;
	case 3:
		StrawAnimRight();
		break;
	case 4:
		FanAnimRight();
		break;

	}

}
void Character::LeftAniSet(){
	switch (hand)
	{
	case 0:
	case 1:
		if (bring)
			FireAnimLeft();
		else
			RunAnimLeft();
		break;
	case 3:
		StrawAnimLeft();
		break;
	case 4:
		FanAnimLeft();
		break;

	}

}
void Character::AniReset(){
	if (!oneTime){
		if (watchingView == 1)
			RightAniSet();
		else
			LeftAniSet();
		oneTime = true;
	}
}
//027300947