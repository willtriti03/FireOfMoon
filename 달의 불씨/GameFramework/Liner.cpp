#include "Liner.h"



Liner::Liner()
{
	D3DXCreateLine((GameApp->GetInstance()->GetDevice()), &liner);
	liner->SetWidth(1);
	liner->Begin();
}


Liner::~Liner()
{
	liner->End();
}

void Liner::SetWid(int a){
	liner->SetWidth(a);
}

void Liner::Draw(D3DXVECTOR2 *list,int max){
	Liner::list = list;
	Liner::max = max;
}

void Liner::Update(float eTime) {
	ISceneNode::Update(eTime);
}

void Liner::Render(){
	ISceneNode::Render();	
	SpriteMgr->Sprite()->SetTransform(&GetMatrix());
	SpriteMgr->Sprite()->Begin(D3DXSPRITE_ALPHABLEND);
	liner->Draw(list, max, D3DCOLOR_XRGB(255, 255, 255));
	SpriteMgr->Sprite()->End();
}



