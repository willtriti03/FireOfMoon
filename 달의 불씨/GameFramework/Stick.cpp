#include "Stick.h"


Stick::Stick()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);

	m_pStrick = new Sprite("resource/item/stick/stick.png");
}


Stick::~Stick()
{
}
void Stick::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pStrick->Update(eTime);


}

void Stick::Render(){
	ISceneNode::Render();
	m_pStrick->Render();
}
void Stick::SetPos(int x, int y){
	m_pStrick->SetPosition(x, y);
	SetGravityObject(m_pStrick);
	m_pCrash->CheckStack(this);
}