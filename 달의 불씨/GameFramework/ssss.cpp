#include "ssss.h"
#include "MainScene.h"
#include <iostream>
#include <fstream>
#include <string>

ssss::ssss()
{

	int i = 0;
	int a = 100;
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
	m_pmyFont = new Font(400, eback);
	//eback = (eback / 2 - eback / 10)*d;
	m_pmyFont->SetString(stList[0]);
	SetMiddle(eback, stList[0]);

	SetTime(100);
}


ssss::~ssss()
{
}

void ssss::Update(float eTime) {
	ISceneNode::Update(eTime);
	m_pmyFont->Update(eTime);
	time++;

	if (time > timer&& cnt<max) {
		SetMiddle(eback, stList[cnt]);
		m_pmyFont->SetString(stList[cnt]);
		cnt++;
		time = 0;
	}
}

void ssss::Render() {
	ISceneNode::Render();
	m_pmyFont->Render();
}

void ssss::SetMiddle(int fontsize, string str) {
	int strsize;
	int positionX;
	const char * c = str.c_str();
	strsize = strlen(c);
	fontsize = (fontsize / 2 - fontsize / 10)*strsize;
	positionX = (1024 - fontsize) / 2;
	m_pmyFont->SetPosition(D3DXVECTOR2( positionX, m_pmyFont->GetPosition().y));
}

void ssss::SetTime(int timer) {
	ssss::timer = timer;
}