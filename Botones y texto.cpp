#include<tchar.h>
#include<windows.h>
#define bt1 101
#define bt2 102
#define btcrr 103
#define edit 104
#define leer 105

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam){
    switch(message){
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            //ws_visible: permite que el boton sea visible
            CreateWindowEx(0,"button",("Texto"),WS_VISIBLE|WS_CHILD|0,0,0,50,25,hwnd,(HMENU)bt1,0,0);
            CreateWindowEx(0,"button",("vale"),WS_VISIBLE|WS_CHILD|0,0,30,50,25,hwnd,(HMENU)bt2,0,0);
            CreateWindowEx(0,"button",("Cerrar"),WS_VISIBLE|WS_CHILD|0,0,60,50,25,hwnd,(HMENU)btcrr,0,0);
            CreateWindowEx(0,"button",("leer"),WS_VISIBLE|WS_CHILD|0,155,0,50,25,hwnd,(HMENU)leer,0,0);
            CreateWindowEx(0,"edit","",ES_AUTOHSCROLL|ES_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER|0,55,0,100,25,hwnd,(HMENU)edit,0,0);


            break;
        case WM_COMMAND:
            switch(LOWORD(wParam)){
            case bt1:
                MessageBox(hwnd,"hi","hi world",MB_OK);
                break;
            case bt2:
                MessageBox(hwnd,"puta","puta",MB_OK);
                break;
            case btcrr:
                PostQuitMessage(0);
                break;
            case leer:
                char buffer[500]={0};
                GetDlgItemText(hwnd,edit,buffer,100);
                MessageBox(hwnd,buffer,"Puta",MB_OK);
                break;
            }
        break;

        default:
            return DefWindowProc(hwnd,message,wParam,lParam);
    }
    return 0;
}

TCHAR szClassName[ ] = _T("CodeBlockWindowsApp");

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstace,
                   LPSTR lpszArgument,
                   int nCmdShow){
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;
    //Estructura de window
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure; //esta funcion es llamada por window
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);

    //usa el icono y puntero por defecto
    wincl.hIcon = LoadIcon(NULL , IDI_APPLICATION); //icono que se ve desde carpeta
    wincl.hIconSm = LoadIcon(NULL,IDI_ERROR); // icono desde la app
    wincl.hCursor = LoadCursor(NULL,IDC_HELP); // cursor
    wincl.lpszMenuName = NULL;  // barra de menu
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;

    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if(!RegisterClassEx(&wincl))
        return 0;

    hwnd = CreateWindowEx(0,
                          szClassName,
                          _T("Code::Block Template Window App"),//titulo
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          500,
                          500,
                          HWND_DESKTOP,
                          NULL,
                          hThisInstance,
                          NULL
                          );
    ShowWindow(hwnd,nCmdShow);
    ShowWindow(GetConsoleWindow( ),SW_HIDE);//oculta la cmd

    while(GetMessage(&messages,NULL,0,0)){//provoca que la ventana no se cierre de manera instantanea
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}
