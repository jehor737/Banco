#include "Transaccion.h"

Transaccion::Transaccion(){}

float Transaccion::Depositos(string n, int num, float d)
{
    float dinero;
    cout<<"Ingrese deposito"<<endl;
    float deposito;
    cin>>deposito;
    if(depositos.size()==0){
        depositos.push_back(new Deposito(n, num, d, deposito));
        dinero = depositos[0]->dineroFinal();     
    }
    else{
        int i=depositos.size();
        depositos.push_back(new Deposito(n, num, d, deposito));
        dinero = depositos[i]->dineroFinal();    
    }
    
    return dinero;
    
}

float Transaccion::Retiros(string n, int num, float d)
{
    float dinero;
    
    cout<<"Saldo disponible "<<d<<" . Ingrese retiro"<<endl;
    float retiro;
    cin>>retiro;
    if(retiros.size()==0){
        retiros.push_back(new Retiro(n, num, d, retiro));
        dinero = retiros[0]->dineroFinal();    
    }
    else{
        int i=retiros.size();
        retiros.push_back(new Retiro(n, num, d,retiro));
        dinero = retiros[i]->dineroFinal();    
    }
    
    
    return dinero;
    
}


float Transaccion::transferencias(string n, int num, float d, vector<Cuenta*> u){
    cout<<"Ingrese la cuenta a la que quiere transferir la cantidad ingresada"<<endl;
    cin>>cuentTransf;
    dinTransf = Retiros(n, num, d);
    float transferido = d - dinTransf;
    for(int i=0; i<u.size(); i++){
        if(cuentTransf == u[i]->getNumCuenta()){
            n=u[i]->getNombre();
            d=u[i]->getDinero();
            int k=depositos.size();
            depositos.push_back(new Deposito(n, cuentTransf, d, transferido));
            float dinero= depositos[k]->dineroFinal();
            u[i]->setDinero(dinero);
            cout<<"Se han transferido "<<transferido<< " de la cuenta "<<num<<" a la cuenta "<<cuentTransf<<endl;
        }
    }

    return dinTransf;
}

void Transaccion::reporteRetiros()
{
    int i;
    cout<<"Persona\tCuenta\tCantidad"<<endl;
    for(i=0; i<retiros.size(); i++){
        cout<<retiros[i]->getNombre()<<"\t"<<retiros[i]->getNumCuenta()<<"\t"<<retiros[i]->getRetiro()<<endl;
    }
    
}

void Transaccion::reporteDepositos()
{
    int i;
    cout<<"Persona\tCuenta\tCantidad"<<endl;
    for(i=0; i<depositos.size(); i++){
        cout<<depositos[i]->getNombre()<<"\t"<<depositos[i]->getNumCuenta()<<"\t"<<depositos[i]->getDeposito()<<endl;
    }
    
}

void Transaccion::reporteTransacciones(int num)
{
    int i;
    cout<<retiros.size()<<endl;
    for(i=0; i<retiros.size(); i++){
        if(num == retiros[i]->getNumCuenta())
        cout<<retiros[i]->getNombre()<<"\t"<<retiros[i]->getNumCuenta()<<"\t"<<retiros[i]->getRetiro()<<endl;
    }

    for(i=0; i<depositos.size(); i++){
        if(num == depositos[i]->getNumCuenta())
        cout<<depositos[i]->getNombre()<<"\t"<<depositos[i]->getNumCuenta()<<"\t"<<depositos[i]->getDeposito()<<endl;
    }
}