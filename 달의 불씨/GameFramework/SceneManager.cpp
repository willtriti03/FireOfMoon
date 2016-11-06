#include "SceneManager.h"

SceneManager::SceneManager() : m_pNowScene(NULL) {}
SceneManager::~SceneManager() {}
void SceneManager::changeScene(ISceneNode* p, bool erase) {
	if(erase) SAFE_DELETE(m_pNowScene);
	m_pNowScene = p;
}
void SceneManager::update(float eTime) {
	if(m_pNowScene) {
		m_pNowScene->Update(eTime);
	}
}
void SceneManager::Render() {
	if(m_pNowScene) {
		m_pNowScene->Render();
	}
}
void SceneManager::releaseScene() {
	if(m_pNowScene) {
		delete m_pNowScene;
	}
}