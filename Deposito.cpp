#include "Deposito.h"

Deposito::Deposito(){}

Deposito::Deposito(string n, int num, float din, float dinDep)
{
    nombre = n;
    numCuenta = num;
    dinero = din;
    dineroDepositado = dinDep;
}

float Deposito::getDeposito()
{
    return dineroDepositado;
}

void Deposito::setDeposito(float dep)
{
    dineroDepositado = dep;
}

float Deposito::dineroFinal()
{
    float dineroFinal;
    
    dineroFinal = Cuenta::getDinero() + getDeposito();
    
    return dineroFinal;
}
