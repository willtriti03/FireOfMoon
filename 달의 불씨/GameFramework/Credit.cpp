#include "Credit.h"



Credit::Credit()
{
	m_pCredit = new Sprite("resource/UI/credit_name.png");
	SetBGMiddle(m_pCredit);
	m_pBackground = new Sprite("resource/UI/illust.png");
	m_pOpacity = new Sprite("resource/UI/opa80.png");
}


Credit::~Credit()
{
}

void Credit::Update(float eTime) {
	m_pBackground->Update(eTime);
	m_pOpacity->Update(eTime);
	m_pCredit->Update(eTime);

	if (InputMgr->keyState(27) == 4) {
		SceneMgr->changeScene(new StartScene);
	}
}

void Credit::Render() {
	m_pBackground->Render();
	m_pOpacity->Render();
	m_pCredit->Render();
}

void Credit::SetBGMiddle(Sprite *m_pBackground) {
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