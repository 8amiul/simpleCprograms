#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

#define SECOND_TIMER 1000

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (
HINSTANCE hInstance, HINSTANCE hPrevInstance,
PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloWin");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    HICON hIcon;
    hIcon = LoadImage(NULL, "favicon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = hIcon;
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT"),
            szAppName, MB_ICONERROR);
        return 0;
    }
    hwnd = CreateWindow(szAppName,
        TEXT("TimeDateWin32"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
        );

    ShowWindow(hwnd, iCmdShow);

    UpdateWindow(hwnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(
    HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam
)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rec;

    switch (message)
    {
        case WM_CREATE:
            //PlaySound(TEXT("sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
            return 0;
        case WM_PAINT:
            SetTimer(hwnd, SECOND_TIMER, SECOND_TIMER, NULL);       // Timer for refreshing the window

            hdc = BeginPaint(hwnd, &ps);

            GetClientRect(hwnd, &rec);
            /*
            rec.left = 0; rec.top = 0;
            rec.right = 200; rec.bottom = 200;
            */
            FillRect(hdc, &rec, CreateSolidBrush(RGB(0,0,0)));                   // Filling the rect bg with some color.
            // CreateSolidBrush returns a hbr type. RGB is a macro for COLORREF
            
            SYSTEMTIME st, lt;
            GetSystemTime(&st);
            GetLocalTime(&lt);
            char time[100];
            sprintf(time, "%02d:%02d:%02d [%02d/%02d/%04d]", lt.wHour-12, st.wMinute, st.wSecond, st.wDay, st.wMonth, st.wYear);
            
            AddFontResourceA("font.ttf");
            AddFontResourceA("font2.ttf");
            HFONT hFont1 = CreateFont(
                80,
                0,
                0,
                0,
                FW_REGULAR,
                FALSE,
                FALSE,
                FALSE,
                DEFAULT_CHARSET,
                OUT_DEFAULT_PRECIS,
                CLIP_DEFAULT_PRECIS,
                ANTIALIASED_QUALITY,
                DEFAULT_PITCH,
                "Delius"
            );
            SelectObject(hdc, hFont1);

            SetBkColor(hdc, RGB(0, 0, 0));                                       // Setting text bg color

            SetTextColor(hdc, RGB(255, 255, 255));                                   // Setting text fg color
            DrawText(hdc, time, -1, &rec, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);  // Drawing text in a rect

            SetTextColor(hdc, RGB(255, 98, 0));
            TextOut(hdc, 10, 0, "TimeDateWin32", 13);                                // Drawing text in a x,y position


            EndPaint(hwnd, &ps);
            return 0;
        case WM_TIMER:
            if(wParam == SECOND_TIMER)
                InvalidateRect( hwnd, NULL, FALSE );    // Refreshing window
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
