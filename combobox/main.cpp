#include<tchar.h>
#include<windows.h>
#include "ConvertidorMedidas.cpp"
#include<iostream>
using namespace std;

#define cb_unidades1 100
#define cb_unidades2 101
#define edit_resultado 102
#define edit_valor 103
#define bt1 104
#define bt_convertir 105





LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam){

    int nItems;
    const char* Unidades[]={
        "Kilometros","Hectometros","Decametros","Metros","Centimetro","Milimetros","Pulgadas","Yardas","Pies"
    };
    nItems = (sizeof(Unidades)/(sizeof(char*)));

    switch(message){
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            //ws_visible: permite que el boton sea visible
            //CreateWindowEx(0,"button",("boton"),WS_VISIBLE|WS_CHILD|0,0,0,50,25,hwnd,(HMENU)bt1,0,0);
            CreateWindowEx(0,"button",("Convertir"),WS_VISIBLE|WS_CHILD,445,10,100,25,hwnd,(HMENU)bt_convertir,0,0);
            CreateWindowEx(0,"edit",(""),WS_VISIBLE|WS_CHILD,225,10,100,25,hwnd,(HMENU)edit_resultado,0,0);
            CreateWindowEx(0,"edit",(""),WS_VISIBLE|WS_CHILD,10,10,100,25,hwnd,(HMENU)edit_valor,0,0);
            CreateWindowEx(0,"combobox","",CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD,335,10,100,25,hwnd,(HMENU)cb_unidades1,0,0);

            for(int i=0;i<nItems;i++)
                SendDlgItemMessage(hwnd,cb_unidades1,CB_ADDSTRING,0,(LPARAM)Unidades[i]);
            SendDlgItemMessage(hwnd,cb_unidades1,CB_SETCURSEL,(WPARAM)3,(LPARAM)0);

            CreateWindowEx(0,"combobox","",CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD,120,10,100,500,hwnd,(HMENU)cb_unidades2,0,0);

            for(int i=0;i<nItems;i++)
                SendDlgItemMessage(hwnd,cb_unidades2,CB_ADDSTRING,0,(LPARAM)Unidades[i]);
            SendDlgItemMessage(hwnd,cb_unidades2,CB_SETCURSEL,(WPARAM)3,(LPARAM)0);

            break;

        case WM_COMMAND:
            switch(LOWORD(wParam)){
            case bt_convertir:{
                char opc1[20] = {0} , opc2[20] = {0};
                int exito;
                char respuesta[50];

                int itemIndice = SendDlgItemMessage(hwnd,cb_unidades1,CB_GETCURSEL,0,0);
                SendDlgItemMessage(hwnd,cb_unidades1,CB_GETLBTEXT,itemIndice,(LPARAM)opc1);

                itemIndice = SendDlgItemMessage(hwnd,cb_unidades2,CB_GETCURSEL,0,0);
                SendDlgItemMessage(hwnd,cb_unidades2,CB_GETLBTEXT,itemIndice,(LPARAM)opc2);
                memset(respuesta,0,50);
                GetDlgItemText(hwnd,edit_valor,respuesta,50);

                double entrada = atof(respuesta);
                memset(respuesta,0,50);
                sprintf(respuesta,"%lf",Convertir(opc1,opc2,entrada,&exito));
                if(exito != 1){
                    MessageBox(hwnd,"opcion no disponible","Pendiente",MB_OK);
                    SetDlgItemText(hwnd,edit_valor,"");
                    SetDlgItemText(hwnd,edit_resultado,"");
                }
                SetDlgItemText(hwnd,edit_resultado,respuesta);
                break;
            }

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
                          1000,
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
