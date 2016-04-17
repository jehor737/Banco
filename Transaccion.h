#include "Deposito.h"
#include "Retiro.h"
#include <vector>

class Transaccion
{
    private:
        vector<Deposito*> depositos;
        vector<Retiro*> retiros;
        int cuentTransf;
        float dinTransf;
    
    public:
    
        Transaccion();
    
        float Depositos(string n, int num, float d);
        float Retiros(string n, int num, float d);
    
        void reporteRetiros();
        void reporteDepositos();
        void reporteTransacciones(int num);
        float transferencias(string n, int num, float d, vector<Cuenta*> u);
};