#ifndef _MAINSCENE_H_
#define _MAINSCENE_H_

#include <string>
#include <iostream>
#include <fstream>

#include "Font.h"
#include "Wind.h"
#include "Fire.h"
#include "Liner.h"
#include "Touch.h"
#include "Light.h"
#include "Wheel.h"
#include "Timer.h"
#include "Sprite.h"
#include "Gagebar.h"
#include "Physical.h"
#include "Character.h"
#include "GUIButton.h"
#include "PrintFont.h"
#include "ISceneNode.h"
#include "Application.h"
#include "CrashManager.h"
#include "SpawnManager.h"
#include "CSound.h"

class PopUp;
class DirectionI;
class NextStageManager;
using namespace std;
class MainScene : public ISceneNode{
private:
	int				width;
	int				height;
	int				x, y;
	int				max;
	int				direction;

	float			limit;

	bool			popup = false;
	bool			updateControl=true;
	bool			rt;


	D3DXVECTOR2		*pixcelPoint;
	D3DXVECTOR2		*firePoint;
	D3DXVECTOR2		windPoint;

	Touch			*m_pTouch;
	Philla			*m_pPhilla;
	Stick			*m_pStick;
	Fan				*m_pFan;
	Npc				*m_pNpc;
	PopUp			*m_pPopUp;

	Sprite			*m_pStarMap;
	Sprite			*m_pMap;
	Character		*m_pChar;
	
	PrintFont		*m_pFonts;

	string			stage;

	CrashManager	*m_pCrash;
	SpawnManager    *m_pSpawn;
	Light			*m_pLight;
	
	DirectionI		*m_pDirect;

public:

	MainScene(string mapName);
	~MainScene();

	void			Update(float eTime);
	void			Render();

	void			CharacterMoved(int move);
	void			LoadData(string mapName);
	void			UpdateControl(float time);

};

#endif
/*


D3DXVECTOR2		*npcPoint;
D3DXVECTOR2		*phillaPoint;
D3DXVECTOR2		*stickPoint;
D3DXVECTOR2		*touchPoint;
D3DXVECTOR2		*fanPoint;
*/