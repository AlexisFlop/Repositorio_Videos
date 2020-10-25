#include <iostream>

using namespace std;

//Declaracion previa de funciones
void CalcularHN();
void CalcularNE();



int main()
{
    //Variables para determinar la opcion que elije el usuario
    int uOPCION = 0;
    bool uBANDERA = true;
    cout << "Programa para calcular los elementos de una sucesion.\n";

    //Ciclo para mostrar un menu al usuario mientras no decida salir de este
    do
    {
        //Opciones del menu
        cout << "1: Calcular hasta N elemento\n2: Calular N elemento\n3: Salir del programa\n";
        //El usuario ingresa que opcion desea escojer
        cout << "Ingrese la opcion a la que desea acceder: "; cin >> uOPCION;

        //Situaciones que se llevara a cabo dependiendo de el numero que ingrese el usuario
        switch(uOPCION)
        {
            case 1:
            //En caso de elegir la opcion 1, se llamara a la funcion CalcularHN
            CalcularHN();
            break;
            case 2:
            //En caso de elegir la opcion 2, se llamara a la funcion CalcularNE
            CalcularNE();
            break;
            case 3:
            //En caso de elegir la opcion 3, se saldra del programa
            cout << "Ha decidido salir del programa.\n";
            uBANDERA = false;
            break;
            default:
            //En caso de no elegir ninguna de las anteriores, se volvera a mostrar el menu
            cout << "La opcion que ha seleccionado no es valida, vuelva a intentarlo\n";
            break;
        }
    }while(uBANDERA);
    return 0;
}

//Funcionar para calcular hasta N elemento de la sucesion
void CalcularHN()
{
    //Variable para que el usuario escoja hasta que elemento de la secesion desea conocer
    int cOPCION = 0;
    cout << "Elija hasta que elemento de la sucesion  desea calcular: ";
    //bloque de codigo
    oLINE:
    //ingresar n elemento
    cin >> cOPCION;
    //Si el valor es menor que 0 no calculara ningun numero de la sucesion
    if (cOPCION < 0)
    {
        cout << "No puede ingresar el calculo de terminos en la sucesion menores a 0, vuelva a intentarlo: ";
        goto oLINE;
    }

    //Declaracion de A0
    float A0 = 1.5;

    //Ciclo que realiza las operaciones para avanzar en la susecion
    for (int i = 0; i < cOPCION; i++)
    {
        //Muestra A0*2
        cout << "Asub-" << i+1 << ": " << A0*2 << endl;

        //Multiplica A0*2 y lo almacena en el valor de la varibale
        A0*=2; 
    } 
}

//Funcion para calcular el elemento N de la sucesion
void CalcularNE()
{
    //opcion para que el usuario elija que elemento de la sucesion desea conocer
    int caOPCION = 0;
    cout << "Elija que elemento de la susecion desea determinar: ";
    oaLINE:
    cin >> caOPCION;

    //Si el valor es menor que 0, le dira que no se pueden calcular dichos terminos de la sucesion y regresara a que se ingrese el valor
    if (caOPCION < 0)
    {
        cout << "\nNo puede ingresar el calculo de terminos en la sucesion menores a 0, vuelva a intentarlo: ";
        goto oaLINE;
    }
    
    //Declaracion del valor A0
    float AA0 = 1.5;
    
    //Si el valor de caOPCION es igual a 0, mostrar el valor A0 de la sucesion
    if ( caOPCION == 0)
    {
        cout << "El termino Sub 0 de la sucesion es: " << AA0;
    }
    else
    {
        //Si el valor de caOPCION es mayor que 0, realizara este ciclo que multiplicara el valor de cada elemento de la
        //sucesion x2 para determinar ese termino
        for (int j = 0 ; j < caOPCION; j++)
        {
            AA0*=2;
        }
        //Mostrara el valor N de la sucesion, el cual fue solicitado por el usuario.
        cout << "El termino " << caOPCION << " de la sucesion es: " << AA0 << endl;
    }
}