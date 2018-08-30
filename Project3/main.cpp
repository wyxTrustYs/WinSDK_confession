#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include "resource.h"

INT_PTR CALLBACK WinProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NewProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
HWND handle;
HDC hdc;
HWND MainWindow;
DWORD dwX;
DWORD dwY;
static RECT rect = { 100, 100, 20, 10 };
WNDPROC oldproc = nullptr;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, WinProc);
	return 0;
}

INT_PTR CALLBACK WinProc(HWND hwnd,
	UINT Message,
	WPARAM wParam,
	LPARAM lParam) {
	switch (Message)
	{
	case WM_INITDIALOG:
	{
  		RECT rect = { 0 };
  		handle = GetDlgItem(hwnd, Refuse);
  		MainWindow = hwnd;
  		//SetParent(handle, NULL);
  		
  		 //MoveWindow(hwnd, 100, 100, 300, 300, NULL);
  		oldproc = (WNDPROC)SetWindowLong(handle, GWL_WNDPROC, (LONG)NewProc);
		//ShowWindow(handle, SW_SHOW);
 		break;
	}
	case WM_MOUSEMOVE:
	{
//  		handle = GetDlgItem(hwnd, Confirm);
//  		
//  		SetParent(handle, NULL);
//  		//MoveWindow(hwnd, 100, 100, 500, 300, NULL);
//  		oldproc = (WNDPROC)SetWindowLong(handle, GWL_WNDPROC, (LONG)NewProc);
 		break;
	}
	case WM_COMMAND:
	{
		SHORT id = LOWORD(wParam);
		switch (id)
		{
		case Agree:
			EndDialog(hwnd, 0);
			break;
		default:
			break;
		}
		break;
	}
	case WM_CLOSE:
		//EndDialog(hwnd, 0);
		break;
	default:
		break;
	}
	return 0;
}

LRESULT CALLBACK NewProc(HWND hwnd,
	UINT Message,
	WPARAM wParam,
	LPARAM lParam) {
	switch (Message)
	{
	case WM_MOUSEMOVE:
	{
		
		//RECT rect = { 0 };
		SetParent(hwnd, NULL);
		//GetClientRect(MainWindow, &rect);
		 dwX = rand() % 1300;
		 dwY = rand() % 700;
		//能够移动窗口位置
		MoveWindow(hwnd, dwX, dwY,65, 25, true);
		ShowWindow(hwnd, 5);
		
		break;
		
	}
// 	case  WM_PAINT:
// 	{
// 		PAINTSTRUCT ps = {};
// 		hdc = BeginPaint(MainWindow, &ps);
// 		// TODO:  在此添加任意绘图代码...
// 
// 		DrawText(hdc, _T("确定"), 2, &rect, 1);
// 		EndPaint(MainWindow, &ps);
// 		MoveWindow(MainWindow, dwX, dwY, 500, 400, true);
// 	}
	}
	return oldproc(hwnd, Message, wParam, lParam);
}