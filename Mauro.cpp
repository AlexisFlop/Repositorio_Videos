#include <iostream>
#include <string>
using namespace std;

//Nodos de cola
struct Nodo{
    string a;
    int b = 0;
    char c;
    struct Nodo *Siguiente;
};
typedef struct Nodo nodo;

struct Cola{
    nodo *Inicio;
    nodo *Final;
};
typedef struct Cola cola;

//Funciones de la cola

void Inicializar(cola *C){
    C->Final = NULL;
    C->Inicio = NULL;
}

void Push(cola *C,string AC,int AB,char AD){
    nodo *newNodo;
    newNodo = new nodo;
    newNodo->a = AC;
    newNodo->b = AB;
    newNodo->c = AD;
    newNodo->Siguiente = NULL;

    if(C->Final == NULL){
        C->Inicio = newNodo;
    }
    else{
        (C->Final)->Siguiente = newNodo;
    }

    C->Final = newNodo;
}

bool Empty (cola *C){
    return (C->Inicio == NULL) ? true : false;
}

void Pop (cola *C){
    if (Empty(C)){
        cout << "Underflow\n";
        return;
    }

    nodo *aux = C->Inicio;
    C->Inicio = aux->Siguiente;

    if (C->Inicio == NULL){
        C->Final = NULL;
    }
    delete(aux);
}

void MostrarCola(cola *C){
    nodo *aux = C->Inicio;
    if (Empty(C)){
        cout << "\nLa cola esta vacia\n";
    }else{
        int i = 0;
        while (aux){
            cout << "\nEl string " << i+1 << " es : " << aux->a << endl;
            cout << "El entero " << i+1 << " es : " << aux->b << endl;
            cout << "El char " << i+1 << " es: " << aux->c << endl; 
            i++;
            aux = aux->Siguiente;
        }
    }
}

int Size(cola *C){
    int contador = 0;
    nodo *aux = C->Inicio;
    if (Empty(C)){
        return 0;
    }else{  
        while (aux){
            aux = aux->Siguiente;
            contador++;
        }
        return contador++;
    }
}

void Front(cola *C){
    nodo *aux = C->Inicio;
    if (Empty(C)){
        cout << "\nLa cola esta vacia\n";
    }else{
        cout << "\nEl string del frente es : " << aux->a << endl;
        cout << "El entero del frente es : " << aux->b << endl;
        cout << "El char del frente es: " << aux->c << endl << endl; 
        
    }
}

void Back(cola *C){
    nodo *aux = C->Final;
    if (Empty(C)){
        cout << "\nLa cola esta vacia\n";
    }else{
        cout << "\nEl string del final es : " << aux->a << endl;
        cout << "El entero del final es : " << aux->b << endl;
        cout << "El char del final es: " << aux->c << endl << endl; 
        
    }
}

//prototipos de funciones
void IngresarDatos(cola*);
void BorrarDato(cola*);
void MostrarDatos(cola*);

//main
int main(){
    cola C1;
    Inicializar(&C1);
    int n = 0;
    bool bandera = true;

    do
    {
        cout << "\nBienvenido al prpgrama - Menu para molde de colas" << endl;
        cout << "1: Ingresar datos\n2: Borrar datos del frente \n3: Mostrar datos\n4: Mostrar frente";
        cout << "\n5: Mostrar Final\n6: Salir del programa\n";
        cout << "Ingrese la opcion a la que desea acceder: "; 
        cin >> n;

        switch (n){
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
        bandera = false;
        break;
        default:
        cout << "Ninguna de las opciones que ha seleccionado es valida, vuelva a intentarlo.\n";
        break;
        }
    }while(bandera);
    return 0;
}

//Funciones


void IngresarDatos(cola *C){
    int cd = 0;
    cout << "Ingrese la cantidad de datos que desea ingresar: "; 
    cin >> cd;
    if (cd <= 0){
        cout << "\nNo se pueden ingresar la cantidad de datos que ha seleccionado.\nRegresando al menu...\n";
        return;
    }

    string q;
    int w = 0;
    char e;

    for (int i = 0 ; i < cd ; i++)
    {
        cin.ignore();
        cout << "\nDigite el string que desea ingresar: "; 
        getline(cin,q);
        cout << "Digite el entero que desea ingresar: "; 
        cin >> w;
        cin.ignore();
        cout << "Digite el char que desea ingresar: "; 
        cin >> e;
        Push(C,q,w,e);
    }
}

void MostrarDatos(cola *C){
    cout << "\nMostrando los datos...\n";
    MostrarCola(C);
}

void BorrarDato(cola *C){
    int cb = 0;
    cout << "\nIngrese cuantos datos desea retirar de su cola: "; 
    cin >> cb;
    if (cb > Size(C) || cb < 0){
        cout << "El valor que ha introducido no es valido para realizar esta operacion.\n";
        cout << "Ingrese un valor menor o igual a: " << Size(C) << endl; 
    }else{
        for (int i = 0 ; i < cb ; i++)
        {
            Pop(C);
        } 
        cout << "\nLos datos se han borrado correctamente.\n";
    }
}