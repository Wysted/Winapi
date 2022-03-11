#ifndef API_H
#define API_H
#include<Windows.h>

#define ID_SALIR 1000

#define ID_REGISTRO 3000
#define EDT_NOMBRE 3100
#define EDT_NACIONALIDAD 3101
#define EDT_DNI 3102
#define EDT_NACIMIENTO 3103
#define EDT_EDAD 3104
#define EDT_SALARIO 3105
#define EDT_FECHA 3106 
#define EDT_CARGO 3107

#define STT_NOMBRE 3200
#define STT_NACIONALIDAD 3201
#define STT_DNI 3202
#define STT_EDAD 3204
#define STT_SALARIO 3205
#define STT_FECHA 3206
#define STT_CARGO 3207

#define ID_AGREGAR 2000
#define ID_ELIMINAR 2001
#define ID_BUSCAR 2002
#define ID_SIGUIENTE 2003
#define ID_ANTERIOR 2004

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam);
BOOL CALLBACK dlgRegistroProc(HWND vent,UINT msg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK dlgBuscarProc(HWND vent,UINT msg,WPARAM wParam,LPARAM lParam);


BOOL registrarClase(UINT estilo,HINSTANCE instancia,WNDPROC wndProcedimiento,LPCSTR nombreMenu,LPCSTR clsNombre,int color);

#endif