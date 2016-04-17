#include "Banco.h"
class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "No tiene fondos.";
  }
} myex;


Banco::Banco(){}



Transaccion* Banco::getOperacionesBancarias()
{
    return operacion;
}

void Banco::setOperacionesBancarias(Transaccion *op)
{
    operacion = op;
}

void Banco::crearCliente(int i)
{
    usuario.push_back(new Cuenta());
    cout<<"Bienvenido por favor ingrese su nombre"<<endl;
    getline(cin,nom);
    usuario[i]->setNombre(nom);
    numCuenta = 1000 + i;
    usuario[i]->setNumCuenta(numCuenta);
    cout<<"¿Cuanto dinero tiene inicialmente en su nueva cuenta?"<<endl;
    cin>>din;
    usuario[i]->setDinero(din);
    cout<<usuario[i]->getNombre()<<", su numero de cuenta es "<<usuario[i]->getNumCuenta()<<endl;
    cout<<"\n";
    menu();   
}

void Banco::opciones(){
    int flag=0, cont=0;
    do{ 
        cout<<"¿Que desea hacer?\n1.Agregar cliente.\n2.Realizar operacion bancaria.\n3.Reportes\n4.Salir"<<endl;
        cin>>respuesta;
        
        if(isdigit(respuesta[0])){
            resp = atoi(respuesta);
            flag = 1;
        }
    }while(flag!=1);
    cin.ignore();
    switch(resp){
            case 1:
                if(usuario.size()==0){
                    i = 0;
                    crearCliente(i);
                }
            
                else{
                    i = usuario.size();
                    crearCliente(i);
                }
            
            break;
        
            case 2:
                flag =0;
                do{
                    flag = 0;
                    cin.clear();
                    if(cont > 0) cin.ignore(1024, '\n');
                    cout<<"Ingrese numero de cuenta"<<endl;
                    cin>>numCuenta;
                    cont++;
                    if(cin.fail() && cin.rdstate()){
                        cout << "No es un numero" << endl;
                        flag = 1;
                    }
                }while(flag==1);
                    
                for(i = 0; i<usuario.size(); i++){
                    if(numCuenta == usuario[i]->getNumCuenta()){
                        din = usuario[i]->getDinero();
                        nom = usuario[i]->getNombre();
                        do{
                        cout<<"¿Que transaccion desea hacer?\n1. Deposito\n2. Retiro\n3.Transferencia"<<endl;
                        cin>>respuesta;
                        
                            if(isdigit(respuesta[0])){
                                resp = atoi(respuesta);
                                flag = 1;
                            }
                        }while(flag!=1);
                        switch(resp)
                        {
                            case 1:
                                //depositarFondos(nom, numCuenta, din);
                                
                                dinFin = operacion->Depositos(nom, numCuenta, din);
                                usuario[i]->setDinero(dinFin);
                                cout<<"Dinero final "<<usuario[i]->getDinero()<<endl;
                                menu();
                            break;
                        
                            case 2:
                                try{
                                    if(din<=0){
                                      throw myex;
                                    }
                                    else{
                                        dinFin = operacion->Retiros(nom, numCuenta, din);
                                        usuario[i]->setDinero(dinFin);
                                        cout<<"Dinero final "<<usuario[i]->getDinero()<<endl;
                                    }
                                }
                                catch(exception& e){
                                    cout<<e.what()<<endl;
                                }
                                menu();
                            break;
                            
                            case 3:
                                
                                try{
                                    if(din<=0){
                                      throw myex;
                                    }
                                    else{
                                        float transferido=operacion->transferencias(nom, numCuenta, din, usuario);
                                        usuario[i]->setDinero(transferido);
                                    }
                                }
                                catch(exception& e){
                                    cout<<e.what()<<endl;
                                }
                            
                            break;
                        }
                    }
                }
                menu();
            break;
        
            case 3:
                flag = 0;
                
                do{
                    cout<<"¿De que desea reporte?\n1. Todos los clientes\n2. Todos los retiros\n3. Todos los depositos\n4. Transacciones de una cuenta en particular\n5. Regresar"<<endl;
                    cin>>respuesta;
                    if(isdigit(respuesta[0])){
                        resp = atoi(respuesta);
                        flag = 1;
                    }
                }while(flag!=1);
                
                switch(resp){
                    case 1:
                        cout<<"Persona\tCuenta"<<endl;
                        for(i=0; i<usuario.size(); i++)
                            cout<<usuario[i]->getNombre()<<"\t"<<usuario[i]->getNumCuenta()<<endl;
                        menu();
                    break;
                
                    case 2:
                        operacion->reporteRetiros();
                        menu();
                    break;
                    
                    case 3:
                        operacion->reporteDepositos();
                        menu();
                    break;
                    
                    case 4:
                        cont=0;
                        do{
                            flag = 0;
                            cin.clear();
                            if(cont > 0) cin.ignore(1024, '\n');
                                cout<<"Ingrese numero de cuenta"<<endl;
                                cin>>numCuenta;
                                cont++;
                                if(cin.fail() && cin.rdstate()){
                                cout << "No es un numero" << endl;
                                flag = 1;
                            }
                        }while(flag==1);
                        operacion->reporteTransacciones(numCuenta);
                        menu();
                    break;

                    default:
                        menu();
                    break;
                }
            
            break;
        
            case 4:
                return;
            break;
            default:
                menu();
            break;
        }
}

void Banco::menu()
{
    
    cout<<"Bienvenido al Banco POO"<<endl;
    opciones();
}