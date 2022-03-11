#include "Api.h"
#include<iostream>
#include<string>
using namespace std;

typedef struct{
    string nombre;
    string nacionalidad;
    string cargo;
    string fechaIngreso;
    string dni;
    short edad;
    float salario;
    int n_empleado;
}Empleado;

void initEmpleado(Empleado* e);
void mostrarEmpleado(HWND vent,Empleado* e);

BOOL CALLBACK dlgRegistroProc(HWND vent,UINT msg,WPARAM wParam,LPARAM lParam){
    PAINTSTRUCT ps;
    static HDC hdcvent;
    static HBRUSH pincel;
    static FILE* arch;

    static Empleado e;

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
                char buffer[50];
                    initEmpleado(&e);

                    char *nombre = &e.nombre[0];
                    char *nacionalidad = &e.nacionalidad[0];
                    char *dni = &e.dni[0];
                    char *fecha = &e.fechaIngreso[0];
                    char *cargo = &e.cargo[0];
                    GetDlgItemText(vent,EDT_NOMBRE,nombre,50);
                    GetDlgItemText(vent,EDT_NACIONALIDAD,nacionalidad,30);
                    GetDlgItemText(vent,EDT_DNI,dni,20);
                    e.edad = GetDlgItemInt(vent,EDT_EDAD,NULL,FALSE);
                    GetDlgItemText(vent,EDT_CARGO,cargo,30);
                    memset(buffer,'\0',50);
                    GetDlgItemText(vent,EDT_SALARIO,buffer,50);
                    e.salario = strtod(buffer,NULL);
                    GetDlgItemText(vent,EDT_FECHA,fecha,12);
                    fwrite(&e,sizeof(Empleado),1,arch);
                break;
                }
                case ID_ELIMINAR:{
                    SendMessage(vent,WM_CLOSE,0,0);
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
            fclose(arch);
            EndDialog(vent,TRUE);
            break;
        }
    }
    return FALSE;
}

BOOL CALLBACK dlgBuscarProc(HWND vent,UINT msg,WPARAM wParam,LPARAM lParam){
    PAINTSTRUCT ps;
    static HDC hdcvent;
    static HBRUSH pincel;
    static FILE* arch;

    static Empleado e;
    static int pos = 0;
    static int nEmpleados = 0;

    switch(msg){
        case WM_INITDIALOG:{
            if((arch = fopen("registro.txt","ab"))==NULL){
                MessageBox(vent,"Fallo al abrir el archivo","Error",MB_OK|MB_ICONERROR);
                EndDialog(vent,TRUE);
            }
            pos = 0;
            fseek(arch,0,SEEK_END);
            nEmpleados = (int)(ftell(arch)/sizeof(Empleado));

            rewind(arch);
            fread(&e,sizeof(Empleado),1,arch);
            mostrarEmpleado(vent,&e);
            pos = 0;
            EnableWindow(GetDlgItem(vent,ID_ANTERIOR),FALSE);
            if(nEmpleados == 1){
                EnableWindow(GetDlgItem(vent,ID_SIGUIENTE),FALSE);
            }
            break;
        }
        case WM_COMMAND:{
            switch(LOWORD(wParam)){
                case ID_SIGUIENTE:{
                    pos++;
                    if(pos >= (nEmpleados-1)){
                        EnableWindow(GetDlgItem(vent,ID_SIGUIENTE),FALSE);
                    }
                    EnableWindow(GetDlgItem(vent,ID_ANTERIOR),TRUE);
                    rewind(arch);
                    fseek(arch,pos*sizeof(Empleado),SEEK_SET);
                    fread(&e,sizeof(Empleado),1,arch);
                    mostrarEmpleado(vent,&e);
                }
                case ID_ANTERIOR:{
                    pos--;
                    if(pos < 1){
                        EnableWindow(GetDlgItem(vent,ID_ANTERIOR),FALSE);
                    }
                    EnableWindow(GetDlgItem(vent,ID_SIGUIENTE),TRUE);
                    rewind(arch);
                    fseek(arch,pos*sizeof(Empleado),SEEK_SET);
                    fread(&e,sizeof(Empleado),1,arch);
                    mostrarEmpleado(vent,&e);
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
            fclose(arch);
            EndDialog(vent,TRUE);
            break;
        }
    }
    return FALSE;
}

void initEmpleado(Empleado* e){
    e->nombre = "";
    e->cargo = "";
    e->nacionalidad = "";
    e->dni = "";
    e->fechaIngreso = "";
    e->edad = 0;
    e->salario = 0.0;
}
void mostrarEmpleado(HWND vent,Empleado* e){
    char buffer[50];
    char *nombre = &e->nombre[0];
    char *nacionalidad = &e->nacionalidad[0];
    char *dni = &e->dni[0];
    char *fecha = &e->fechaIngreso[0];
    char *cargo = &e->cargo[0];
    SetDlgItemText(vent,EDT_NOMBRE,nombre);
    SetDlgItemText(vent,EDT_NACIONALIDAD,nacionalidad);
    SetDlgItemText(vent,EDT_DNI,dni);
    SetDlgItemText(vent,EDT_FECHA,fecha);
    SetDlgItemText(vent,EDT_CARGO,cargo);
    SetDlgItemInt(vent,EDT_EDAD,e->edad,TRUE);
    memset(buffer,'\0',20);
    sprintf(buffer,"%.2lf",e->salario);
    SetDlgItemText(vent,EDT_SALARIO,buffer);
}