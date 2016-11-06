#include "Function.h"
#include "Application.h"
#include "Drag.h"
#include "Wheel.h"
LRESULT WINAPI MsgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) 
{
	switch(Msg) {
		case WM_DESTROY :
			GameApp->Destroy();
			PostQuitMessage(0);
			return 0;
			break;
		case WM_DROPFILES:
			Drag->DragsFile((HDROP)wParam);
			return 0;
			break;
		case WM_MOUSEWHEEL:
			WHEEL->useWhile(wParam);
			return 0;
			break;
	}
	return(DefWindowProc(hWnd, Msg, wParam, lParam));
}