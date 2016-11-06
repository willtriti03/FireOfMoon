#include "Application.h"
#include "Function.h"
#include "SceneManager.h"
#include "SpriteManager.h"
#include "TextureManager.h"
#include "InputManager.h"


LARGE_INTEGER LInterval;
LARGE_INTEGER RInterval;
LARGE_INTEGER Frequency;

Application::Application() :
m_pD3D(NULL), m_pd3dDevice(NULL),
m_hWnd(NULL),
m_pAppName(NULL),
m_nWidth(0), m_nHeight(0)
{
	QueryPerformanceCounter(&LInterval);
	QueryPerformanceFrequency(&Frequency);

	directSprite = 0;

	width = 0;
	height = 0;

	ratioX = GetSystemMetrics(SM_CXSCREEN) / 1920.0f;
	ratioY = GetSystemMetrics(SM_CYSCREEN) / 1080.0f;

	aspect = (float)GetSystemMetrics(SM_CXSCREEN) / GetSystemMetrics(SM_CYSCREEN);

	windowed = false;
}
Application::~Application() {}
//타입 클래스이름::함수이름(){}
void Application::RegisterWindowSize(int nWidth, int nHeight) {
	m_nWidth = nWidth;
	m_nHeight = nHeight;
}
float Application::GetElapsedTime() {
	QueryPerformanceCounter(&RInterval);
	__int64 Interval(RInterval.QuadPart - LInterval.QuadPart);

	float eTime = (double)Interval / (double)Frequency.QuadPart;

	LInterval = RInterval;

	return eTime;
}
void Application::InitializeApp() {
	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		m_pAppName, NULL };

	RegisterClassEx(&wc);

	RECT rcAdjustWindow = { 0, };
	rcAdjustWindow.right = m_nWidth;
	rcAdjustWindow.bottom = m_nHeight;
	AdjustWindowRectEx(&rcAdjustWindow, WS_OVERLAPPEDWINDOW, FALSE, 0UL);
	m_hWnd = CreateWindowEx(0UL, m_pAppName, m_pAppName,
		WS_OVERLAPPEDWINDOW, 100, 0, rcAdjustWindow.right - rcAdjustWindow.left, rcAdjustWindow.bottom - rcAdjustWindow.top,
		GetDesktopWindow(), NULL, wc.hInstance, NULL);
}
HRESULT Application::InitDirect3D() {
	D3DPRESENT_PARAMETERS d3dpp;
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferWidth = m_nWidth;
	d3dpp.BackBufferHeight = m_nHeight;
	d3dpp.BackBufferCount = 1;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice);

	SpriteMgr->Initialize();

	return S_OK;
}
void Application::Update(float eTime) {
	SceneMgr->update(eTime);
	InputMgr->Update();

}
void Application::Render() {
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET,
		D3DCOLOR_ARGB(0,0,0,0), 1.0f, 0);
	Update(GetElapsedTime());
	if (SUCCEEDED(m_pd3dDevice->BeginScene())) {
		SceneMgr->Render();
		m_pd3dDevice->EndScene();
	}
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
void Application::Destroy() {
	m_pD3D->Release();
	m_pd3dDevice->Release();
	SpriteMgr->Release();
	TextureMgr->Release();
}



LPD3DXSPRITE Application::GetSprite()
{
	return directSprite;
}


int Application::GetScreenWidth()
{
	return width;
}

int Application::GetScreenHeight()
{
	return height;
}

float Application::GetRatioX()
{
	return ratioX;
}

float Application::GetRatioY()
{
	return ratioY;
}

float Application::GetAspect()
{
	return aspect;
}

void Application::SetLightPosition(float x, float y, float z)
{
	lightPosition.x = x;
	lightPosition.y = y;
	lightPosition.z = z;

	D3DXVECTOR3 lookAt = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	D3DXMatrixLookAtLH(
		&lightViewMatrix, &lightPosition, &lookAt, &up);
}

D3DXVECTOR3 Application::GetLightPosition()
{
	return lightPosition;
}

D3DXMATRIX Application::GetLightViewMatrix()
{
	return lightViewMatrix;
}

D3DXMATRIX Application::GetLightProjectionMatrix()
{
	return lightProjectionMatrix;
}


