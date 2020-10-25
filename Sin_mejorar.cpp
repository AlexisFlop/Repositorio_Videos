#include <iostream>
#include <string>
using namespace std;

//Nodos de cola
struct nodo
{
    string a;
    int b = 0;
    char c;
    struct nodo *Next;
};
typedef struct nodo Nodo;

//Cola
struct cola
{
    Nodo *Front;
    Nodo *Back;
};
typedef struct cola Cola;

/*------- Prototipos de funciones -------*/

//Funciones de la cola
void Inicializar(Cola*);
void Push(Cola*, string, int, char);
void Pop(Cola*);
void Front(Cola*);
void Back(Cola*);
void ShowQ(Cola*);
bool Empty(Cola*);
int Size(Cola*);

//Funciones del programa
void IngresarDatos(Cola*);
void BorrarDato(Cola*);
void MostrarDatos(Cola*);

//Main
int main()
{
    Cola C1;
    Inicializar(&C1);

    int uOPCION = 0;
    bool uBANDERA = true;

    do
    {
        cout << "\nMenu para molde de colas" << endl;
        cout << "1: Ingresar datos\n2: Borrar datos del frente \n3: Mostrar datos\n4: Mostrar frente";
        cout << "\n5: Mostrar Final\n6: Salir del programa\n";
        cout << "Ingrese la opcion a la que desea acceder: "; cin >> uOPCION;

        switch (uOPCION)
        {
        case 1:
        IngresarDatos(&C1);
        break;

        case 2:
        BorrarDato(&C1);
        break;

        case 3:
        MostrarDatos(&C1);
        break;

        case 4:
        Front(&C1);
        break;

        case 5:
        Back(&C1);
        break;

        case 6:
        cout << "\nHa decidido salir del programa\n";
        uBANDERA = false;
        break;

        default:
        cout << "Ninguna de las opciones que ha seleccionado es valida, vuelva a intentarlo.\n";
        break;
        }
    }while(uBANDERA);

    return 0;
}

//Funciones de cola
void Inicializar(Cola *C)
{
    C->Back = NULL;
    C->Front = NULL;
}

bool Empty (Cola *C)
{
    bool vacio = (C->Back == NULL);
    return vacio;

}

int Size(Cola *C)
{
    int Count = 0;
    Nodo *aux = C->Front;
    if (Empty(C))
    {
        return 0;
    }
    else
    {  
        while (aux)
        {
            aux = aux->Next;
            Count++;
        }
        return Count++;
    }
}

void Push(Cola *C, string AC, int AB, char AD)
{
    Nodo *newNodo;
    newNodo = new Nodo;
    newNodo->a = AC;
    newNodo->b = AB;
    newNodo->c = AD;
    newNodo->Next = NULL;

    if(C->Back == NULL)
    {
        C->Front = newNodo;
    }
    else
    {
        (C->Back)->Next = newNodo;
    }

    C->Back = newNodo;
}



void Pop (Cola *C)
{
    if (Empty(C))
    {
        cout << "Underflow\n";
        return;
    }

    Nodo *aux = C->Front;
    C->Front = aux->Next;

    if (C->Front == NULL)
    {
        C->Back = NULL;
    }
    delete(aux);
}

void Front(Cola *C)
{
    Nodo *aux = C->Front;
    if (Empty(C))
    {
        cout << "\nLa cola esta vacia\n";
    }
    else 
    {
        cout << "\nEl string del frente es : " << aux->a << endl;
        cout << "El entero del frente es : " << aux->b << endl;
        cout << "El char del frente es: " << aux->c << endl << endl; 
        
    }
}

void Back(Cola *C)
{
    Nodo *aux = C->Back;
    if (Empty(C))
    {
        cout << "\nLa cola esta vacia\n";
    }
    else 
    {
        cout << "\nEl string del final es : " << aux->a << endl;
        cout << "El entero del final es : " << aux->b << endl;
        cout << "El char del final es: " << aux->c << endl << endl; 
        
    }
}

void ShowQ(Cola *C)
{
    Nodo *aux = C->Front;
    if (Empty(C))
    {
        cout << "\nLa cola esta vacia\n";
    }
    else 
    {
        int i = 0;
        while (aux)
        {
            cout << "\nEl string " << i+1 << " es : " << aux->a << endl;
            cout << "El entero " << i+1 << " es : " << aux->b << endl;
            cout << "El char " << i+1 << " es: " << aux->c << endl; 
            i++;
            aux = aux->Next;
        }
    }
}

//Funciones del programa
void IngresarDatos(Cola *C)
{
    int uDATOS = 0;
    cout << "Ingrese la cantidad de datos que desea ingresar: "; cin >> uDATOS;
    if (uDATOS <= 0)
    {
        cout << "\nNo se pueden ingresar la cantidad de datos que ha seleccionado.\nRegresando al menu...\n";
        return;
    }

    string q;
    int w = 0;
    char e;
    for (int i = 0 ; i < uDATOS ; i++)
    {

        cin.ignore();
        cout << "\nDigite el string que desea ingresar: "; cin >> q;
        cout << "Digite el entero que desea ingresar: "; cin >> w;
        cin.ignore();
        cout << "Digite el char que desea ingresar: "; cin >> e;
        Push(C, q, w, e);
    }
}

void BorrarDato(Cola *C)
{
    int uVALOR = 0;
    cout << "\nIngrese cuantos datos desea retirar de su cola: "; cin >> uVALOR;
    if (uVALOR > Size(C) || uVALOR < 0)
    {
        cout << "El valor que ha introducido no es valido para realizar esta operacion.\n";
        cout << "Ingrese un valor menor o igual a: " << Size(C) << endl; 
    }
    else
    {
        for (int i = 0 ; i < uVALOR ; i++)
        {
            Pop(C);
        } 
        cout << "\nLos datos se han borrado correctamente.\n";
    }
}

void MostrarDatos(Cola *C)
{
    cout << "\nMostrando los datos...\n";
    ShowQ(C);
}