#include "Ocean.h"



Ocean::Ocean()
{
}


Ocean::~Ocean()
{
}



bool Ocean::OceanCheck(int x) {
	for (iter = oceanlist.begin(); iter != oceanlist.end(); ++iter){
		if (x >= iter->x || x <= iter->y) return true;
		else return false;
	}
}