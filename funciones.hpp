#include <iostream>
#include <stack>
#include <string>

using namespace std;


stack <int> Pares;
stack <int> Impares;

void Llenar1(int*, int);
void Llenar2(int*, int);
int Multiplicar(int*, int*, int);
void Agrupar(int);

void Llenar1(int *pARREGLO, int n)
{
    for (int i = 0; i < n ; i++)
    {
        cout << "Ingrese el valor " << i+1 << " del primer arreglo: ";
        cin >> pARREGLO[i];
    }
}

void Llenar2(int *sARREGLO, int n)
{
    for (int i = 0; i < n ; i++)
    {
        cout << "Ingrese el valor " << i+1 << " del segundo arreglo: ";
        cin >> sARREGLO[i];
    }
}

int Multiplicar( int *pARREGLO, int *sARREGLO, int i)
{
    int resultado = pARREGLO[i] * sARREGLO[i];
    return resultado;
}

void Agrupar(int valor)
{
    if (valor%2 == 0)
    {
        Pares.push(valor);
    }
    else
    {
        Impares.push(valor);
    }
}