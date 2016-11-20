#pragma once
#include "Application.h"
#include <list>
#define OceanMgr Ocean::GetInstance()
using namespace std;
class Ocean
{
private:
	list <D3DXVECTOR2> oceanlist;
	list<D3DXVECTOR2>::iterator iter;

public:
	Ocean();
	~Ocean();

	void FFlush(){ oceanlist.clear(); };
	void SetOcean(int x1, int x2){ oceanlist.push_back(D3DXVECTOR2(x1, x2)); };
	
	bool OceanCheck(int x);

	static Ocean* GetInstance(){ static Ocean Instance; return &Instance; };

};
