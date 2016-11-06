#include "TextBox.h"
#include "Automata.h"
#include "InputManager.h"
#include <conio.h>

TextBox::TextBox(int id, string path, float size)
{
	this->id = id;

	textBox = new Sprite(path);
	PushScene(textBox, false);

	this->size = size;

	isFocus = false;
	isReset = true;

	stringBuffer_unicode = 0;
}

TextBox::~TextBox()
{
	delete[] stringBuffer;
	delete[] stringBuffer_unicode;

	delete font;
}

void TextBox::Initialize(string caption, int limit, bool isSecure)
{
	this->caption	= caption;
	this->limit		= limit;
	this->isSecure	= isSecure;

	font = new Font(_MAX_PATH, size);

	font->SetText("%s", caption.c_str());

	area.left	= GetPosition().x;
	area.top	= GetPosition().y;
	area.right	= area.left + textBox->GetWidth();
	area.bottom = area.top + textBox->GetHeight();

	stringBuffer = new char[BUFSIZ];
	memset(stringBuffer, 0, sizeof(char)* BUFSIZ);
}


void TextBox::Write()
{
	int tempLimit = 0;

	if (!AUTOMATA->GetIsEnglish())
	{
		tempLimit = limit * 2;
	}

	else
	{
		tempLimit = limit;
	}

	unsigned short RealCode = AUTOMATA->GetConvertedUnionCode();

	if (strlen(AUTOMATA->GetStringBuffer()) <= tempLimit)
	{
		strcpy(stringBuffer, AUTOMATA->GetStringBuffer());
		if (AUTOMATA->State())
		{		
			char buff[3] = { RealCode & 0x00ff, RealCode >> 8, 0 };

			sprintf(stringBuffer, "%s%s", stringBuffer, buff);
		}
		caption = stringBuffer;
	}

	else
	{
		AUTOMATA->SetBuffer(stringBuffer);
	}

}

void TextBox::Reset(string caption)
{
	this->caption = caption;

	if (stringBuffer)
		delete[] stringBuffer;

	stringBuffer = new char[BUFSIZ];
	memset(stringBuffer, 0, sizeof(char)* BUFSIZ);

	isReset = true;
}
void TextBox::Update(float eTime)
{
	float x = 0.0f;
	float y = 0.0f;

	area.left	= GetPosition().x + x;
	area.top	= GetPosition().y + y;
	area.right	= area.left + textBox->GetWidth();
	area.bottom = area.top + textBox->GetHeight();
}

void TextBox::Render()
{
	ISceneNode::Render();

	textBox->Render();

	float x = 0.0f;
	float y = 0.0f;

	
	font->SetPosition(
		D3DXVECTOR2((int)(x + GetPosition().x +(25 * GameApp->GetRatioX() + textBox->GetHeight() / 2)),
		(int)(y + GetPosition().y + (textBox->GetHeight() / 6 - 3 * GameApp->GetRatioY()))));

	if (isFocus && stringBuffer)
	{

		if (!isSecure)
		{
			font->SetText("%s", stringBuffer);
		}

		else if (isSecure)
		{
			if (!isReset)
			{

				for (int i = 0; i < strlen(caption.c_str()); ++i)
				{
					caption.replace(i, 1, "*");
				}
			}
			font->SetText("%s", caption.c_str());
		}
	}

	else if (!isFocus)
	{
		font->SetText("%s", caption.c_str());
	}

	font->Render();
}

bool TextBox::MouseClick()
{
	if (MouseOn())
	{
		if (InputMgr->keyState(VK_LBUTTON)==2)
		{
			return true;
		}
	}
	return false;
}

bool TextBox::MouseOn()
{
	int x, y;

	InputMgr->GetMouseCusor(x, y);

	if ((x >= area.left && x <= area.right) &&
		(y >= area.top && y <= area.bottom))
	{
		return true;
	}

	return false;
}

void TextBox::SetTextBoxColor(D3DXCOLOR color)
{
	textBox->SetColor(color);
}

void TextBox::SetFontColor(D3DXCOLOR color)
{
	fontColor = color;
	font->SetColor(color);
}

void TextBox::SetFocus(bool focus) 
{
	isFocus = focus; 
}

bool TextBox::GetFocus() 
{
	return isFocus; 
}

void TextBox::SetReset(bool reset) 
{
	isReset = reset; 
}

bool TextBox::GetReset() 
{ 
	return isReset;
}

int TextBox::GetLimit() 
{ 
	return limit; 
}
int TextBox::GetId() 
{
	return id; 
}

char* TextBox::GetStringBuffer()
{
	return stringBuffer;
}

WCHAR* TextBox::GetStringBuffer_UNICODE()
{
	int size = MultiByteToWideChar(CP_ACP, 0, stringBuffer, -1, NULL, NULL);

	if (stringBuffer_unicode)
		delete[] stringBuffer_unicode;

	stringBuffer_unicode = new WCHAR[size];

	MultiByteToWideChar(CP_ACP, 0, stringBuffer, strlen(stringBuffer) + 1, stringBuffer_unicode, size);

	return stringBuffer_unicode;
}