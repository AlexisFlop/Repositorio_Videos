#include <iostream>
#include <string>
#include <queue>

using namespace std;

void uMenu();

void uMenu()
{
    int uOPCION = 0;
    bool uBANDERA = true;
    do
    {
        cout << "\n1: Ingresar datos a la cola.\n2: Borrar primer dato de la cola\n3: Salir del programa.\n";
        cout << "\nIngrese la opcion a la que desea acceder: "; cin >> uOPCION;
        switch (uOPCION)
        {
            case 1:

                break;
            case 2:
                
                break;
            case 3:
                cout << "\nHa decidido salir del programa.\n";
                uBANDERA = false;
                break;
            default:
                cout << "\nNinguna de las opciones que ha ingresado es valida.\n";
                break;
        }
    } while (uBANDERA);
}