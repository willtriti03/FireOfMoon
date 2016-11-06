#include "Wind.h"

#include<stdio.h>
Wind::Wind()
{
}


Wind::~Wind()
{
}
void Wind::SetWindPlace(D3DXVECTOR2 wind ,int direct){
	struct Wind::wind wd;
	wd.windState = wind;
	wd.direction = direct;
	
	windList.push_back(wd);

}
D3DXVECTOR2 Wind::WindZoneCheck(D3DXVECTOR2 location){
	list<wind>::iterator iter;
	for (iter = windList.begin(); iter != windList.end(); iter++){
		if (iter->windState.x <= location.x&&location.x <= iter->windState.y){
			windState = D3DXVECTOR2(1, iter->direction);
			break;
		}
		else windState = D3DXVECTOR2(0, 0);
	}
	return windState;
}