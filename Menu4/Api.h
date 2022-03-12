#include<Windows.h>

#ifndef API_H
#define API_H

LRESULT CALLBACK WindowProcedure(HWND ventana,UINT mensaje,WPARAM wParam,LPARAM lParam);
BOOL RegistrarClaseEx(UINT clsEstilo,HINSTANCE instancia,LPCSTR clsName,LPCSTR menuName,WNDPROC wndProcedimiento,HBRUSH color);

#endif