#include <iostream>

using namespace std;

void OPCION1();
void OPCION2();
void OPCION3();

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
                OPCION1();
                break;
            case 2:
                OPCION2();
                break;
            case 3:
                OPCION3();
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

void OPCION1()
{
   int uOPCION1 = 0;
   bool uFLAG1 = true;
   
   cout << "\nEstas en el menu de la funcion OPCION1\n";

   do
   {
       cout << "\n1: Ingresar a la opcion 1\n2: Ingresar a la opcion 2\n3: Ingresar a la opcion 3\n4: Salir del programa\n";
       cout << "Por favor ingrese a la opcion a la que desea acceder: "; cin >> uOPCION1;
       switch (uOPCION1)
       {
            case 1:
                cout << "\nHa ingresado a la opcion 1\n";
                break;
            case 2:
                cout << "\nHa ingresado a la opcion 2\n";
                break;
            case 3:
                cout << "\nHa ingresado a la opcion 3\n";
                break;
            case 4:
                cout << "\nHa decidido salir del menu, regresando al menu principal...\n";
                uFLAG1 = false;
            default:
                cout << "\nNinguna de las opciones que ha seleccionado es valida.\n";
                break;
       }
   } while (uFLAG1);
}

void OPCION2()
{

}

void OPCION3()
{
    
}