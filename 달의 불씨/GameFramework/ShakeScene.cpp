#include "ShakeScene.h"
#include <time.h>


ShakeScene::ShakeScene()
{
	limit = 0.1 + TimeMgr->GetTime();
	m_pBackground = new Sprite("resource/shakeimage/skimg.png");
	srand((unsigned)time(NULL));
}


ShakeScene::~ShakeScene()
{
}

void ShakeScene::Update(float eTime) {

	ISceneNode::Update(eTime);
	m_pBackground->Update(eTime);
	TimeMgr->Update(eTime);
	if (limit < TimeMgr->GetTime()&& n<60) {
		//m_pBackground->SetPosition(0, pow(-1 * (15 / (n + 1.5)), n));
		float rd = rand()%(40-(n-20));
		float rd2 = rand() % (20);
		m_pBackground->SetPosition(D3DXVECTOR2(rd2,rd));
		limit = TimeMgr->GetTime() + 0.03;
		n++;
	}
	else{
		m_pBackground->SetPosition(D3DXVECTOR2(0, 0));

	}

}

void ShakeScene::Render() {
	ISceneNode::Render();
	m_pBackground->Render();
}