#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "ISceneNode.h"

#define SceneMgr SceneManager::getInstance()

class SceneManager {
	ISceneNode* m_pNowScene; //현재 GameScene의 포인터

private:
	SceneManager();

public:
	virtual ~SceneManager();

	static SceneManager* getInstance() {
		static SceneManager Instance;
		return &Instance;
	}

	void changeScene(ISceneNode* p, bool erase = true);
	void update(float eTime);
	void Render();
	void releaseScene();
};

#endif