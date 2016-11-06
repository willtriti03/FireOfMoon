#include "Wheel.h"

int Wheel::useWhile(WPARAM wParam){
	
	value=((short)HIWORD(wParam))/120;
	return 0;
}

int Wheel::valueWheel(){
	return value;

}