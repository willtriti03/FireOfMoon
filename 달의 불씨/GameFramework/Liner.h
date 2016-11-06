#pragma once
#include"ISceneNode.h"
#include"Application.h"
#include "SpriteManager.h"
class Liner : public ISceneNode
{
private:
public:
	ID3DXLine *liner;
	D3DXVECTOR2 *list;

	IDirect3DVertexBuffer9* VertexBuffer;
	
	int max;

	void Draw(D3DXVECTOR2 *list,int max);
	void Draw3DLine(D3DXVECTOR2 * list, int max);

	void SetWid(int a);

	void Update(float eTime);
	void Render();
	Liner();
	~Liner();
};

