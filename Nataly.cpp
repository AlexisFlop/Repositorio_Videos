/*--------------------------Pila desde 0--------------------------*/
#include <iostream>
#include <string>
using namespace std;

//Nodos de cola
struct Nodo{
    string a;
    int b = 0;
    char c;
    struct Nodo *siguiente;
};
typedef struct Nodo nodo;

struct Cola{
    nodo *front;
    nodo *back;
};
typedef struct Cola cola;

//Funciones de la cola
void inicializar(cola *C){
    C->back = NULL;
    C->front = NULL;
}

void push(cola *C, string AC, int AB, char AD){
    nodo *newNodo;
    newNodo = new nodo;
    newNodo->a = AC;
    newNodo->b = AB;
    newNodo->c = AD;
    newNodo->siguiente = NULL;

    if(C->back == NULL){
        C->front = newNodo;
    }
    else{
        (C->back)->siguiente = newNodo;
    }

    C->back = newNodo;
}

bool empty (cola *C){
    return (C->front == NULL) ? true : false;
}

void pop (cola *C){
    if (empty(C)){
        cout << "Underflow\n";
        return;
    }

    nodo *aux = C->front;
    C->front = aux->siguiente;

    if (C->front == NULL){
        C->back = NULL;
    }
    delete(aux);
}

void showQ(cola *C){
    nodo *aux = C->front;
    if (empty(C)){
        cout << "\nLa cola esta vacia\n";
    }else{
        int i = 0;
        while (aux){
            cout << "\nEl string " << i+1 << " es : " << aux->a << endl;
            cout << "El entero " << i+1 << " es : " << aux->b << endl;
            cout << "El char " << i+1 << " es: " << aux->c << endl; 
            i++;
            aux = aux->siguiente;
        }
    }
}

int size(cola *C){
    int contador = 0;
    nodo *aux = C->front;
    if (empty(C)){
        return 0;
    }else{  
        while (aux){
            aux = aux->siguiente;
            contador++;
        }
        return contador++;
    }
}

void front(cola *C){
    nodo *aux = C->front;
    if (empty(C)){
        cout << "\nLa cola esta vacia\n";
    }else{
        cout << "\nEl string del frente es : " << aux->a << endl;
        cout << "El entero del frente es : " << aux->b << endl;
        cout << "El char del frente es: " << aux->c << endl << endl; 
        
    }
}

void back(cola *C){
    nodo *aux = C->back;
    if (empty(C)){
        cout << "\nLa cola esta vacia\n";
    }else{
        cout << "\nEl string del final es : " << aux->a << endl;
        cout << "El entero del final es : " << aux->b << endl;
        cout << "El char del final es: " << aux->c << endl << endl; 
        
    }
}

//Prototipos de funciones
void ingresarDatos(cola*);
void borrarDato(cola*);
void mostrarDatos(cola*);

//main
int main(){
    cola C1;
    inicializar(&C1);

    int opcion = 0;
    bool condicion = true;

    do{
        cout << "\nMenu para molde de colas" << endl;
        cout << "1: Ingresar datos\n2: Borrar datos del frente \n3: Mostrar datos\n4: Mostrar frente";
        cout << "\n5: Mostrar Final\n6: Salir del programa\n";
        cout << "Ingrese la opcion a la que desea acceder: "; 
        cin >> opcion;

        switch (opcion){
        case 1:
        ingresarDatos(&C1);
        break;
        case 2:
        borrarDato(&C1);
        break;
        case 3:
        mostrarDatos(&C1);
        break;
        case 4:
        front(&C1);
        break;
        case 5:
        back(&C1);
        break;
        case 6:
        cout << "\nHa decidido salir del programa\n";
        condicion = false;
        break;
        default:
        cout << "Ninguna de las opciones que ha seleccionado es valida, vuelva a intentarlo.\n";
        break;
        }
    }while(condicion);
    return 0;
}

//Funciones
void ingresarDatos(cola *C){
    int cantidadDatos = 0;
    cout << "Ingrese la cantidad de datos que desea ingresar: "; 
    cin >> cantidadDatos;
    if (cantidadDatos <= 0){
        cout << "\nNo se pueden ingresar la cantidad de datos que ha seleccionado.\nRegresando al menu...\n";
    }else{
        string q;
        int w = 0;
        char e;
        for (int i = 0 ; i < cantidadDatos ; i++){
        cin.ignore();
        cout << "\nDigite el string que desea ingresar: "; 
        getline(cin, q);
        cout << "Digite el entero que desea ingresar: "; 
        cin >> w;
        cin.ignore();
        cout << "Digite el char que desea ingresar: "; 
        cin >> e;
        push(C, q, w, e);
        }
    }

}

void mostrarDatos(cola *C){
    cout << "\nMostrando los datos...\n";
    showQ(C);
}

void borrarDato(cola *C){
    int cantidadBorrar = 0;
    cout << "\nIngrese cuantos datos desea retirar de su cola: "; 
    cin >> cantidadBorrar;
    if (cantidadBorrar > size(C) || cantidadBorrar < 0){
        cout << "El valor que ha introducido no es valido para realizar esta operacion.\n";
        cout << "Ingrese un valor menor o igual a: " << size(C) << endl; 
    }else{
        for (int i = 0 ; i < cantidadBorrar ; i++){
            pop(C);
        } 
        cout << "\nLos datos se han borrado correctamente.\n";
    }
}