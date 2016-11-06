#include "Touch.h"


Touch::Touch()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);

	m_pTouch = new Sprite("resource/item/touch/touch.png");
}


Touch::~Touch()
{
}

void Touch::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pTouch->Update(eTime);
}

void Touch::Render(){
	ISceneNode::Render();
	m_pTouch->Render();
}

void Touch::TurnOn(){
	fire = true;
}

void Touch::TurnOff(){
	fire = false;
}

void Touch::SetPos(int x, int y){
	startPos.x = x;
	startPos.y = y;
	m_pTouch->SetPosition(x, y);
	SetGravityObject(m_pTouch);
	m_pCrash->CheckStack(this);
}
