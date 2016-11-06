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
	if (Image[0]) PopScene(Image[0], true);   //���� ��ư�� �̹����� ����
	Image[0] = new Sprite(path);            //�ٽ� ���� ��������Ʈ �Ҵ�            //�̹��� ����
	PushScene(Image[0], false);
	AddOverImage(path);
	updateCollision();
}
void GUIButton::AddOnButtonImage(std::string path) {
	if (Image[1]) PopScene(Image[1], true);   //���� ��ư�� �̹����� ����
	Image[1] = new Sprite(path);            //�ٽ� ���� ��������Ʈ �Ҵ�
	//�̹��� ����
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
	//��ư�� �浹������ ������Ʈ����
	updateCollision();
	if (OnMouseEnter()) {         //���콺�� ��ư���� �ö�Դٸ�
		btn_state = 1;   //��ư�� ���¸� 1 : (���콺�� �ö��) ���·� ����

	}
	else {                     //�ƴ϶��
		btn_state = 0;            //��ư�� ���¸� 0 : (����) ���·� ����
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
	//���� ��ư���¿� �ش��ϴ� �̹����� ��������
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