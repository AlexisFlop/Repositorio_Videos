#include <iostream>
#include "Cabecera.hpp"

using namespace std;

int main()
{
    int uNUM = 0, uNUM2 = 0, uNUM3 = 0;

    fLINE:
    cout << "\nIngrese el valor de la variable 1: "; cin >> uNUM;
    cout << "Ingrese el valor de la variable 2: "; cin >> uNUM2;
    cout << "Ingrese el valor de la variable 3: "; cin >> uNUM3;

    if (uNUM <= 0 || uNUM2 <= 0 || uNUM3 <= 0)
    {
        cout << "\nUno de los valores que ha ingresado no puede procesarse, ingrese nuevamente todos los datos\n";
        cout << "con numeros mayores que 0\n";
        goto fLINE;
    }

    int rSUMA = Suma(uNUM, uNUM2);
    int rRESTA = Resta(uNUM2, uNUM3);

    cout << "\nEL valor de rSUMA es: " << rSUMA;
    cout << "\nEl valor de rRESTA es: " << rRESTA;
    return 0;
}