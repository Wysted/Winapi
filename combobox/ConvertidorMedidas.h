#ifndef CONVERTIDORMEDIDAS_H
#define CONVERTIDORMEDIDAS_H
double Convertir(const char* unidadEntrada, const char* unidadSalida, double entrada,int* exito);
//  Kilometros","Hectometros","Decametros","Metros","Centimetro","Milimetros","Pulgadas","Yardas","Pies"

double metros_kilometros(double);
double metros_hectometros(double);
double metros_decametros(double);
double metros_metros(double);
double metros_centimetros(double);
double metros_milimetros(double);
double metros_pulgadas(double);
double metros_yardas(double);
double metros_pies(double);

#endif // CONVERTIDORMEDIDAS_H
