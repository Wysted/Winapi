#include <windows.h>
#include <tchar.h>

#define bt1 101

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam);
BOOL insertarMenu(HWND ventana);

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
    wincl.hIconSm = LoadIcon(NULL,IDI_WINLOGO); // icono desde la app
    wincl.hCursor = LoadCursor(NULL,IDC_HELP); // cursor
    wincl.lpszMenuName = NULL;  // barra de menu
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;

    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if(!RegisterClassEx(&wincl))
        return 0;

    hwnd = CreateWindowEx(0,
                          szClassName,
                          _T("Window"),//titulo
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
   // insertarMenu(hwnd);
    ShowWindow(GetConsoleWindow( ),SW_HIDE);//oculta la cmd
    ShowWindow(hwnd,nCmdShow);

    while(GetMessage(&messages,NULL,0,0)){//provoca que la ventana no se cierre de manera instantanea
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,LPARAM lParam){

    switch(message){
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
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

BOOL insertarMenu(HWND ventana){
    HMENU menuPrincipal,opMenuPrincipal;
    opMenuPrincipal = CreateMenu();
    menuPrincipal = CreateMenu();

    if(menuPrincipal == NULL || opMenuPrincipal == NULL){
        return FALSE;
    }
    if(AppendMenu(opMenuPrincipal,MF_STRING,1,"Agregar")==0){
        return FALSE;
    }
    if(AppendMenu(opMenuPrincipal,MF_STRING,2,"Eliminar")==0){
        return FALSE;
    }
    if(AppendMenu(opMenuPrincipal,MF_SEPARATOR,0,NULL)==0){
        return FALSE;
    }
    if(AppendMenu(opMenuPrincipal,MF_STRING,3,"Salir")==0){
        return FALSE;
    }
    //le dice a la ventana principal que tendra
    //una opcion plegable
    if(AppendMenu(menuPrincipal,MF_POPUP|MF_STRING,(UINT64)opMenuPrincipal,"Menu Principal")==0){
        return FALSE;
    }
    //Coloca el menu plegable
    if(SetMenu(ventana,menuPrincipal)==0){
        return FALSE;
    }

    return TRUE;
}