#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "GUIButton.h"
#include "SceneManager.h"
#include "Font.h"
using namespace std;
class ssss :public ISceneNode
{
private:
	Font *m_pmyFont;
	string *stList;
	int time = 0;
	int cnt = 1;
	int timer = 0;
	unsigned int eback = 50;
	int max;
public:
	ssss();
	~ssss();

	void Update(float eTime);
	void Render();
	void SetMiddle(int fontsize, string str);
	void SetTime(int timer);
};
