#include "Fan.h"


Fan::Fan()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);
	m_pFan = new Sprite("resource/item/fan/openfan/open_fan.png");
}


Fan::~Fan()
{
}
void Fan::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pFan->Update(eTime);
}

void Fan::Render(){
	ISceneNode::Render();
	m_pFan->Render();
}

void Fan::SetPos(int x, int y){
	m_pFan->SetPosition(x, y);
	SetGravityObject(m_pFan);
	m_pCrash->CheckStack(this);
}