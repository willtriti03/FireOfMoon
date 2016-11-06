#ifndef _FONT_H_
#define _FONT_H_

#include "ISceneNode.h"
#include "Application.h"
#include "SpriteManager.h"
#include <string>
class Font :public ISceneNode{
private:
	LPD3DXFONT font;
public:
	char *string;
	char *fontname;
	DWORD color;
	int len;

	Font(int bufferSize, UINT size, char* fontname = "¸¼Àº °íµñ");
	~Font();

	void Render();
	void Update(float eTime);

	void SetText(LPCSTR fmt, ...);
	void SetString(char string[], bool autosize = true);
	void SetString(std::string string, bool autosize = true);
	void SetColor(D3DXCOLOR color) { this->color = color; };
};

#endif