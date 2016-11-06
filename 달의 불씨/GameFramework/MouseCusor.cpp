#include "MouseCusor.h"
#include "InputManager.h"
MouseCusor::MouseCusor(){
	m_pCusor = new Sprite("");
	PushScene(m_pCusor, false);



};
MouseCusor::~MouseCusor(){};
void MouseCusor::Update(float eTime){
	ISceneNode::Update(eTime);

	m_pCusor->Update(eTime);

	InputMgr->GetMouseCusor(x, y);
	m_pCusor->SetPosition(D3DXVECTOR2(x, y));
}
void MouseCusor::Render(){
	m_pCusor->Render();
}
