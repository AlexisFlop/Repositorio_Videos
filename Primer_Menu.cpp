#include <iostream>

using namespace std;

int main()
{
   int uOPCION = 0;
   bool uFLAG = true;

   do
   {
       cout << "\n1: Ingresar a la opcion 1\n2: Ingresar a la opcion 2\n3: Ingresar a la opcion 3\n4: Salir del programa\n";
       cout << "Por favor ingrese a la opcion a la que desea acceder: "; cin >> uOPCION;
       switch (uOPCION)
       {
            case 1:
                cout << "\nHa ingresado a la opcion 1.\n";
                break;
            case 2:
                cout << "\nHa ingresado a la opcion 2\n";
                break;
            case 3:
                cout << "\nHa ingresado a la opcion 3.\n";
                break;
            case 4:
                cout << "\nHa decidido salir del programa\n";
                uFLAG = false;
            default:
                cout << "\nNinguna de las opciones que ha seleccionado es valida.\n";
                break;
       }
   } while (uFLAG);
   return 0;
}
