// WindowsProject2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject2.h"


#define MAX_LOADSTRING 100

// Глобальные переменные:
HWND hWnd;
HWND hButton1;
HWND hButton2;
HWND hEdit;
HWND hStatic;
INT hTimer;
HRGN FormRgn1;
HRGN FormRgn2;

const INT id_button1 = 150;
const INT id_button2 = 151;
const INT id_edit = 152;
const INT id_static = 153;

HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
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
   hButton1 = CreateWindow(TEXT("BUTTON"), L"Button1", WS_CHILD | WS_VISIBLE, 50, 50, 100, 100, hWnd, HMENU(id_button1), hInstance, NULL);
   hButton2 = CreateWindow(TEXT("BUTTON"), L"Button2", WS_CHILD | WS_VISIBLE, 200, 50, 100, 100, hWnd, HMENU(id_button2), hInstance, NULL);
   hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE, 50, 200, 200, 200, hWnd, HMENU(id_edit), hInstance, NULL);
   hStatic = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("static"), TEXT(""), WS_CHILD | WS_VISIBLE, 350, 50, 300, 100, hWnd, HMENU(id_static), hInstance, NULL);

   RECT r;
   GetWindowRect(hWnd, &r);
   FormRgn1 = CreateEllipticRgn(0, 0, r.right - r.left, r.bottom - r.top);
   FormRgn2 = CreateRectRgn(0,0, r.right - r.left, r.bottom - r.top-300);
   CombineRgn(FormRgn1, FormRgn1, FormRgn2, RGN_OR);
   FormRgn2 = CreateEllipticRgn((r.right - r.left) / 2, (r.bottom - r.top) / 2, (r.right - r.left) / 2 + 200, (r.bottom - r.top) / 2 + 200);
   CombineRgn(FormRgn1, FormRgn1, FormRgn2, RGN_XOR);
   SetWindowRgn(hWnd, FormRgn1, true);

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
				char str[100];
				GetWindowText(hEdit, LPWSTR(str), 100);
				SetWindowText(hStatic, LPWSTR(str));
				break;
			case id_button2:
				WCHAR str1[50];
				GetWindowText(hWnd, (LPWSTR)str1, 50);
				SetWindowText(hStatic, LPWSTR(str1));
				break;
			case id_menu:
				SetWindowText(hEdit, L"Нажат Новый пункт меню");
				SetParent(hButton1, NULL);
				hTimer = SetTimer(hWnd, 1, 100, 0);
				break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_TIMER:
		{
			RECT r;
			GetWindowRect(hButton1, &r);
			SetWindowPos(hButton1, HWND_TOP, r.left + 1, r.top, r.bottom - r.top, r.right - r.left, NULL);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			SetWindowText(hEdit, L"Нажата левая кнопка мыши");
		}
		break;
	case WM_RBUTTONDOWN:
		{
			SetWindowText(hEdit, L"Нажата правая кнопка мыши");
			KillTimer(hWnd, 1);
			SetParent(hButton1, hWnd);
		}
		break;
	case WM_CREATE:
		{
			MessageBox(NULL, L"Создано окно!", L"ClickWindow", MB_OK);
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
		{
		MessageBox(NULL, L"Окно закрыто!", L"ClickWindow", MB_OK);
		PostQuitMessage(0);
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
