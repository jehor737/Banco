#include "Retiro.h"

#include "Deposito.h"

Retiro::Retiro(){}

Retiro::Retiro(string n, int num, float din, float dinRet)
{
    nombre = n;
    numCuenta = num;
    dinero = din;
    dineroRetirado = dinRet;
}

float Retiro::getRetiro()
{
    return dineroRetirado;
}

void Retiro::setRetiro(float dep)
{
    dineroRetirado = dep;
}

float Retiro::dineroFinal()
{
    float dineroFinal;

    dineroFinal = Cuenta::getDinero() - getRetiro();
    if(dineroFinal < 0)
    {
        cout<<"No puede exceder el monto que tiene"<<endl;
        return Cuenta::getDinero();
    }
    else return dineroFinal;
}

