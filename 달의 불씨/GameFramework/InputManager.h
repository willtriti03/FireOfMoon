#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#define InputMgr InputManager::GetInstance()

#include <windows.h>
#include "Application.h"
class InputManager {
private:
	POINT	    currentMousePoint;

	bool rkey[256], lkey[256];

	InputManager();

public:
	~InputManager();

	static InputManager* GetInstance();

	void Update();

	int keyState(unsigned int key);

	void GetMouseCusor(int &x, int &y);
};

#endif