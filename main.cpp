#include "Banco.h"

int main()
{
    Banco *sucursal = new Banco();
    Transaccion *operaciones = new Transaccion();
    sucursal->setOperacionesBancarias(operaciones);
    //Cuenta *usuario = new Cuenta();
    
    //sucursal->setClientes(usuario);
    
    sucursal->menu();
    
    int aa;
    cin>>aa;
    
    return 0;
}