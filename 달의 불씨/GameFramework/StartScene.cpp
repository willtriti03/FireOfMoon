#include "StartScene.h"
#include <direct.h>
#include <iostream>
#include "DirectionA.h"
StartScene::StartScene()
{
	m_pBgm = new CSound("resource/Sound/bgm1.wav", true);
	m_pBgm->Play();

	m_pBackground = new Sprite("resource/UI/illust.png");
	m_pTitle = new Sprite("resource/UI/title.png");
	m_pTitle->SetPosition(465, 120);
	m_pStartBtn = new GUIButton();
	m_pStartBtn->AddOnButtonImage("resource/UI/gamestart_button_2.png");
	m_pStartBtn->AddUsualButtonImage("resource/UI/gamestart_button_1.png");
	m_pStartBtn->AddOverImage("resource/UI/gamestart_button_2.png");
	m_pStartBtn->SetPosition(800, 470);

	m_pCreditBtn = new GUIButton();
	m_pCreditBtn->AddOnButtonImage("resource/UI/credit_button_2.png");
	m_pCreditBtn->AddUsualButtonImage("resource/UI/credit_button_1.png");
	m_pCreditBtn->AddOverImage("resource/UI/credit_button_2.png");
	m_pCreditBtn->SetPosition(800, 540);


	m_pExitBtn = new GUIButton();
	m_pExitBtn->AddOnButtonImage("resource/UI/gamefinish_button_2.png");
	m_pExitBtn->AddUsualButtonImage("resource/UI/gamefinish_button_1.png");
	m_pExitBtn->AddOverImage("resource/UI/gamefinish_button_2.png");
	m_pExitBtn->SetPosition(800, 610);
	InstallFont();
}


StartScene::~StartScene()
{
}

void StartScene::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pBackground->Update(eTime);
	m_pTitle->Update(eTime);
	m_pStartBtn->Update(eTime);
	m_pCreditBtn->Update(eTime);
	m_pExitBtn->Update(eTime);
	if (m_pStartBtn->OnMouseClicked()) {
		SceneMgr->changeScene(new DirectionA);
	}
	else if (m_pCreditBtn->OnMouseClicked()) {
		SceneMgr->changeScene(new Credit);
	}

	else if (m_pExitBtn->OnMouseClicked()){
		PostQuitMessage(0);
	}

}

void StartScene::Render() {
	ISceneNode::Render();
	m_pBackground->Render();
	m_pTitle->Render();
	m_pStartBtn->Render();
	m_pCreditBtn->Render();
	m_pExitBtn->Render();
}

void StartScene::InstallFont() {
	char arr[MAX_PATH];
	string happy = "";
	happy = getcwd(arr, MAX_PATH);
	happy = "cd " + happy;
	const char *cstr = happy.c_str();
	cout << happy << "\n" << cstr;
	//system(cstr);
}