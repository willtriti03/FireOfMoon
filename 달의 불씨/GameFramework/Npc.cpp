#include "Npc.h"


Npc::Npc()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);
	m_pNpc = new Sprite("resource/item/npc/npc.png");
	m_pAni = new Animation();
	m_pAni->Create(6,15,true);
	m_pAni->GenerateAnimation("resource/stranger/Ani");
	renderSel = true;
}


Npc::~Npc()
{
}

void Npc::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pNpc->Update(eTime);
	m_pAni->Update(eTime);
	m_pAni->SetPosition(m_pNpc->GetPosition());
}

void Npc::Render(){
	ISceneNode::Render();
	if (renderSel)
		m_pNpc->Render();
	else{
		m_pAni->Render();
	}
}
void Npc::SetPos(int x, int y){
	m_pNpc->SetPosition(x, y);
	SetGravityObject(m_pNpc);
	m_pCrash->CheckStack(this);
}