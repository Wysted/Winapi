#include "Api.h"

using namespace std;

typedef struct{
    string nombre;
    string nacionalidad;
    string cargo;
    string fechaIngreso;
    short edad;
    float salario;
    int n_empleado;
}Empleado;

BOOL CALLBACK dlgRegistroProc(HWND vent,UINT msg,WPARAM wParam,LPARAM lParam){
    PAINTSTRUCT ps;
    static HDC hdcvent;
    static HBRUSH pincel;
    static FILE* arch;

    switch(msg){
        case WM_INITDIALOG:{
            if((arch =fopen("registro.txt","ab"))==NULL){
                MessageBox(vent,"Fallo al abrir el archivo","Error",MB_OK|MB_ICONERROR);
                EndDialog(vent,TRUE);
            }
            if(GetDlgCtrlID((HWND)wParam)!=EDT_NOMBRE){
                SetFocus(GetDlgItem(vent,EDT_NOMBRE));
                return FALSE;
            }
            return TRUE;
        }
        case WM_COMMAND:{
            switch(LOWORD(wParam)){
               case ID_AGREGAR:{
                   break;
               } 
            }
            break;
        }
        case WM_PAINT:{
            hdcvent = BeginPaint(vent,&ps);
            if(hdcvent!=NULL){
                FillRect(hdcvent,&ps.rcPaint,CreateSolidBrush(RGB(217,233,242)));
                EndPaint(vent,&ps);
            }
            break;
        }
        case WM_CTLCOLORSTATIC:{
            pincel = CreateSolidBrush(RGB(217,233,242));
            SetBkColor((HDC)wParam,(RGB(217,233,242)));
            return (INT_PTR)pincel;
        }
        case WM_CLOSE:{
            DeleteObject(pincel);
            EndDialog(vent,TRUE);
            break;
        }
    }
    return FALSE;
}