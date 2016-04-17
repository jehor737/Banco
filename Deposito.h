#include "Cuenta.h"

class Deposito : public Cuenta
{
    private:
        float dineroDepositado;
    
    public:
        Deposito();
        Deposito(string nombre, int numCuenta, float dinero, float dineroDepositado);
        
        float getDeposito();
        void setDeposito(float dinDep);
        
        float dineroFinal();
};