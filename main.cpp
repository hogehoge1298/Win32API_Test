#define STRICT
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, int iCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;
	wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = (LPCTSTR)"Hello,World";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), NULL);

		return 1;
	}

	HWND hWnd = CreateWindow(
		(LPCTSTR)"Hello,World",
		NULL,
		WS_OVERLAPPED,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		hInst,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);

		return 1;
	}

	// The parameters to ShowWindow explained: 
	// hWnd: the value returned from CreateWindow 
	// nCmdShow: the fourth parameter from WinMain 
	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd); 

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps; HDC hdc; TCHAR greeting[] = _T("Hello, World!"); switch (message) {
	case WM_PAINT: hdc = BeginPaint(hWnd, &ps); 
		// Here your application is laid out. 
		// For this introduction, we just print out "Hello, World!" 
		// in the top left corner. 
		TextOut(hdc, 5, 5, greeting, _tcslen(greeting)); 
		// End application specific layout section. 
		EndPaint(hWnd, &ps); 
		break; 
	case WM_DESTROY: PostQuitMessage(0); 
		break; 
	default: 
			return DefWindowProc(hWnd, message, wParam, lParam); 
			break; 
	} 
	return 0; 
}