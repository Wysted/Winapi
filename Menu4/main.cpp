#include <windows.h>
#include <tchar.h>
#include"Api.h"

TCHAR szClassName[] = _T("Ventana principal");
TCHAR AppName[] = _T("Curso winapi");


int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstace,
                   LPSTR lpszArgument,
                   int nCmdShow){
    HWND hwnd;
    MSG messages;

    if(!RegistrarClaseEx(CS_DBLCLKS,hThisInstance,szClassName,NULL,WindowProcedure,CreateSolidBrush(RGB(150,150,150)))){
        MessageBox(NULL,"Error: Fallo al registrar la ventana",AppName,MB_OK|MB_ICONERROR);
        return EXIT_FAILURE;
    }

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
