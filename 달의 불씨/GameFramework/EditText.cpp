#include "EditText.h"

EditText::EditText(){
	m_pEditText = new GUIButton();
	m_pEditText->AddOnButtonImage("resource/WhiteBlank.png");
	m_pEditText->AddUsualButtonImage("resource/WhiteBlank.png");
	m_pEditText->setScale(D3DXVECTOR2(300,100));


}
EditText::~EditText(){

}

void EditText::InputStart(){}

void EditText::update(float eTime){}

void EditText::render(){}