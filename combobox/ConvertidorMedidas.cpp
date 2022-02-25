#include "ConvertidorMedidas.h"
#include<string.h>

double Convertir(const char*unidadEntrada,const char* unidadSalida,double entrada,int *exito){
    *exito = 1;

    if( (strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Kilometros")==0)){
        return metros_kilometros(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Hectometros")==0)){
        return metros_hectometros(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Decametros")==0)){
        return metros_decametros(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Metros")==0)){
        return metros_metros(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Centimetro")==0)){
        return metros_centimetros(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Milimetros")==0)){
        return metros_milimetros(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Pulgadas")==0)){
        return metros_pulgadas(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Yardas")==0)){
        return metros_yardas(entrada);
    }else if((strcmp(unidadEntrada,"Metros")==0) && (strcmp(unidadSalida,"Pies")==0)){
        return metros_pies(entrada);
    }else{
        *exito = 0;
        return 0.0;
    }
}
double metros_kilometros(double a){
    return a/1000;
}
double metros_hectometros(double a){
    return a/100;
}
double metros_decametros(double a){
    return a/10;
}
double metros_metros(double a){
    return a;
}
double metros_centimetros(double a){
    return a*100;
}
double metros_milimetros(double a){
    return a*1000;
}
double metros_pulgadas(double a){
    return a*39.37;
}
double metros_yardas(double a){
    return a*1.094;
}
double metros_pies(double a){
    return a*3.281;
}
