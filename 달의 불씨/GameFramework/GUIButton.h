#ifndef _GUIBUTTON_H_
#define _GUIBUTTON_H_

#include "ISceneNode.h"
#include "Sprite.h"
#include <string>

class GUIButton :public ISceneNode{
private:
	Sprite* Image[3];         //버튼 이미지         0번그림 : 보통이미지, 1번그림 : 마우스 눌렸을때 이미지 2번그림 : 마우스 올라왔을때
	POINT   currentMousePoint;   //마우스의 현재 위치
	RECT   collision;         //버튼의 충돌영역

	int      btn_state = 0;         //버튼의 상태         보통 : 0, 마우스 올라옴 : 1
	bool    RenderSleep;
	bool    clickBool;
public:
	GUIButton();
	~GUIButton();

	RECT GetRect(){ return Image[0]->GetRect(); };
	void AddUsualButtonImage(std::string path);
	void AddOnButtonImage(std::string path);
	void AddOverImage(std::string path);
	bool OnMouseClicked();      //버튼이벤트 : 버튼이 마우스로 클릭되면 true, 클릭되지 않으면 false를 반환
	bool OnReleased();
	bool InClick();

	void Update(float eTime);
	void Render();

private:
	void updateCollision();      //버튼의 충돌영역을 업데이트해줌
	bool OnMouseEnter();      //마우스가 버튼위에 올라오면 true 아니면 false를 반환
};

#endif