#include<windows.h>
#include"Api.h"


extern TCHAR appName;

LRESULT CALLBACK WindowProcedure(HWND ventana,UINT mensaje,WPARAM wParam,LPARAM lParam){
    /*
        Manipulador de dispositivo de contexto
        Caracteristicas
        1. Objetos graficos del dispositivo  - brocha,pinceles
        2. Modos graficos del dispositivo - combinacion de colores, forma de muestra del pintado en la ventana
        3. Tipos de dispositivos - lugar donde vamos a dibujar
        4. Operaciones con dispositivos - operaciones con los objetos graficos
        5. Color y manejo de imagen     
    */
    HDC hdc = NULL;
    PAINTSTRUCT ps; 

    switch(mensaje){
        case WM_DESTROY:{
            PostQuitMessage(0);
            break;
        }

        case WM_PAINT:{
            hdc = BeginPaint(ventana,&ps);
            RECT rc;
            rc.left = 10;
            rc.right = 110;
            rc.top = 10;
            rc.bottom = 110;
            FrameRect(hdc,&rc,NULL);

            EndPaint(ventana,&ps);
            break;
        }

        default:{
            return DefWindowProc(ventana,mensaje,wParam,lParam);
        }

    }
    return 0;
}

BOOL RegistrarClaseEx(UINT clsEstilo,HINSTANCE instancia,LPCSTR clsName,LPCSTR menuName,WNDPROC wndProcedimiento,HBRUSH color){
    WNDCLASSEX wincl;
    //Estructura de window
    wincl.hInstance = instancia;
    wincl.lpszClassName = clsName;
    wincl.lpfnWndProc = wndProcedimiento; //esta funcion es llamada por window
    wincl.style = clsEstilo;
    wincl.cbSize = sizeof(WNDCLASSEX);

    //usa el icono y puntero por defecto
    wincl.hIcon = LoadIcon(NULL , IDI_APPLICATION); //icono que se ve desde carpeta
    wincl.hIconSm = LoadIcon(NULL,IDI_APPLICATION); // icono desde la app
    wincl.hCursor = LoadCursor(NULL,IDC_ARROW); // cursor
    wincl.lpszMenuName = menuName;  // barra de menu
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;

    wincl.hbrBackground = color;

    if(!RegisterClassEx(&wincl)){
        return false;
    }
    return true;
}