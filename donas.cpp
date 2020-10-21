#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

//Estructuras
struct productos
{
    string nombre;
    float precio;
};
typedef struct productos Productos;

struct pedido
{
    string Apellido;
    vector<Productos> Lista_comida;
};
typedef struct pedido Pedidos;

//Variables globales
queue<Pedidos> ColaDonas;
queue<Pedidos> ColaPlatos;

//Funciones
void AtenderC(float*, float*);
void ComprarPlatos(float*);
void ComprarDonas(float*);

int main()
{
    int uOPCION = 0;
    bool uBANDERA = true;
    float tDONAS = 0, tPLATOS = 0;

    cout << "\nBienvenido a Henry Donuts\n";

    do
    {
        cout << "\n1: Atender pedidos de clientes\n2: Calcular ganancia por donas\n3: Calcular ganancias por platos fuertes\n4: Salir del programa\n";
        cout << "Ingrese a cual funcion desea acceder: "; cin >> uOPCION;
        switch (uOPCION)
        {
            case 1:
            AtenderC(&tDONAS, &tPLATOS);
            break;

            case 2:
            cout << "\nCout el total vendido en donas es: $" << tDONAS << endl;
            break;

            case 3:
            cout << "\nCout el total vendido en donas es: $" << tPLATOS << endl;
            break;

            case 4:
            cout << "\nHa decidido salir del programa.\n";
            uBANDERA = false;
            break;

            default:
            cout << "\nNinguna de las opciones que ha ingresado es valida\n";
            break;
        }
    } while (uBANDERA);
    return 0;
}

void AtenderC(float *tDONAS, float *tPLATOS)
{
    int oOPCION = 0;
    bool oBANDERA = true;
    cout << "\n¿Que desea comprar?. Recuerde que solo puede elegir una de las opciones.\n";
    do
    {
        cout << "1: Donas\n2: Platos fuertes\n3: Regresar al menu principal\n";
        cout << "Elija a cual opcion desea acceder: "; cin >> oOPCION;
        switch(oOPCION)
        {
            case 1:
            ComprarDonas(tDONAS);
            return;
            break;

            case 2:
            ComprarPlatos(tPLATOS);
            return;
            break;

            case 3:
            cout << "\nHa decidido regresar al menu principal\n";
            oBANDERA = false;
            break;

            default:
            cout << "\nNinguna de la opciones que ha selecciona es valida\n";
            break;

        }
    } while (oBANDERA);
}

void ComprarDonas(float *tDONAS)
{
    int cUSU = 0;

    cout << "\nLos precios y disponibilidades de las donas son:\n";
    cout << "1: Sencilla $1\n2: Rellena $1.25\n3: Moca o Caramelo $1.50\n";

    cout << "\nIngrese la cantidad de donas que desea comprar: "; cin >> cUSU;
    if (cUSU < 0 )
    {
        cout << "\nNo puede adquirir esa cantidad de productos. Regresando al menu anterior.\n";
    }
    else
    {
        Productos uPROD;
        Pedidos uPED;
        float Monto = 0;
        vector<Productos> Listaproductos;
        for (int i = 0; i < cUSU ; i++)
        {
            
            int cDONAS = 0;
            cout << "\nIngrese el sabor de las donas que desea adquirir una por una que se mostro en el menu de sabores: ";
            cin >> cDONAS;
            switch (cDONAS)
            {
                case 1:
                uPROD.nombre = "Dona Sencilla";
                uPROD.precio = 1.00;
                *tDONAS += 1.00;
                Monto+=1.00;
                Listaproductos.push_back(uPROD);
                break;
            
                case 2:
                uPROD.nombre = "Dona Rellena";
                uPROD.precio = 1.25;
                *tDONAS += 1.25;
                Monto+=1.25;
                Listaproductos.push_back(uPROD);
                break;

                case 3:
                uPROD.nombre = "Moca o Caramelo";
                uPROD.precio = 1.50;
                *tDONAS += 1.50;
                Monto+=1.50;
                Listaproductos.push_back(uPROD);
                break;

                default:
                cout << "Ninguna de las opciones que ha seleccionado es correcta.";
                break;
            }
            ColaDonas.push(uPED);

        }
        cin.ignore();
        cout << "Ingrese su Apellido: "; getline(cin, uPED.Apellido);
        uPED.Lista_comida = Listaproductos;
        cout << "\nEl total del monto comprado por este cliente de de: $" << Monto << endl;

    }
}

void ComprarPlatos(float *tPLATOS)
{
    int cUSU = 0;

    cout << "\nLos precios y disponibilidades de las donas son:\n";
    cout << "1: Desayuno $2.50\n2: Almuerzo $5.00\n3: Cena $3.50\n";
    cout << "\nIngrese la cantidad de platos que desea comprar: "; cin >> cUSU;
    if (cUSU < 0 )
    {
        cout << "\nNo puede adquirir esa cantidad de productos. Regresando al menu anterior.\n";
    }
    else
    {
        Productos uPROD;
        Pedidos uPED;
        float Monto = 0;
        vector<Productos> Listaproductos;
        for (int i = 0; i < cUSU ; i++)
        {
            
            int cPLATOS = 0;
            
            cout << "\nIngrese los platos que desea adquirir una por una que se mostro en el menu de platillos: ";
            cin >> cPLATOS;
            switch (cPLATOS)
            {
                case 1:
                uPROD.nombre = "Desayuno";
                uPROD.precio = 2.50;
                *tPLATOS += 2.50;
                Monto+= 2.50;
                Listaproductos.push_back(uPROD);
                break;
            
                case 2:
                uPROD.nombre = "Almuerzo";
                uPROD.precio = 5.00;
                *tPLATOS += 5.00;
                Monto+=5.00;
                Listaproductos.push_back(uPROD);
                break;

                case 3:
                uPROD.nombre = "Cena";
                uPROD.precio = 3.50;
                *tPLATOS += 3.50;
                Monto+=3.50;
                Listaproductos.push_back(uPROD);
                break;

                default:
                cout << "Ninguna de las opciones que ha seleccionado es correcta.";
                break;
            }
            ColaPlatos.push(uPED);

        }
        cin.ignore();
        cout << "Ingrese su Apellido: "; getline(cin, uPED.Apellido);
        uPED.Lista_comida = Listaproductos;
        cout << "\nEl total del monto comprado por este cliente de de: $" << Monto << endl;
    }
}