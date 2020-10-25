//DONAS CAJAS REGISTRADORAS
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>


using namespace std;

struct producto{
    string nombre;
    float precio_unitario;
};

struct pedido{
    string apellido;
    vector<producto> lista_comida;
};

//prototipos funciones
void menuPrincipal();
void menuDonas();
void menuComida();
void menuOpcion();




int main(){
	
	//opciones menu
    int op;
    int op2; 
    int opDona; 
    int opComida; 
    float TotalD;
    float TotalP;
    float SumaD;
    float SumaP;
    
    queue<pedido> clienteD;
    queue<pedido> clienteP;

    pedido pedidoD;
    pedido pedidoP;
    pedido pedidoSumaD;
    pedido pedidoSumaP;


    producto productoD;
    producto productoP;
    producto productoSumaD;
    producto productoSumaP;

    vector<producto> lista_comidaD;
    vector<producto> lista_comidaP;

    do{
    	//menus
        menuPrincipal();
        cin>>op;
 
        switch(op)
        {
            case 1:
                system("cls");
                do{
                    menuOpcion();
                    cin>>op2;
                    switch(op2)
                    {
                        case 1: //para donas
                                cout<<"Su apellido:";
                                cin>>pedidoD.apellido;
                                do{
                                    menuDonas();
                                    cin>>opDona;
                                    switch(opDona)
                                    {
                                        case 1:
                                                productoD.nombre = "Sencilla";
                                                productoD.precio_unitario = 1.00;
                                                lista_comidaD.push_back(productoD);
                                                cout<<"producto Agregado:" << productoD.nombre<<"\n";
                                                TotalD += 1.00;
                                                break;
                                        case 2:
                                                productoD.nombre = "Rellena";
                                                productoD.precio_unitario = 1.25;
                                                 lista_comidaD.push_back(productoD);
                                                cout<<"producto Agregado:" << productoD.nombre<<"\n";     
                                                 TotalD += 1.25;                                          
                                                break;
                                        case 3:
                                                productoD.nombre = "Especial";
                                                productoD.precio_unitario = 1.50;
                                                 lista_comidaD.push_back(productoD);
                                                cout<<"producto Agregado:" << productoD.nombre<<"\n";    
                                                 TotalD += 1.50;                                           
                                                break;
                                    }
                                    pedidoD.lista_comida = lista_comidaD;                                  
                                }while(opDona!=4);
                                 //calcular total
                                system("pause");
                                cout<<endl;
                                cout<<"Total de Donas:"<<pedidoD.lista_comida.size()<<"\n";
                                cout<<"Total del cliente:"<<TotalD<<"\n";



                                clienteD.push(pedidoD);
                                cout<<endl;
                                system("pause");

                                break;
                        case 2:  //para platillos
                                cout<<"Su apellido:";
                                cin>>pedidoP.apellido;
                                do{
                                    menuComida();
                                    cin>> opComida;
                                    switch(opComida)
                                    {
                                        case 1:
                                            productoP.nombre = "Desayuno";
                                            productoP.precio_unitario = 2.50;
                                            lista_comidaP.push_back(productoP);
                                            cout<<"producto Agregado:" << productoP.nombre<<"\n";
                                             TotalP += 2.50;
                                            break;

                                        case 2:
                                            productoP.nombre = "Almuerzo";
                                            productoP.precio_unitario = 5.00;
                                            lista_comidaP.push_back(productoP);
                                            cout<<"producto Agregado:" << productoP.nombre<<"\n"; 
                                             TotalP += 5.00;
                                            break;
                                        case 3:
                                            productoP.nombre = "Cena";
                                            productoP.precio_unitario = 3.50;
                                            lista_comidaP.push_back(productoP);
                                            cout<<"producto Agregado:" << productoP.nombre<<"\n"; 
                                             TotalP += 3.50;
                                            break;
                                    }
                                    pedidoP.lista_comida = lista_comidaP;     
                                }while(opComida!=4);
								//calcular total
                                system("pause");
                                cout<<endl;
                                cout<<"Total de Platos :"<<pedidoP.lista_comida.size()<<"\n";
                                cout<<"Total del cliente:"<<TotalP<<"\n";
                                clienteP.push(pedidoP);
                                cout<<endl;
                                system("pause");
                    }
                    cout<<endl<<endl; 
                    system("cls"); 
                }while(op2!=3);
                break;
            case 2:
            	  if (clienteD.empty()){
                        cout<<"No existen pedidos de donas.\n";
                    }else{
                        
                        
                        while(!clienteD.empty()){
                        pedidoSumaD = clienteD.front();
                        for(int i=0;i<pedidoSumaD.lista_comida.size();i++){
                            productoSumaD = pedidoSumaD.lista_comida[i];
                            SumaD += productoSumaD.precio_unitario;
                        }
                         cout<<"Total venta donas. \n"<<SumaD<<"\n";
                        clienteD.pop();
                        }
                       
                	}
                    system("pause");
                 
                 
                break;
            case 3:
            	if (clienteP.empty()){
                        cout<<"No existen pedidos de Platos fuertes.\n";
                    }else{
                        
                        
                        while(!clienteP.empty()){
                        pedidoSumaP = clienteP.front();
                         for(int i=0;i<pedidoSumaD.lista_comida.size();i++){
                            productoSumaP = pedidoSumaP.lista_comida[i];
                            SumaP += productoSumaP.precio_unitario;
                        }
                        cout<<"Total venta platos fuertes. \n"<<SumaP<<"\n";
                        clienteP.pop();
                        }
                        
                	}
                    system("pause");
                 
                break;
        }
        cout<<endl<<endl; 
        system("cls");    
    }while(op!=4);

    system("pause");
    return 0;
}

 //funciones menus :3
void menuPrincipal()
{
    cout<<"\n\t\t .: Promociones de Donas :.\n\n";
    cout<<" 1. Atender pedidos de clientes."<<endl;
    cout<<" 2. Calcular ganancias por venta de donas."<<endl;
    cout<<" 3. Calcular ganancias por venta de platos fuertes."<<endl;
    cout<<" 4. Salir                   "<<endl;
 
    cout<<"\n Ingrese Opcion: ";
}

void menuDonas()
{
    cout<<"\n\t\t--Donas--\n\n";
    cout<<" 1. Sencilla $1"<<endl;
    cout<<" 2. Rellena de leche $1.25"<<endl;
    cout<<" 3. Sabores especiales(moca, caramelo) $1.50"<<endl;
    cout<<" 4. Volver"<<endl;
    cout<<"\n Ingrese Seleccion de donas: ";
}

void menuComida()
{
    cout<<"\n\t\t--Platos Fuertes--\n\n";
    cout<<" 1. Desayuno $2.50"<<endl;
    cout<<" 2. Almuerzo $5.00"<<endl;
    cout<<" 3. Cena $3.50"<<endl;
    cout<<" 4. Volver"<<endl;
    cout<<"\n Ingrese Seleccion de platos fuertes: ";
}

void menuOpcion()
{
    cout<<"\n\t\t--Seleccion entre donas y platos fuertes--\n\n";
    cout<<" 1. Donas"<<endl;
    cout<<" 2. Platos fuertes"<<endl;
    cout<<" 3. Volver"<<endl;
    cout<<"\n Ingrese Seleccion de tipo de comida: ";
}


