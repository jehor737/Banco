#ifndef ACCOUNT
#define ACCOUNT
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Cuenta
{
    protected:
        
        string nombre;
        int numCuenta;
        float dinero;
       
    public:
        Cuenta();
        Cuenta(string nom, int numCuenta, float dinero);
        
        string getNombre();
        void setNombre(string n);
        
        int getNumCuenta();
        void setNumCuenta(int num);
        
        float getDinero();
        void setDinero(float din);
        
        float dineroFinal();
};
#endif