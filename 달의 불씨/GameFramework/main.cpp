#include "Application.h"
#include "Console.h"
#include "SceneManager.h"
#include "MainScene.h"
#include"CSound.h"
#include "PrintFont.h"
#include "StartScene.h"


#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

Console g_Console;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	GameApp->RegisterWindowSize(1024, 768);
	GameApp->SetAppName(L"SPACE");
	GameApp->InitializeApp();
	GameApp->InitDirect3D();

	ShowWindow(GameApp->GetHWND(), SW_SHOWDEFAULT);
	UpdateWindow(GameApp->GetHWND());
	//DragAcceptFiles(GameApp->GetHWND(), true);//파일 드래그
	//ShowCursor(false);커서숨김

	//사운드 관련 초기화
	CSound::s_Init();

	//게임씬
	SceneMgr->changeScene(new StartScene);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while(msg.message != WM_QUIT) {
		if(PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			GameApp->Render();
		}
	}
	UnregisterClass(GameApp->GetAppName(), GetModuleHandle(NULL));

	
	return 0;
}