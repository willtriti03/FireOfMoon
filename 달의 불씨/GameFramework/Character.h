#pragma once

#include "ISceneNode.h"
#include "Physical.h"
#include "Sprite.h"
#include "InputManager.h"
#include "PrintFont.h"
#pragma once

#include "ISceneNode.h"
#include "Physical.h"
#include "Sprite.h"
#include "InputManager.h"
#include "PrintFont.h"
#include "Animation.h"
#include "Sprite.h"
#include "CSound.h"

class CrashManager;
class NextSceneManager;
class SpawnManager;
class Touch;
class MainScene;
class Fire;
class Light;
class Character : virtual public Physical, virtual public ISceneNode {
private:
	int            movement;
	int            max;
	int            gravityMode = 0;
	int            hand = 0;
	int            watchingView = 1;//left -1 right 1
	int            glove = 0;
	int            right;

	float         starttime;

	bool         bring = false;
	bool         stop = false;
	bool         check2 = true;
	bool       oneTime = false;
	bool         jumpcheck = false;
	bool         grcheck = false;

	Touch         *touchsaver;
	Fire         *m_pFire;
	RECT         collision;
	Physical      *phy;
	Physical      *m_pBring;
	Physical      *m_pTmp;
	Sprite         *m_pCharacter;
	MainScene      *m_pMain;
	PrintFont      *m_pFont;
	D3DXVECTOR2      startPosition;
	D3DXVECTOR2      windstate;
	Animation       *m_pAnim;
	SpawnManager   *m_pSpawn;
	Light         *m_pLight;
	CrashManager   *m_pCrash;
	CSound         *m_pWalk;
	CSound         *m_pWind;
public:
	Character(D3DXVECTOR2 *list, int max, D3DXVECTOR2 startPos, MainScene *main, SpawnManager *sm, Light *lg, CrashManager *cm);
	~Character();
	int GetMovement() { return movement; };
	int GetWatchingView() { return watchingView; };

	bool GetFireBring(){ return bring; };
	bool ItemEvent(int useCode, Physical *target);
	bool check;
	void SetWatchingView(int watch) { watchingView = watch; };
	void SetMovement(int x, int y);

	void LostGlove() { glove = 0; };
	void SetFonts(PrintFont *pf) { m_pFont = pf; };

	void FireAnimRight();
	void RunAnimRight();
	void FanAnimRight();
	void StrawAnimRight();
	void Fire_useAnimRight();


	void FireAnimLeft();
	void RunAnimLeft();
	void FanAnimLeft();
	void StrawAnimLeft();
	void Fire_useAnimLeft();

	void ImageSet();
	void RightAniSet();
	void LeftAniSet();
	void AniReset();

	void Jump();

	void Update(float eTime);
	void Render();
};
