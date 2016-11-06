
#include "Font.h"

Font::Font(int bufferSize, UINT size, char* fontname)
{
	string = new char[bufferSize];
	this->fontname = fontname;
	D3DXCreateFontA(GameApp->GetInstance()->GetDevice(), size, size / 2 - size / 10, FW_HEAVY, D3DX_DEFAULT, NULL, DEFAULT_CHARSET, OUT_TT_PRECIS, CLEARTYPE_QUALITY, NULL, fontname, &font);
	color = D3DCOLOR_ARGB(255, 0, 0, 0);
}
Font::~Font()
{
	//delete( font );
	delete[] string;
}

void Font::Render()
{
	ISceneNode::Render();

	SpriteMgr->Sprite()->SetTransform(&GetMatrix());
	SpriteMgr->Sprite()->Begin(D3DXSPRITE_ALPHABLEND);
	font->DrawTextA(SpriteMgr->Sprite(), string, len, NULL, DT_TOP | DT_LEFT | DT_NOCLIP, color);
	SpriteMgr->Sprite()->End();
}
void Font::Update(float eTime)
{
	ISceneNode::Update(eTime);
}

void Font::SetText(LPCSTR fmt, ...)
{
	char	buff[1024] = { 0, };

	vsprintf(buff, fmt, (char*)(&fmt + 1));

	strcpy(string, buff);
}
void Font::SetString(char string[], bool autosize)
{
	strcpy_s(this->string, strlen(string) + 1, string);
	if (autosize)
	{
		len = strlen(this->string);
	}
}
void Font::SetString(std::string string, bool autosize)
{
	strcpy_s(this->string, string.length() + 1, string.c_str());
	if (autosize)
	{
		len = strlen(this->string);
	}
}