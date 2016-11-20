#include "Pole.h"


Pole::Pole()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);

	m_pPole = new Sprite("resource/item/Pole/Pole.png");
}


Pole::~Pole()
{
}

void Pole::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pPole->Update(eTime);


}

void Pole::Render(){
	ISceneNode::Render();
	m_pPole->Render();
}
void Pole::SetPos(int x, int y){
	m_pPole->SetPosition(x, y);
	SetGravityObject(m_pPole);
	m_pCrash->CheckStack(this);
}