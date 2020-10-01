#include <iostream>
#include <stack>

using namespace std;

void AgregarNCapas();
void EliminarCapa();
void EliminarCapas();
void CalcularPromedio();

struct Capas
{
    string TipoDeSuelo;
    float Grosor = 0;
    int Dureza = 0;
};

typedef struct Capas uCAPAS;

stack <uCAPAS> LITO;
stack <uCAPAS> RESPALDO;

int main()
{
    int uOPCION = 0;
    bool uBANDERA = true;
    cout << "Bienvenido al programa para agregar capas de suelo" <<  endl;
    do
    {
        cout << "1: Agregar capas de suelo.\n2: Eliminar capas de suelo.\n3: Eliminar todas las capas.\n4: Calcular promedio de dureza.\n5: Salir del programa.";
        cout << "\nElija la accion que desa realizar: "; cin >> uOPCION;
        switch (uOPCION)
        {
            case 1:
            cin.ignore();
            AgregarNCapas();
            break;
            case 2:
            EliminarCapa();
            break;
            case 3:
            EliminarCapas();
            break;
            case 4:
            CalcularPromedio();
            break;
            case 5:
            cout << "\nHa decidido salir del programa\n";
            uBANDERA = false;
            default:
            cout << "\nNinguna de las opciones que ha ingresado es valida, vuelva a intentarlo.\n";
            break;
        }
    }while(uBANDERA);
}

void AgregarNCapas()
{
    int nVECES = 0;
    uCAPAS CAP;
    cout << "\nIngrese cuantas capas de suelo desea agregar: "; lINGRESAR: cin >> nVECES;
    if (nVECES < 0)
    {
        cout << "No se pueden agregar la cantidad de capas que ha ingresado, vuelva a intentarlo: ";
        goto lINGRESAR;
    }
    else
    {
        for (int i = 0; i < nVECES ; i++)
        {
            cin.ignore();
            cout << "Ingrese el tipo de la capa de suelo: "; getline(cin, CAP.TipoDeSuelo);
            gLINE:
            cout << "Ingrese el grosor de la capa de suelo en metros: "; cin >> CAP.Grosor;
            if (CAP.Grosor < 0)
            {
                cout << "No puede ingresar un grosor menor que 0.\n";
                goto gLINE;
            }
            dLINE:
            cout << "Ingrese la dureza de la capa de suelo: "; cin >> CAP.Dureza;
            if (CAP.Dureza < 0)
            {
                cout << "No puede ingresar un grosor menor que 0.\n";
                goto dLINE;
            }

            LITO.push(CAP);
        }   
    }
    cout << "Se han agregado las capas correctamente, regresando al menu...\n";
}

void EliminarCapa()
{
    cout << "Ha seleccionado la opción eliminar capa, aguarde mientras se realiza el proceso...\n";
    LITO.pop();
    cout << "La capa se ha eliminado correctamente.\n";
}

void EliminarCapas()
{
    cout << "Ha seleccionado eliminar todas las capas, espere mientras se realiza el proceso...\n";
    for (int i = 0; i < LITO.size() ; i++)
    {
        LITO.pop();
    }
    cout << "Todas la capas se han eliminado correctamente.\n";
}

void CalcularPromedio()
{
    cout << "\nHa decidido calcular el promedio de dureza del piso...";
    float PROMEDIO = 0;
    int DURO = 0;
    int tamano = LITO.size();
    for (int i = 0 ; i < tamano ; i++)
    {
        uCAPAS Calcular = LITO.top();
        RESPALDO.push(Calcular);
        DURO += Calcular.Dureza;
        LITO.pop();
    }
    PROMEDIO = DURO/tamano;
    for (int j = 0 ; j < tamano ; j++)
    {
        uCAPAS Doble = RESPALDO.top();
        LITO.push(Doble);
        RESPALDO.pop();
    }
    cout << "\nEl promedio de dureza de su Perfil Litologico es de: " << PROMEDIO <<  endl;
}