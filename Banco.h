#include "Transaccion.h"
#include <cctype>
#include <cstdlib>
class Banco
{
    private:
        vector<Cuenta*>usuario;
        Transaccion *operacion;
        string nom;
        char respuesta[2];
        int numCuenta, resp, i, cuentTransf;
        float din, dinFin;
        
    public:
        Banco();
        
        Transaccion* getOperacionesBancarias();
        void setOperacionesBancarias(Transaccion *operacion);
        
        void menu();
        void opciones();
        void crearCliente(int i);
};