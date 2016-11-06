#include "SpawnManager.h"
#include "Light.h"

#define TOUCH	"resource\\mapdata\\mapTouch\\"
SpawnManager::SpawnManager()
{

	
}


SpawnManager::~SpawnManager()
{
}

void SpawnManager::Update(float eTime){
	ISceneNode::Update(eTime);
	list<RenderTouch>::iterator iter;
	for (iter = m_lTouch.begin(); iter != m_lTouch.end(); iter++){
		if ((iter->renderBool) == true)
			iter->m_pTouch->Update(eTime);
	}
	list<RenderNpc>::iterator iter2;
	for (iter2 = m_lNpc.begin(); iter2 != m_lNpc.end(); iter2++){
		if ((iter2->renderBool) == true)
			iter2->m_pNpc->Update(eTime);
	}
	list<RenderFan>::iterator iter3;
	for (iter3 = m_lFan.begin(); iter3 != m_lFan.end(); iter3++){
		if ((iter3->renderBool) == true)
			iter3->m_pFan->Update(eTime);
	}
	list<RenderStick>::iterator iter4;
	for (iter4 = m_lStick.begin(); iter4 != m_lStick.end(); iter4++){
		if ((iter4->renderBool) == true){
			iter4->m_pStick->Update(eTime);
		}
	}
	list < RenderPhilla > ::iterator iter5;
	for (iter5 = m_lPhilla.begin(); iter5 != m_lPhilla.end(); iter5++){
		if ((iter5->renderBool) == true)
			iter5->m_pPhilla->Update(eTime);

	}

}

void SpawnManager::Render(){
	ISceneNode::Render();
	list<RenderTouch>::iterator iter;
	for (iter = m_lTouch.begin(); iter != m_lTouch.end(); iter++){
		if ((iter->renderBool) == true)
			iter->m_pTouch->Render();
	}
	list<RenderNpc>::iterator iter2;
	for (iter2 = m_lNpc.begin(); iter2 != m_lNpc.end(); iter2++){
		if ((iter2->renderBool) == true)
			iter2->m_pNpc->Render();
	}
	list<RenderFan>::iterator iter3;
	for (iter3 = m_lFan.begin(); iter3 != m_lFan.end(); iter3++){
		if ((iter3->renderBool) == true)
			iter3->m_pFan->Render();
	}
	list<RenderStick>::iterator iter4;
	for (iter4 = m_lStick.begin(); iter4 != m_lStick.end(); iter4++){
		if ((iter4->renderBool) == true)
			iter4->m_pStick->Render();
	}
	list < RenderPhilla > ::iterator iter5;
	for (iter5 = m_lPhilla.begin(); iter5 != m_lPhilla.end(); iter5++){
		if ((iter5->renderBool) == true)
			iter5->m_pPhilla->Render();
	}
}

void SpawnManager::PushTouch(Touch *touch,int max){
	struct RenderTouch rt;
	for (int i = 0; i < max; ++i){
		rt.m_pTouch = touch[i].GetTouch();
		rt.renderBool = touch[i].GetRenderBool();

		m_lTouch.push_back(rt);
	}
}

void SpawnManager::PushFan(Fan *fan,int max){
	struct RenderFan ft;
	for (int i = 0; i < max; ++i){
		ft.m_pFan = fan[i].GetInstance();
		ft.renderBool = fan[i].GetRenderBool();

		m_lFan.push_back(ft);
	}
}
void SpawnManager::PushStick(Stick *stick,int max){
	struct RenderStick st;
	for (int i = 0; i < max; ++i){
		st.m_pStick = stick[i].GetInstance();
		st.renderBool = stick[i].GetRenderBool();

		m_lStick.push_back(st);
	}
}
void SpawnManager::PushPhilla(Philla *philla, int max){
	struct RenderPhilla rp;
	for (int i = 0; i < max; ++i){
		rp.m_pPhilla = philla[i].GetInstance();
		rp.renderBool = philla[i].GetRenderBool();
		m_lPhilla.push_back(rp);
	}
}

void SpawnManager::PushNpc(Npc *npc, int max){
	struct RenderNpc rp;
	for (int i = 0; i < max; ++i){
		rp.m_pNpc = npc[i].GetInstance();
		rp.renderBool = npc[i].GetRenderBool();
		m_lNpc.push_back(rp);
	}
}
bool SpawnManager::ChageBool(Physical *phy, bool boolean){
	int address= phy->GetAddress();
	list<RenderTouch>::iterator iter;
	for (iter = m_lTouch.begin(); iter != m_lTouch.end(); iter++){
		if ((int)iter->m_pTouch == address){
			iter->renderBool = boolean;
			iter->m_pTouch->SetRenderBool(boolean);
			return true;
		}
	}
	list<RenderNpc>::iterator iter2;
	for (iter2 = m_lNpc.begin(); iter2 != m_lNpc.end(); iter2++){
		if ((int)iter2->m_pNpc == address){
			iter2->renderBool = boolean;
			iter2->m_pNpc->SetRenderBool(boolean);
			return true;
		}
	}
	list<RenderFan>::iterator iter3;
	for (iter3 = m_lFan.begin(); iter3 != m_lFan.end(); iter3++){
		if ((int)iter3->m_pFan == address){
			iter3->renderBool = boolean;
			iter3->m_pFan->SetRenderBool(boolean);
			return true;
		}
	}
	list<RenderStick>::iterator iter4;
	for (iter4 = m_lStick.begin(); iter4 != m_lStick.end(); iter4++){
		if ((int)iter4->m_pStick == address){
			iter4->renderBool = boolean;
			iter4->m_pStick->SetRenderBool(boolean);
			return true;
		}
	}
	list < RenderPhilla > ::iterator iter5;
	for (iter5 = m_lPhilla.begin(); iter5 != m_lPhilla.end(); iter5++){
		if ((int)iter5->m_pPhilla == address){
			iter5->renderBool = boolean;
			iter5->m_pPhilla->SetRenderBool(boolean);
			return true;
		}
	}
}
void SpawnManager::FflushList(){
	m_lTouch.clear();
	m_lFan.clear();
	m_lPhilla.clear();
	m_lStick.clear();
}

void SpawnManager::SetFirePhilla(int x,int y){
	list < RenderPhilla > ::iterator iter5;
	for (iter5 = m_lPhilla.begin(); iter5 != m_lPhilla.end(); iter5++){
		if ((iter5->m_pPhilla->GetPhillaPosition() == D3DXVECTOR2(x, y))){
			m_pFirePhllia = iter5->m_pPhilla;
			m_pFirePhllia->SetFire(true);
			m_pFirePhllia->GetFire(FireMgr);
			
		}
	}
}
void SpawnManager::SetFirePhilla(D3DXVECTOR2 point){
	list < RenderPhilla > ::iterator iter5;
	for (iter5 = m_lPhilla.begin(); iter5 != m_lPhilla.end(); iter5++){
		if ((iter5->m_pPhilla->GetPhillaPosition() == point)){
			m_pFirePhllia = iter5->m_pPhilla;
			m_pFirePhllia->SetFire(true);

		}
	}
}
void SpawnManager::MoveMap(int move){
	list<RenderTouch>::iterator iter;
	for (iter = m_lTouch.begin(); iter != m_lTouch.end(); iter++){
		iter->m_pTouch->SetSunPosition(-1 * move, 0);
	}
	list<RenderNpc>::iterator iter2;
	for (iter2 = m_lNpc.begin(); iter2 != m_lNpc.end(); iter2++){
		iter2->m_pNpc->SetSunPosition(-1 * move, 0);
	}
	list<RenderFan>::iterator iter3;
	for (iter3 = m_lFan.begin(); iter3 != m_lFan.end(); iter3++){
		iter3->m_pFan->SetSunPosition(-1 * move, 0);
	}
	list<RenderStick>::iterator iter4;
	for (iter4 = m_lStick.begin(); iter4 != m_lStick.end(); iter4++){
		iter4->m_pStick->SetSunPosition(-1 * move, 0);
	}
	list < RenderPhilla > ::iterator iter5;
	for (iter5 = m_lPhilla.begin(); iter5 != m_lPhilla.end(); iter5++){
		iter5->m_pPhilla->SetSunPosition(-1 * move, 0);
	}
	if (m_pLight->GetPhillaBool())
		m_pLight->SetLightPosition(-1 * move, 0);
}
void SpawnManager::SwitchPoint(D3DXVECTOR2 pos){
	list<RenderTouch>::iterator iter;
	for (iter = m_lTouch.begin(); iter != m_lTouch.end(); iter++){
		iter->m_pTouch->SetPos(pos.x,pos.y);
		iter->m_pTouch->SetRenderBool(true);
		iter->renderBool = true;
	}
}


void SpawnManager::CommitGlove(string stage){
	string path="";
	if (stage.compare("third") == 0){
		path = "fourth";
	}
	else if (stage.compare("fourth") == 0){
		path = "five";
	}
	else if (stage.compare("five") == 0){
		path = "six";
	}
	else if (stage.compare("six") == 0){
		path = "seven";
	}
	else if (stage.compare("seven") == 0){
		path = "eight";
	}
	else if (stage.compare("eight") == 0){
		path = "nine";
	}
	if (path.compare("")!=0){
		ofstream fp(TOUCH + path + ".mdatT");
		list<RenderTouch>::iterator iter;
		fp << "1"<<"\n";
		for (iter = m_lTouch.begin(); iter != m_lTouch.end(); iter++){
			fp << iter->m_pTouch->GetSunPosition().x << " " << iter->m_pTouch->GetSunPosition().y <<" 1\n";
		}
	}

}
void SpawnManager::CommitShakes(D3DXVECTOR2 mapPos, D3DXVECTOR2 charPos){
	ofstream fp("resource/Location/location.txt");
	fp << (int)mapPos.x << " " << (int)mapPos.y << "\n";
	list < RenderPhilla > ::iterator iter5;
	for (iter5 = m_lPhilla.begin(); iter5 != m_lPhilla.end(); iter5++){
		if (iter5->m_pPhilla->GetFireBool()){
			fp << (int)iter5->m_pPhilla->GetSunPosition().x << " " << (int)iter5->m_pPhilla->GetSunPosition().y << "\n";

		}
	}
	fp << (int)charPos.x << " " << (int)charPos.y << "\n";
	fp.close();
}


SpawnManager* SpawnManager::GetInstance() {
	static SpawnManager Instance;
	return &Instance;
}

void SpawnManager::InstanceReset(){

}