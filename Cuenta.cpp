#include "Cuenta.h"

Cuenta::Cuenta(){}

Cuenta::Cuenta(string n, int num, float din)
{
    nombre = n;
    numCuenta = num;
    dinero = din;
}
        
string Cuenta::getNombre()
{
    return nombre;
}

void Cuenta::setNombre(string n)
{
    nombre = n;
}

int Cuenta::getNumCuenta()
{
    return numCuenta;
}

void Cuenta::setNumCuenta(int num)
{
    numCuenta = num;
}
        
float Cuenta::getDinero()
{
    return dinero;
}

void Cuenta::setDinero(float din)
{
    dinero = din;
}