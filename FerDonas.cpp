#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pedido
{
    string apellido;
    vector<comida> lista;
};

struct comida
{
    string nombre;
    float precio;
};
queue<pedido>donas;
queue<pedido>cregular;
vector<comida>lista;


int main(){

    bool pedir =true;  
    bool continuar=true;
    int opcion,tipo;
    float gdonas=0,gplatof=0,totalp=0,totalppt=0;
    string decision;
    comida unacomida;
    pedido unpedido;
    
    do
    {
        opcion=0;
        cout<<"Escoja una de las siguientes opciones:"<<endl;
        cout<<"1.Hacer un pedido"<<endl;
        cout<<"2.Ganancia por donas"<<endl;
        cout<<"3.Ganancia por platos fuertes"<<endl;
        cout<<"4.Salir"<<endl;
        cin>>opcion;cin.ignore();

        switch (opcion)
        {
        case 1:
            tipo=0;
            Dcorrect:
            cout<<"Que desea ordenar?"<<endl;
            cout<<"1.Donas"<<endl;
            cout<<"2.Plato Fuerte"<<endl;
            cin>>tipo;cin.ignore();

            switch (tipo)
            {
            case 1:
                
                Ncorrect:
                cout<<"El menu de las donas es: "<<endl;
                cout<<"Dona sencilla $1.00"<<endl;
                cout<<"Dona rellena $1.25"<<endl;
                cout<<"Sabores especiales(moca,caramelo) $1.50"<<endl;
                cout<<"Cual dona desea?";getline(cin, unacomida.nombre);cin.ignore();
                if (unacomida.nombre == "Dona sencilla")
                {
                    unacomida.precio = 1.00;
                    gdonas += 1.00;
                }
                else if (unacomida.nombre == "Dona Rellena")
                {
                    unacomida.precio = 1.25;
                    gdonas += 1.25;
                }
                else if (unacomida.nombre == "Sabor especial")
                {
                    unacomida.precio = 1.50;
                    gdonas += 1.50;
                }
                else
                {
                    cout<<"Elija una dona que se encuentre en el menu"<<endl;
                    goto Ncorrect;
                }
                totalp += unacomida.precio;
                cout<<"Su mnto total de momento es "<<totalp<<endl;
                lista.insert(lista.begin(),unacomida);

                cout<<"Desea seguir ordenando donas?(s/n)"<<endl;
                cin>>decision;
                if (decision=="s")
                {
                    
                    goto Ncorrect;
                }
                else
                {
                    cout<<"A nombre de quien se haria el pedido?"<<endl;
                    getline(cin,unpedido.apellido);cin.ignore();
                    donas.push(unpedido);
                    break;
                } 
            case 2:
                Lcorrect:
                cout<<"Este es el menu de la platos fuertes: "<<endl;
                cout<<"Desayuno $2.50"<<endl;
                cout<<"Almuerzo $5.00"<<endl;
                cout<<"Cena $3.50"<<endl;
                cout<<"Cual plato fuerte desea ordenar?";getline(cin,unacomida.nombre);cin.ignore();

                if (unacomida.nombre =="Desayuno")
                {
                    unacomida.precio=2.50;
                    gplatof += 2.50;
                }
                else if (unacomida.nombre =="Almuerzo")
                {
                    unacomida.precio=5.00;
                    gplatof += 5.00;
                }
                else if (unacomida.nombre == "Cena")
                {
                    unacomida.precio=3.50;
                    gplatof +=3.50;
                }
                else
                {
                    cout<<"Elija un plato del menu"<<endl;
                    goto Lcorrect;
                }
                
                totalppt += unacomida.precio;
                cout<<"Su monto total de momento "<<totalppt<<endl;
                lista.insert(lista.begin(),unacomida);

                cout<<"Desea ordenar mas platos fuertes?(s/n)"<<endl;
                cin>>decision;
                if (decision == "s")
                {
                    goto Lcorrect;
                }
                else
                {
                    cout<<"A nombre de quien se hara el pedido?"<<endl;
                    getline(cin,unpedido.apellido);cin.ignore();
                    cregular.push(unpedido);
                    break;
                }
                
            default:
                cout<<"Escoja una opcion valida"<<endl;
                goto Dcorrect;
                break;
            }
            break;
        case 2:
            cout<<"El total de la ganacia de donas es "<<gdonas<<endl;
            break;
        case 3:
            cout<<"El total de la ganacia de platos fuertes es "<<gplatof<<endl;
            break;
        default:
            break;
        }

    } while (continuar);
    

    return 0;
}