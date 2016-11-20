#include "Light.h"



Light::Light()
{
	m_pLight = new Sprite("resource/background/light.png");
	half_width = m_pLight->GetRect().right / 2;
	half_height = m_pLight->GetRect().bottom / 2;
}


Light::~Light()
{
}

void Light::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pLight->Update(eTime);

}

void Light::Render() {
	ISceneNode::Render();
	m_pLight->Render();
}

void Light::UpdateCenterPos(Fire *fire){
	int PhysicalX, PhysicalY;
	int CenterX, CenterY;

	PhysicalX = fire->GetFireCenter().x;
	PhysicalY = fire->GetFireCenter().y;

	//2000*1500

	CenterX = (PhysicalX - half_width);
	CenterY = PhysicalY - half_height;

	startPos = D3DXVECTOR2(CenterX, CenterY);
}

void Light::LightScale(float lightpower) {
	m_pLight->SetScale(D3DXVECTOR2(lightpower, lightpower));
	half_width *= lightpower;
	half_height *= lightpower;
}