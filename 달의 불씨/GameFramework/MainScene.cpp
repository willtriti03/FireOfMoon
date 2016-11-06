#include"MainScene.h"
#include "NextStageManager.h"
#include "DirectionI.h"
#include <conio.h>
#include "PopUp.h"


#define FIRE	"resource\\mapdata\\mapFire\\"
#define NPC		"resource\\mapdata\\mapNpc\\"
#define STICK	"resource\\mapdata\\mapStick\\"
#define WIND	"resource\\mapdata\\mapWind\\"
#define TOUCH	"resource\\mapdata\\mapTouch\\"
#define PHILLA	"resource\\mapdata\\mapPhilla\\"
#define MAP		"resource\\mapdata\\mapLine\\"
#define FAN		"resource\\mapdata\\mapFan\\"
#define CHARA	"resource\\mapdata\\mapChar\\"


MainScene::MainScene(string mapName){

	m_pSpawn = new SpawnManager();
	m_pLight = new Light();
	m_pSpawn->SetLight(m_pLight);
	m_pCrash = new CrashManager();
	stage = mapName;
	LoadData(mapName);
	m_pMap = new Sprite("resource/map/"+mapName+".png");
	m_pStarMap = new Sprite("resource/background/bg.png");
	m_pMap->SetPosition(D3DXVECTOR2(0, -5));
	m_pChar = new Character(pixcelPoint, max, D3DXVECTOR2(463, 100), this, m_pSpawn, m_pLight, m_pCrash);
	m_pDirect = new DirectionI(mapName);
	ifstream fp(CHARA + mapName + ".mdatC");
	fp >> x >> y;
	fp.close();
	m_pChar->SetMovement(x, y);

	m_pFonts	= new PrintFont();
	m_pPopUp	= new PopUp();


	
	m_pPopUp->SetBool(&popup);
	m_pChar->SetFonts(m_pFonts);
	m_pFonts->Stop();
	m_pLight->LightScale(0.6);
	m_pCrash->SetCharacter(m_pChar);
	StageMgr->SetStage(stage);
	m_pLight->UpdateCenterPos(FireMgr);
}

MainScene::~MainScene(){
	m_pSpawn->CommitShakes(m_pMap->GetPosition(), m_pChar->GetSunPosition());
	m_pSpawn->CommitGlove(stage);
	m_pCrash->CleanStack();
	m_pSpawn->FflushList();
	FireMgr->ResetFire();
	FireMgr->LostChar();
	SAFE_DELETE(pixcelPoint);

}

void MainScene::Update(float eTime){
	ISceneNode::Update(eTime);
	if (!popup){
		if (updateControl){
			m_pChar->AniReset();
			m_pChar->Update(eTime);
		}
		else if (!updateControl){
			if (TimeMgr->GetTime() >= limit){
				updateControl = true;
			}
		}
		m_pMap->Update(eTime);
		m_pFonts->Update(eTime);
		m_pStarMap->Update(eTime);

		m_pLight->UpdateCenterPos(FireMgr);
		m_pLight->FollowMe();
		
		FireMgr->Update(eTime);
		m_pSpawn->Update(eTime);
		m_pLight->Update(eTime);
		TimeMgr->Update(eTime);
		GageMgr->Update(eTime);
		StageMgr->Update(eTime);
		//shangus

		if (FireMgr->GetFireSize() == 0){
			SceneMgr->changeScene(new DirectionI(stage));
		}
		
		else if (InputMgr->keyState(27)==4){
			popup = true;
		}


	}

	else
		m_pPopUp->Update(eTime);

	
}

void MainScene::Render(){
	ISceneNode::Render();
	m_pStarMap->Render();
	m_pLight->Render();
	m_pMap->Render();
	m_pChar->Render();
	//m_pGui->Render();
	m_pFonts->Render();
	FireMgr->Render();
	m_pSpawn->Render();
	GageMgr->Render();
	if (popup){
		m_pPopUp->Render();
	}

	StageMgr->Render();
}

void MainScene::CharacterMoved(int move){
	m_pMap->SetPosition(D3DXVECTOR2(-1 * move, m_pMap->GetPosition().y));
	m_pStarMap->SetPosition(D3DXVECTOR2(-1 * move, m_pMap->GetPosition().y));
	m_pSpawn->MoveMap(move);

}

void MainScene::UpdateControl(float time){
	limit = time+TimeMgr->GetTime();
	updateControl = false;
}

void MainScene::LoadData(string mapName){
	int maxum;

	ifstream fp(MAP + mapName + ".mdatL");
	fp >> width >> height >> max;
	pixcelPoint = new D3DXVECTOR2[max];
	for (int i = 0; i < max; ++i){
		fp >> x >> y;
		pixcelPoint[i] = D3DXVECTOR2(x, y);
	}
	fp.close();



	fp.open(FAN + mapName + ".mdatF");
	fp >> maxum;
	m_pFan = new Fan[maxum];
	for (int i = 0; i < maxum; ++i){
		fp >> x >> y>>rt;
		m_pFan[i].SetCrashMgr(m_pCrash);
		m_pFan[i].SetPos(x, y);
		m_pFan[i].SetRenderBool(rt);
		m_pFan[i].SetPhyCode(4);
	}
	m_pSpawn->PushFan(m_pFan, maxum);
	fp.close();


	fp.open(TOUCH + mapName + ".mdatT");
	fp >> maxum;
	m_pTouch = new Touch[maxum];
	for (int i = 0; i < maxum; ++i){
		fp >> x >> y >> rt;
		m_pTouch[i].SetCrashMgr(m_pCrash);
		m_pTouch[i].SetPos(x, y);
		m_pTouch[i].SetRenderBool(rt);
		m_pTouch[i].SetPhyCode(1);

	}
	m_pSpawn->PushTouch(m_pTouch, maxum);

	fp.close();

	fp.open(STICK + mapName + ".mdatS");
	fp >> maxum;
	m_pStick = new Stick[max];
	for (int i = 0; i < maxum; ++i){
		fp >> x >> y >> rt;
		m_pStick[i].SetCrashMgr(m_pCrash);
		m_pStick[i].SetPos(x, y);
		m_pStick[i].SetRenderBool(rt);
		m_pStick[i].SetPhyCode(3);
	}
	m_pSpawn->PushStick(m_pStick, maxum);

	fp.close();


	fp.open(NPC + mapName + ".mdatN");
	fp >> maxum;
	m_pNpc = new Npc[max];
	for (int i = 0; i < maxum; ++i){
		fp >> x >> y >> rt;
		m_pNpc[i].SetCrashMgr(m_pCrash);
		m_pNpc[i].SetPos(x, y);
		m_pNpc[i].SetRenderBool(rt);
		m_pNpc[i].SetPhyCode(5);
	}
	m_pSpawn->PushNpc(m_pNpc, maxum);

	fp.close();



	bool as;
	fp.open(PHILLA + mapName + ".mdatP");
	fp >> maxum;
	m_pPhilla = new Philla[maxum];
	for (int i = 0; i < maxum; ++i){
		fp >> x >> y>> rt>>as;
		m_pPhilla[i].SetCrashMgr(m_pCrash);
		m_pPhilla[i].SetPos(x, y);
		m_pPhilla[i].SetRenderBool(rt);
		m_pPhilla[i].SetPhyCode(2);
		m_pPhilla[i].SetReal(as);
	}
	m_pSpawn->PushPhilla(m_pPhilla, maxum);
	fp.close();

	fp.open(FIRE + mapName + ".mdatFi");
	fp >> x >> y;
	m_pSpawn->SetFirePhilla(x, y);
	fp.close();

	fp.open(WIND + mapName + ".mdatW");
	fp >> maxum;
	for (int i = 0; i < maxum; ++i){
		fp >> windPoint.x >> windPoint.y >> direction;
		WindMgr->SetWindPlace(windPoint, direction);
	}
	fp.close();

		
}
