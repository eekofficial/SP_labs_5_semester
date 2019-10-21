// Lab3_SP_Korotaev.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab3_SP_Korotaev.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
LPCWSTR APP_1 = LPCWSTR(TEXT("Lab2_SP_Korotaev"));
LPCWSTR APP_2 = LPCWSTR(TEXT("App_2"));
LPCWSTR APP_3 = LPCWSTR(TEXT("App_3"));
HWND hButton1;
HWND hButton2;
HWND hButton3;
HWND hButton4;
HWND hButton5;
HWND hButton6;
HWND hButton9;
BOOL FL = false;

INT WINDOW_COUNT = 0;
INT CHILD_WINDOW_COUNT = 0;

const INT id_button1 = 150;
const INT id_button2 = 151;
const INT id_button3 = 152;
const INT id_button4 = 153;
const INT id_button5 = 154;
const INT id_button6 = 155;
const INT id_button9 = 158;


// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_LAB3SPKOROTAEV, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB3SPKOROTAEV));

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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB3SPKOROTAEV));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB3SPKOROTAEV);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   hButton1 = CreateWindow(TEXT("button"), TEXT("Свернуть APP_1"), WS_CHILD | WS_VISIBLE, 100, 100, 200, 100, hWnd, HMENU(id_button1), hInstance, 0);
   hButton2 = CreateWindow(TEXT("button"), TEXT("Сделать недоступным APP_2"), WS_CHILD | WS_VISIBLE, 100, 300, 200, 100, hWnd, HMENU(id_button2), hInstance, 0);
   hButton3 = CreateWindow(TEXT("button"), TEXT("Закрыть APP_3"), WS_CHILD | WS_VISIBLE, 100, 500, 200, 100, hWnd, HMENU(id_button3), hInstance, 0);
   hButton4 = CreateWindow(TEXT("button"), TEXT("Пронумеровать все окна"), WS_CHILD | WS_VISIBLE, 400, 100, 200, 100, hWnd, HMENU(id_button4), hInstance, 0);
   hButton5 = CreateWindow(TEXT("button"), TEXT("Нажать Button3 в APP_1"), WS_CHILD | WS_VISIBLE, 400, 300, 200, 100, hWnd, HMENU(id_button5), hInstance, 0);
   hButton6 = CreateWindow(TEXT("button"), TEXT("Нажать пункт меню в APP_1"), WS_CHILD | WS_VISIBLE, 400, 500, 200, 100, hWnd, HMENU(id_button6), hInstance, 0);
   hButton9 = CreateWindow(TEXT("button"), TEXT("Переименовать доч. окна"), WS_CHILD | WS_VISIBLE, 700, 100, 200, 100, hWnd, HMENU(id_button9), hInstance, 0);
  

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

BOOL CALLBACK EnumCC(HWND hWnd, LPARAM lParam) {
	CHILD_WINDOW_COUNT++;
	TCHAR str[50] = TEXT("Дочернее");
	TCHAR str1[10];
	_itot_s(CHILD_WINDOW_COUNT, str1, 10);
	_tcscat_s(str, TEXT(" "));
	_tcscat_s(str, str1);
	SendMessage(hWnd, WM_SETTEXT, 0, LPARAM(str));
	return true;
}

BOOL CALLBACK EnumWW(HWND hWnd, LPARAM lParam) {
	WINDOW_COUNT++;
	CHILD_WINDOW_COUNT = 0;
	TCHAR str[50] = TEXT("Окно");
	TCHAR str1[10];
	_itot_s(WINDOW_COUNT, str1, 10);
	_tcscat_s(str, TEXT(" "));
	_tcscat_s(str, str1);
	SendMessage(hWnd, WM_SETTEXT, 0, LPARAM(str));
	EnumChildWindows(hWnd, &EnumCC, 0);
	return true;
}

BOOL CALLBACK EnumCS(HWND hWnd, LPARAM lParam) {
	SendMessage(hWnd, WM_SETTEXT, 0, LPARAM(TEXT("APP_1 CHILD")));
	return true;
}

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
				HWND hWnd1 = FindWindow(0, APP_1);
				if (hWnd1 != 0) {
					if (IsWindowVisible(hWnd1))
						ShowWindow(hWnd1, SW_MINIMIZE);
				}
			}
			break;
			case id_button2:
			{
				HWND hWnd2 = FindWindow(0, APP_2);
				if (hWnd2 != 0) {
					EnableWindow(hWnd2, FALSE);
				}
			}
			break;
			case id_button3:
			{
				HWND hWnd3 = FindWindow(0, APP_3);
				if (hWnd3 != 0) {
					SendMessage(hWnd3, WM_CLOSE, 0, 0);
				}
			}
			break;
			case id_button4:
			{
				EnumWindows(&EnumWW, 0);
			}
			break;
			case id_button5:
			{
				HWND hWnd1 = FindWindow(0, APP_1);
				if (hWnd1 != 0) {
					HWND hButton3 = FindWindowEx(hWnd1, NULL, TEXT("button"), TEXT("Button3"));
					SendMessage(hButton3, WM_LBUTTONDOWN, 0, 0);
					SendMessage(hButton3, WM_LBUTTONUP, 0, 0);
				}
			}
			break;
			case id_button6:
			{
				HWND hWnd1 = FindWindow(0, APP_1);
				if (hWnd1 != 0) {
					SendMessage(hWnd1, WM_COMMAND, IDM_ABOUT, 0);
				}
			}
			break;
			case id_button9:
			{
				HWND hWnd1 = FindWindow(0, APP_1);
				if (hWnd1 != 0) {
					EnumChildWindows(hWnd1, &EnumCS, 0);
				}
			}
			break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_MOUSEMOVE:
	{
		int wmId = LOWORD(wParam);
		switch (wmId) {
		case MK_LBUTTON:
		{
			SetCapture(hWnd);
			HWND hWnd1 = FindWindow(0, APP_1);
			SendMessage(hWnd1, WM_MOUSEMOVE, wParam, lParam);
			SendMessage(hWnd1, WM_LBUTTONDOWN, wParam, lParam);
		}
		break;
		default:
			ReleaseCapture();
			break;
		}
	}
	break;
	case WM_LBUTTONDOWN:
	{
		HWND hWnd1 = FindWindow(0, APP_1);
		if (hWnd1 != 0) {
			SetCapture(hWnd);
			SendMessage(hWnd1, WM_LBUTTONDOWN, wParam, lParam);
		}
	}
	break;
	case WM_RBUTTONDOWN:
	{
		HWND hWnd1 = FindWindow(0, APP_1);
		if (hWnd1 != 0) {
			SendMessage(hWnd1, WM_RBUTTONDOWN, wParam, lParam);
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


