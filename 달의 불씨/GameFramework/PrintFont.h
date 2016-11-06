#pragma once
#include "ISceneNode.h"
#include "Sprite.h"
#include "GUIButton.h"
#include "SceneManager.h"
#include "Font.h"
using namespace std;
class PrintFont :public ISceneNode
{
private:
	Font *m_pmyFont;
	string *stList,tmp;

	int cnt = 1;
	int max;
	int to_cnt = 0;
	int stringNum;
	int len;

	bool playstop;
	float timer = 0;
	unsigned int fontSize = 50;

	
public:
	PrintFont();
	~PrintFont();

	void Update(float eTime);
	void Render();
	void SetMiddle(int fontsize, string str);
	void SetTime(float timer);
	void SetString(int stringNum){ PrintFont::stringNum = stringNum; };
	void Stop();
	void Play(int stringNum);
	void Typing(string stList);
};