#ifndef _WHEEL_H_
#define _WHEEL_H_

#define WHEEL Wheel::GetInstance()
#include "ISceneNode.h"
class Wheel{
public:
	static Wheel* GetInstance() {
		static Wheel Instance;
		return &Instance;
	}
	int value=0;
	int useWhile(WPARAM wParam);
	int valueWheel();


};


#endif