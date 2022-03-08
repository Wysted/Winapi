#include <windows.h>
#include <tchar.h>
#include "Api.h"


const char* const appName = "Curso WINAPI";
const char* const clsName = "Mi clase";

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam){
    static HINSTANCE instancia;

    switch(message){
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            instancia = ((LPCREATESTRUCT)lParam)->hInstance;
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam)){
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
                          _T("Principal"),//titulo
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          500,
                          500,
                          HWND_DESKTOP,
                          LoadMenu(hThisInstance,"MenuPrincipal"),
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

BOOL CALLBACK dlgAgregarProc(HWND hwnd,UINT mensaje,WPARAM wParam,LPARAM lParam){

    switch(mensaje){
        case WM_COMMAND:{
            switch(LOWORD(wParam)){
                case IDOK:{
                    MessageBox(hwnd,"Aceptar","Ejemplo",MB_OK);
                    break;
                }
            }
            return TRUE;
        }
        case WM_CLOSE:{
            EndDialog(hwnd,TRUE);
            return TRUE;
        }
    }
    return FALSE;
}