#include "CenterText.h"



CenterText::CenterText()
{
	m_pBackground = new Sprite("resource/pause/popup.png");
	SetBGMiddle(m_pBackground);
}


CenterText::~CenterText()
{
}

void CenterText::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pBackground->Update(eTime);
}

void CenterText::Render() {
	ISceneNode::Render();
	m_pBackground->Render();
}

void CenterText::SetBGMiddle(Sprite *m_pBackground) {
	int width;
	int height;
	int positionX;
	int positionY;
	width = m_pBackground->GetRect().right;
	height = m_pBackground->GetRect().bottom;


	positionX = (1024 - width) / 2;
	positionY = (768 - height) / 2;
	m_pBackground->SetPosition(positionX, positionY);
}