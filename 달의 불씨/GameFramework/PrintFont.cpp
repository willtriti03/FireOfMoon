#include "PrintFont.h"
#include "MainScene.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Timer.h"
PrintFont::PrintFont()
{

	int i = 0;

	ifstream fin("resource/font.txt");
	fin >> max;
	stList = new string[max];
	string token;
	string pattern = "|";
	string::size_type pos = 0;
	while (fin >> token) {
		stList[i] = token;

		while ((pos = stList[i].find(pattern)) != std::string::npos)
		{
			stList[i].replace(pos, pattern.size(), " ");
		}
		i++;
	}
	m_pmyFont = new Font(400, fontSize);
	m_pmyFont->SetString("");
	m_pmyFont->SetPosition(0, 650);
	m_pmyFont->SetColor(D3DXCOLOR(255, 255, 255, 255));
	//eback = (eback / 2 - eback / 10)*d;


	SetTime(100);
	Stop();
}


PrintFont::~PrintFont()
{
}

void PrintFont::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pmyFont->Update(eTime);
	TimeMgr->Update(eTime);
	if (playstop&&TimeMgr->GetTime() > timer){
		if (to_cnt<len){
			if (stList[stringNum].at(to_cnt) < 0) {
				tmp += stList[stringNum].substr(to_cnt, 2).c_str();
				to_cnt += 2;
			}
			else{
				tmp += stList[stringNum].c_str()[to_cnt];
				to_cnt++;
			}
		
			if (to_cnt < len){
				timer += 0.08;
			}
			else
				timer += 1;
			m_pmyFont->SetString(tmp);
		}
		else{
			Stop();
		}
		
	}
	

}

void PrintFont::Render() {
	ISceneNode::Render();
	m_pmyFont->Render();
}

void PrintFont::SetMiddle(int fontsize, string str) {
	int strsize;
	int positionX;
	strsize = strlen(str.c_str());
	fontsize = (fontsize / 2 - fontsize / 10)*strsize;
	positionX = (1024 - fontsize) / 2;
	m_pmyFont->SetPosition(D3DXVECTOR2(positionX, m_pmyFont->GetPosition().y));
}

void PrintFont::SetTime(float timer) {
	PrintFont::timer = 0.1 + TimeMgr->GetTime();
}

void PrintFont::Stop() {
	playstop = false;
	m_pmyFont->SetString("");
}

void PrintFont::Play(int stringNum) {
	if (!playstop){
		playstop = true;
		PrintFont::stringNum = stringNum;
		SetMiddle(fontSize, stList[stringNum]);
		to_cnt = 0;
		len = strlen(stList[stringNum].c_str());
		tmp = "";
		timer = 0.1 + TimeMgr->GetTime();
	}
}

void PrintFont::Typing(string stList) {
}
