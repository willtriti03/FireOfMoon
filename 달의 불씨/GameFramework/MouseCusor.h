#ifndef _MOUSECUSOR_H_
#define _MOUSECUSOR_H_

#include "ISceneNode.h"
#include "Application.h"
#include "Sprite.h"
class MouseCusor: public ISceneNode{
public:
	Sprite		*m_pCusor;
	POINT	    currentMousePoint;
	MouseCusor();
	~MouseCusor();
	int x, y;
	void Update(float eTime);
	void Render();


};
#endif