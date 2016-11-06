#include "PopUp.h"
#include "MainScene.h"



PopUp::PopUp()
{
	
	
	m_pContinueBtn = new GUIButton();
	m_pContinueBtn->AddOnButtonImage("resource/popup/continue.png");
	m_pContinueBtn->AddUsualButtonImage("resource/popup/continue.png");
	m_pContinueBtn->SetPosition(387, 300);

	m_pStopBtn = new GUIButton();
	m_pStopBtn->AddOnButtonImage("resource/popup/gomain.png");
	m_pStopBtn->AddUsualButtonImage("resource/popup/gomain.png");
	m_pStopBtn->SetPosition(387, 400);

	
}


PopUp::~PopUp()
{


}

void PopUp::Update(float eTime) {
	ISceneNode::Update(eTime);

	m_pContinueBtn->Update(eTime);
	if (m_pContinueBtn->OnReleased()) {
		*check = false;
	}
	m_pStopBtn->Update(eTime);
	if (m_pStopBtn->OnMouseClicked()) {
		SceneMgr->changeScene(new StartScene);
	}
	
}

void PopUp::Render() {
	ISceneNode::Render();
	m_pContinueBtn->Render();
	m_pStopBtn->Render();

}


