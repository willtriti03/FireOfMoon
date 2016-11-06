#include "CurtainCall.h"



CurtainCall::CurtainCall()
{
	m_pAni = new Animation();
	m_pAni->Create(10, 13,false);
	m_pAni->GenerateAnimation("resource/curtain_call");
}


CurtainCall::~CurtainCall()
{
}

void CurtainCall::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pAni->Update(eTime);
}

void CurtainCall::Render() {
	ISceneNode::Render();
	m_pAni->Render();
}