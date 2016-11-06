#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "ISceneNode.h"
#include <string>
using namespace std;
class Sprite : public ISceneNode {
private:

	LPDIRECT3DDEVICE9	device;
	LPD3DXSPRITE		sprite;
	LPDIRECT3DTEXTURE9	texture;

	RECT				rect;
	RECT				relativeRect;

	D3DXCOLOR			color;

	int					width;
	int					height;

	int					relativeWidth;
	int					relativeHeight;

	bool				alphaBlend;

public:

	Sprite(string path);
	~Sprite();

	void Update(float eTime);
	void Render();

public:

	RECT		GetRect()	{ return rect; }

	int			GetWidth()	{ return relativeWidth; }
	int			GetHeight() { return relativeHeight; }

	D3DXCOLOR	GetColor()	{ return color; }

public:
	D3DXVECTOR2 GetCenterPosition() {
		return D3DXVECTOR2(m_position.x + width / 2, m_position.y + height / 2);
	}

	void	SetImage(string path);

	void	SetAlphaBlending(bool alphaBlend) { this->alphaBlend = alphaBlend; }

	void	SetRect(RECT rect) { this->rect = rect; }

	void	SetColor(D3DXCOLOR color) { this->color = color; }
};

#endif


