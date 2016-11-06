
#include "InputManager.h"
#include "GUIButton.h"

InputManager::InputManager() {
	for (int i = 0; i < 256; ++i) {
		rkey[i] = lkey[i] = false;
	}

}

InputManager::~InputManager() {}

void InputManager::Update() {
	for (int i = 0; i < 256; ++i) {
		rkey[i] = lkey[i];
		lkey[i] = GetKeyState(i) & 0x8000;
	}
}

int InputManager::keyState(unsigned int key) {
	if (rkey[key] == true && lkey[key] == false) {

		return 2;
	}
	else if (rkey[key] == true && lkey[key] == true){
		return 3;
	}
	else if (rkey[key] == false && lkey[key] == true){
		return 4;
	}

}

void InputManager::GetMouseCusor(int &x,int &y){
	GetCursorPos(&currentMousePoint);
	ScreenToClient(GameApp->GetHWND(), &currentMousePoint);

	x = currentMousePoint.x;
	y = currentMousePoint.y;

}

InputManager* InputManager::GetInstance() {
	static InputManager Instance;
	return &Instance;
}