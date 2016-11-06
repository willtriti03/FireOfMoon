#include "GUIButton.h"
#include "Application.h"
#include "InputManager.h"

GUIButton::GUIButton() {
	/*Image[0] = new Sprite();
	Image[0]->Create("resource/deck_btn.png");
	pushScene(Image[0], false);

	Image[1] = new Sprite();
	Image[1]->Create("resource/clicked.png");
	pushScene(Image[1], false);*/
	Image[0] = Image[1] = Image[2] = nullptr;
	GetCursorPos(&currentMousePoint);

	btn_state = 0;
}
GUIButton::~GUIButton() {
}
void GUIButton::AddUsualButtonImage(std::string path) {
	if (Image[0]) PopScene(Image[0], true);   //이전 버튼의 이미지는 지움
	Image[0] = new Sprite(path);            //다시 새로 스프라이트 할당            //이미지 생성
	PushScene(Image[0], false);
	AddOverImage(path);
	updateCollision();
}
void GUIButton::AddOnButtonImage(std::string path) {
	if (Image[1]) PopScene(Image[1], true);   //이전 버튼의 이미지는 지움
	Image[1] = new Sprite(path);            //다시 새로 스프라이트 할당
	//이미지 생성
	PushScene(Image[1], false);
}

void GUIButton::AddOverImage(std::string path) {
	if (Image[2]) PopScene(Image[2], true);
	Image[2] = new Sprite(path);

	PushScene(Image[2], false);
}



void GUIButton::Update(float eTime) {
	ISceneNode::Update(eTime);
	static float currentTime = 0.f;
	//버튼의 충돌영역을 업데이트해줌
	updateCollision();
	if (OnMouseEnter()) {         //마우스가 버튼위에 올라왔다면
		btn_state = 1;   //버튼의 상태를 1 : (마우스가 올라옴) 상태로 지정

	}
	else {                     //아니라면
		btn_state = 0;            //버튼의 상태를 0 : (보통) 상태로 지정
	}
}
void GUIButton::Render() {
	ISceneNode::Render();

	if (OnReleased()) {

		Image[1]->SetPosition((Image[0]->GetRect().right - Image[1]->GetRect().right)/2, Image[1]->GetPosition().y);
		Image[1]->Render();
	}
	else if (OnMouseEnter()) {
		Image[2]->SetPosition((Image[0]->GetRect().right - Image[2]->GetRect().right)/2, Image[2]->GetPosition().y);
		Image[2]->Render();
	}
	else Image[0]->Render();
	//현재 버튼상태에 해당하는 이미지를 렌더링함
}
void GUIButton::updateCollision() {
	collision.left = GetPosition().x;
	collision.top = GetPosition().y;
	collision.right = GetPosition().x + Image[0]->GetRect().right;
	collision.bottom = GetPosition().y + Image[0]->GetRect().bottom;
	//printf("%ld %ld %ld %ld\n", collision.left, collision.right, collision.top, collision.bottom);
}



bool GUIButton::OnMouseEnter() {

	int x, y;
	InputMgr->GetMouseCusor(x, y);
	if (x > collision.left && x < collision.right &&
		y > collision.top && y < collision.bottom) {

		return true;
	}
	return false;
}
bool GUIButton::OnMouseClicked() {
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 2) {
		return true;
	}

	return false;
}
bool GUIButton::OnReleased() {
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 3) {
		return true;
	}

	return false;
}
bool GUIButton::InClick() {
	if (!btn_state) {

		return false;
	}
	else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 4) {
		return true;
	}

	return false;
}
/*
bool GUIButton::OnDoubleClicked(){
if (!btn_state) {

return false;
}
else if (btn_state && InputMgr->keyState(VK_LBUTTON) == 4) {

return true;

}
return false;
}*/