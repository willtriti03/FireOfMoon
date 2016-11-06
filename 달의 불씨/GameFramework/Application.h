#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <d3d9.h>
#include <d3dx9.h>

#define GameApp Application::GetInstance()

class Application {
//멤버변수
//멤버함수
private:

	

	int					width;
	int					height;

	float				ratioX;
	float				ratioY;

	float				aspect;

	bool				windowed;

	LPDIRECT3D9				m_pD3D; //LP는 long pointer의 약자, m_pD3D는 directx객체
	LPDIRECT3DDEVICE9	m_pd3dDevice; //direct3D device
	D3DXVECTOR3			lightPosition;
	D3DXMATRIX			lightViewMatrix;
	D3DXMATRIX			lightProjectionMatrix;

	LPD3DXSPRITE		directSprite;
	HWND	m_hWnd; //윈도우핸들
	LPCWSTR	m_pAppName;  //윈도우 이름

	int m_nWidth; //윈도우 크기
	int m_nHeight; //윈도우 크기

private:
	Application(); //클래스이름()
	float GetElapsedTime();

public:
	~Application(); //~클래스이름()

public:
	static Application* GetInstance() {
		static Application Instance;
		return &Instance;
	}
	void RegisterWindowSize(int nWidth, int nHeight);
	void InitializeApp();	//윈도우 생성, 띄우기
	HRESULT InitDirect3D(); //DirectX를 초기화해줌

public:
	void SetHWND(HWND hWnd) {m_hWnd = hWnd;}
	void SetAppName(LPCWSTR AppName) { m_pAppName = AppName; }
	
	LPCWSTR GetAppName() { return m_pAppName; }
	int GetWindowWidth() { return m_nWidth; }
	int GetWindowHeight() { return m_nHeight; }
	HWND GetHWND() { return m_hWnd; }
	LPDIRECT3DDEVICE9 GetDevice() { return m_pd3dDevice; }

	
	LPD3DXSPRITE		GetSprite();

	D3DXVECTOR3			GetLightPosition();
	void				SetLightPosition(float x, float y, float z);

	D3DXMATRIX			GetLightViewMatrix();
	D3DXMATRIX			GetLightProjectionMatrix();

	int					GetScreenWidth();
	int					GetScreenHeight();

	float				GetRatioX();
	float				GetRatioY();

	float				GetAspect();

public:
	void Update(float eTime); //게임에서 실시간으로 바뀌는 부분을 처리
	void Render(); //게임장면을 렌더링
	void Destroy(); //프로그램종료시 COM객체 할당해제

};

#endif
