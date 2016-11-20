#include "Hyena.h"
#include "SpawnManager.h"

Hyena::Hyena()
{
	SetAddress((int)this);
	SetRenderBoolean(&renderBool);

	m_pHyena = new Sprite("resource/item/Hyena/Hyena.png");
}


Hyena::~Hyena()
{
}

void Hyena::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pHyena->Update(eTime);
	if (m_pCharacter != NULL){
		if (m_pCharacter->GetFireBring()){
			m_pSwapn->ChageBool(this, false);
			renderBool = false;
		}
		else{
			m_pSwapn->ChageBool(this, true);
			renderBool = true;
		}	
	}
}

void Hyena::Render(){
	ISceneNode::Render();
	m_pHyena->Render();
}

void Hyena::SetPos(int x, int y){
	m_pHyena->SetPosition(x, y);
	SetGravityObject(m_pHyena);
	m_pCrash->CheckStack(this);
}