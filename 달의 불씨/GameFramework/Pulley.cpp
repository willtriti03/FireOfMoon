#include "Pulley.h"

Pulley::Pulley()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);

	m_pPulley = new Sprite("resource/item/pulley/pulley.png");
}


Pulley::~Pulley()
{
}

void Pulley::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pPulley->Update(eTime);

}

void Pulley::Render(){
	ISceneNode::Render();
	m_pPulley->Render();
}

void Pulley::SetPos(int x, int y){
	m_pPulley->SetPosition(x, y);
	SetGravityObject(m_pPulley);
	m_pCrash->CheckStack(this);
}