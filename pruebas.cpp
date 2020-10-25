#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack <int> pila;
//Prototipos de funciones
void Ingresar();
void Sacar();
void Mostrar();

int main()
{
    int uOPCION;
    bool uBANDERA = true; 

    cout << "\nLa cantidad de elementos actual en la pila es: " << pila.size() << endl << endl;
    do
    {
        fLINE:
        cout << "1: Ingresar datos\n2: Sacar datos\n3: Salir del programa\n";
        cout << "\nIngrese la opcion a la que desea acceder: "; cin >> uOPCION;
        switch (uOPCION)
        {
            case 1:
                Ingresar();
                break;
            case 2:
                Sacar();
                break;
            case 3:
                cout << "\nHa decidido salir del programa." << endl;
                uBANDERA = false; 
                break;
            default:
                cout << "\nLa opcion que ha seleccionado es invalida, por favor ingrese una dentro de los parametros" << endl;
                break;
        }
    }while(uBANDERA);
    Mostrar();
    return 0;
}
//Funcion para ingresar datos 1x1
void Ingresar()
{
    int elemento;
    cout << "\nIntroduzca el elemento que desea ingresar a la pila: ";
    cin >> elemento;
    pila.push(elemento);
    cout << "El nuevo tamaño de su pila es: " << pila.size() << endl;
}
//FUncion para sacar datos 1x1
void Sacar()
{
    if (pila.empty())
    {
        cout << "\nNo se pueden extraer datos, a pila esta vacia\n";
    }
    else
    {
        cout << "\nEl dato que esta extrayendo de la pila es es: " << pila.top() << endl;
        pila.pop();
        cout << "El nuevo tamaño de su pila es: " << pila.size() << endl; 
    }
}
//Funcion para mostrar todos los datos existentes en la pila 
void Mostrar()
{
    cout << "\nLos elementos finales en la pila son: \n";
    while (!pila.empty())
    {
        cout << "[" << pila.top()  << "]" << endl;
        pila.pop();
    }
}