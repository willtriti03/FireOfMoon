#pragma once
#include "Application.h"
#include <list>
#define WindMgr Wind::GetInstance()
using namespace std;
class Wind
{
private:
	struct wind
	{
		D3DXVECTOR2 windState;
		int direction;
	};

	list<wind> windList;

	D3DXVECTOR2 windState;
	D3DXVECTOR2 windzone;
	int direction=0;
public:
	Wind();
	~Wind();
	void SetWindPlace(D3DXVECTOR2 wind, int direction);
	
	D3DXVECTOR2 WindZoneCheck(D3DXVECTOR2 location);

	D3DXVECTOR2	GetWindState(){ return windState; };
	D3DXVECTOR2	GetWindPlace(){ return windzone; };
	
	static Wind* GetInstance(){static Wind Instance; return &Instance;};


};

