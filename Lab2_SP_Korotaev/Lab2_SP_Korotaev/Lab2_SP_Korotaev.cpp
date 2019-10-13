// Lab2_SP_Korotaev.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab2_SP_Korotaev.h"
#include <iostream>
#include <string>
using namespace std;

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];  // имя класса главного окна
HWND hWnd;
HWND hButton1;
HWND hButton2;
HWND hButton3;
HWND hEdit;
HWND hStatic;
INT COUNT_WM_NCHITTEST = 0;
TCHAR STRR[300] = TEXT("");
TCHAR STRN[300];
BOOL FL = false;
BOOL FL1 = false;
RECT rect;


const INT id_button1 = 150;
const INT id_button2 = 151;
const INT id_button3 = 154;
const INT id_edit = 152;
const INT id_static = 153;


// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void square_of_number(int& number) {
	number = number * number;
}

void GetWindowPos(HWND hWnd, int* x, int* y)
{
	HWND hWndParent = GetParent(hWnd);
	POINT p = { 0 };

	MapWindowPoints(hWnd, hWndParent, &p, 1);

	(*x) = p.x;
	(*y) = p.y;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB2SPKOROTAEV, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2SPKOROTAEV));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB2SPKOROTAEV));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB2SPKOROTAEV);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	hButton1 = CreateWindow(TEXT("button"), L"Button1", WS_CHILD | WS_VISIBLE, 100, 100, 50, 25, hWnd, HMENU(id_button1), hInstance, 0);
	hButton2 = CreateWindow(TEXT("button"), L"Button2", WS_CHILD | WS_VISIBLE, 150, 100, 50, 25, hWnd, HMENU(id_button2), hInstance, 0);
	hButton3 = CreateWindow(TEXT("button"), L"Button3", WS_CHILD | WS_VISIBLE, 200, 100, 50, 25, hWnd, HMENU(id_button3), hInstance, 0);
	hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", L"", WS_CHILD | WS_VISIBLE, 100, 50, 50, 25, hWnd, HMENU(id_edit), hInstance, 0);
	hStatic = CreateWindowEx(WS_EX_CLIENTEDGE, L"static", L"", WS_CHILD | WS_VISIBLE, 100, 250, 250, 250, hWnd, HMENU(id_static), hInstance, 0);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);


   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
    case WM_COMMAND:
		{
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case id_button1:
			{
				TCHAR str1[50];
				GetWindowText(hEdit, str1, 20);
				int i = _ttoi(str1);
				i *= i;
				_itot_s(i, str1, 10);
				SetWindowText(hStatic, str1);
			}
				break;
			case id_button2:
			{
				// CПОСОБ 1. Программное нажатие и отжатие + сообщение род окну
				SendMessage(hButton1, BM_SETSTATE, 1, 0);
				Sleep(100);
				SendMessage(hButton1, BM_SETSTATE, 0, 0);
				SendMessage(hWnd, WM_COMMAND, id_button1, 0);

				// СПОСОБ 2. Моделирование работы пользователя
				SendMessage(hButton1, WM_LBUTTONDOWN, 0, 0);
				SendMessage(hButton1, WM_LBUTTONUP, 0, 0);
			}
				break;
			case id_button3:
			{
				COUNT_WM_NCHITTEST = 0;
				FL = !FL;
				SetWindowText(hStatic, L"0");
			}
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_RBUTTONDOWN:
	{
		TCHAR xstr[50];
		TCHAR ystr[50];
		int xPos, yPos;
		xPos = (int)LOWORD(lParam);
		yPos = (int)HIWORD(lParam);
		_itot_s(xPos, xstr, 10);
		_itot_s(yPos, ystr, 10);
		_tcscat_s(xstr, L" ; ");
		_tcscat_s(xstr, ystr);
		SetWindowText(hStatic, xstr);
	}
		break;
	case WM_LBUTTONDBLCLK:
	{
		_tcscat_s(STRR, TEXT("WM_LBUTTONDBLCLK\n"));
		SetWindowText(hStatic, STRR);
		FL1 = true;
	}
		break;
	case WM_LBUTTONDOWN:
	{
		SetCapture(hWnd);
		memset(STRR, 0, sizeof STRR);
		_tcscat_s(STRR, TEXT("WM_LBUTTONDOWN\n"));
		POINT pt;
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		ClientToScreen(hWnd, &pt);
		GetWindowRect(hWnd, &rect);
		rect.left = pt.x - rect.left;
		rect.top = pt.y - rect.top;
	}
		break;
	case WM_LBUTTONUP:
	{
		_tcscat_s(STRR, TEXT("WM_LBUTTONUP\n"));
		if (FL1) {
			SetWindowText(hStatic, STRR);
		}
		FL1 = false;
		
	}
		break;
	case WM_MOUSEMOVE:
	{
		int wmId = LOWORD(wParam);
		switch (wmId) {
		case MK_LBUTTON:
		{
			SetCapture(hWnd);
			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			ClientToScreen(hWnd, &pt);
			SetWindowPos(hWnd, HWND_TOP, pt.x - rect.left, pt.y - rect.top, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
		}
		default:
			ReleaseCapture();
			break;
		}

	}
		break;
	case WM_NCHITTEST:
	{
		if (FL) {
			COUNT_WM_NCHITTEST++;
			_itot_s(COUNT_WM_NCHITTEST, STRN, 10);
			SetWindowText(hStatic, STRN);
		}
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
