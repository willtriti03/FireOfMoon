#include "ImageF.h"
#include "MainScene.h"

ImageF::ImageF()
{
	m_pText = new Sprite("resource/UI/dialogue_1.png");
	m_pText->SetPosition((1024 - m_pText->GetRect().right) / 2, (768 - m_pText->GetRect().bottom) / 2);
	m_pCurtain = new CurtainCall;
	time = TimeMgr->GetTime() + 2;
	time2 = time + 2;

}


ImageF::~ImageF()
{
}

void ImageF::Update(float eTime){
	ISceneNode::Update(eTime);
	m_pText->Update(eTime);
	if (rd)
		m_pCurtain->Update(eTime);
	if (time <= TimeMgr->GetTime())
		rd = false;
	else if (time2 >= TimeMgr->GetTime())
		rd = true;
	else if (time2 <= TimeMgr->GetTime())
		SceneMgr->changeScene(new MainScene("five"));
}

void ImageF::Render(){
	ISceneNode::Render();
	m_pText->Render();
	if (rd)
		m_pCurtain->Render();
}
