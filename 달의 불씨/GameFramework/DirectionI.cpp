#include "DirectionI.h"



DirectionI::DirectionI(string path)
{
	stage = path;
	m_pCurtainCall = new CurtainCall();
	time = TimeMgr->GetTime()+1;

}


DirectionI::~DirectionI()
{
}

void DirectionI::Update(float eTime) {
	ISceneNode::Update(eTime);

	m_pCurtainCall->Update(eTime);
	TimeMgr->Update(eTime);
	if (time <= TimeMgr->GetTime()){
		FireMgr->ResetFire();
		SceneMgr->changeScene(new MainScene(stage));
	}
}

void DirectionI::Render() {
	ISceneNode::Render();
	m_pCurtainCall->Render();
}