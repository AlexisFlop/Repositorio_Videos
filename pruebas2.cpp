#include <iostream>
#include <stack>
#include <string>
#include "funciones.hpp"

using namespace std;



int main()
{
    int n;
    fLINE:
    cout << "Ingrese el tamaño que desea darle a sus arreglos: "; cin >> n;
    if(n < 0 )
    {
        cout << "Este valor no puede ser ingresado para el tamaño de sus arreglos, ingrese otro numero\n";
        goto fLINE;
    }

    int pARREGLO[n], sARREGLO[n];

    cout << "Ingrese los datos que desea agregar al primer arreglo..." << endl;
    Llenar1(pARREGLO, n);

    cout << "Ingrese los datos que desea agregar al segundo arreglo..." << endl;
    Llenar2(sARREGLO, n);

    cout << "A continuacion se realizara el producto de los numeros del arreglo..." <<  endl;
    for (int i = 0; i < n; i++)
    {
        int valor = Multiplicar(pARREGLO, sARREGLO, i);
        Agrupar(valor);
    }

    cout << "Productos pares " << endl;
    while(!Pares.empty())
    {
        cout << Pares.top() << endl;
        Pares.pop();
    }    

    cout << "Productos impares " << endl;    
    while(!Impares.empty())
    {
        cout << Impares.top() << endl;
        Impares.pop();
    }
    return 0;
}
