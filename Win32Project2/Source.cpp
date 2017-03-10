#include <Windows.h>
#include "resource.h"

HWND hEdit1;
HWND hEdit2;

CHAR s_text_1[] = { "any text..." };
CHAR s_text_2[] = { 0 };

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DlgProc), 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ICOMAIN));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon1);
		
		hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
		hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);

		SendMessage(hEdit1, WM_SETTEXT, 0, (LPARAM)s_text_1);
		SetFocus(hEdit1);
		break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_COPY:
		{
			SendMessage(hEdit1, WM_GETTEXT, (WPARAM)255, (LPARAM)s_text_2);
			SendMessage(hEdit2, WM_SETTEXT, 0, (LPARAM)s_text_2);
		}
			break;
		case IDOK:
			MessageBox(hwnd, "нажата ок", "info", MB_OK | MB_ICONINFORMATION);
			break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return false;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return false;
	}
	return false;
}
