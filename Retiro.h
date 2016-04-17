#include "Cuenta.h"

class Retiro : public Cuenta
{
    private:
        float dineroRetirado;
    
    public:
        Retiro();
        Retiro(string nombre, int numCuenta, float dinero, float dineroRetirado);
        
        float getRetiro();
        void setRetiro(float dinRet);
        
        float dineroFinal();
};