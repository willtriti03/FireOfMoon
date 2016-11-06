#include "Philla.h"


Philla::Philla()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);

	m_pPhilla = new Sprite("resource/item/philla/philla.png");

	SetGravityObject(m_pPhilla);
}


Philla::~Philla()
{
}
void Philla::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pPhilla->Update(eTime);
	if (fire){
		SetFirePosition();
	}
}

void Philla::Render(){
	ISceneNode::Render();
	m_pPhilla->Render();
}
void Philla::SetPos(int x, int y){
	m_pPhilla->SetPosition(x, y);
	SetGravityObject(m_pPhilla);
	m_pCrash->CheckStack(this);
}

void Philla::SetFirePosition(){
	m_pFire->SetFirePos(D3DXVECTOR2(m_pPhilla->GetPosition().x + 4 - (20 * ((FireMgr->GetFireSize() - 1))), m_pPhilla->GetPosition().y - 80-(100 * (FireMgr->GetFireSize() - 1))));
}