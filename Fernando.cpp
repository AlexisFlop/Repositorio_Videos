#include <iostream>
#include <string>
using namespace std;

//Nodos de cola
struct node{
    string a;
    int b = 0;
    char c;
    struct node *Next;
};
typedef struct node Node;

struct queue{
    Node *front;
    Node *back;
};
typedef struct queue Queue;

//Funciones de la cola
void initialize(Queue *C){
    C->back = NULL;
    C->front = NULL;
}

void push(Queue *C, string AC, int AB, char AD){
    Node *newNodo;
    newNodo = new Node;
    newNodo->a = AC;
    newNodo->b = AB;
    newNodo->c = AD;
    newNodo->Next = NULL;

    if(C->back == NULL){
        C->front = newNodo;
    }
    else{
        (C->back)->Next = newNodo;
    }
    
    C->back = newNodo;
}

bool empty (Queue *C){
    return (C->front == NULL) ? true : false;
}

void pop (Queue *C){
    if (empty(C)){
        cout << endl << "Underflow" << endl;
        return;
    }

    Node *aux = C->front;
    C->front = aux->Next;

    if (C->front == NULL){
        C->back = NULL;
    }
    delete(aux);
}

void showQ(Queue *C){
    Node *aux = C->front;
    if (empty(C)){
        cout << endl << "La cola esta vacia" << endl;
    }else{
        int i = 1;
        while (aux){
            cout << endl << "El string " << i << " es : " << aux->a << endl;
            cout << "El entero " << i << " es : " << aux->b << endl;
            cout << "El char " << i << " es: " << aux->c << endl; 
            i++;
            aux = aux->Next;
        }
    }
}

int size(Queue *C){
    int contador = 0;
    Node *aux = C->front;
    if (empty(C)){
        return 0;
    }else{  
        while (aux){
            aux = aux->Next;
            contador++;
        }
        return contador++;
    }
}

void front(Queue *C){
    Node *aux = C->front;
    if (empty(C)){
        cout << endl << "La cola esta vacia" << endl;
    }else{
        cout << endl << "El string del frente es : " << aux->a << endl;
        cout << "El entero del frente es : " << aux->b << endl;
        cout << "El char del frente es: " << aux->c << endl << endl;      
    }
}

void back(Queue *C){
    Node *aux = C->back;
    if (empty(C)){
        cout << endl << "La cola esta vacia" << endl;
    }else{
        cout << endl << "El string del final es : " << aux->a << endl;
        cout << "El entero del final es : " << aux->b << endl;
        cout << "El char del final es: " << aux->c << endl << endl; 
        
    }
}

//Prototipos de funciones
void ingresarDatos(Queue*);
void borrarDato(Queue*);
void mostrarDatos(Queue*);

//main
int main(){
    Queue C1;
    initialize(&C1);

    int opcion = 0;
    bool condicion = true;

    do{
        cout << endl << "Menu para molde de colas" << endl;
        cout << "1: Ingresar datos" << endl;
        cout << "2: Borrar datos del frente " << endl;
        cout << "3: Mostrar datos" << endl;
        cout << "4: Mostrar frente" << endl;
        cout << "5: Mostrar Final" << endl;
        cout << "6: Salir del programa" << endl;
        cout << "Ingrese la opcion a la que desea acceder: ";cin >> opcion;

        switch (opcion){
        case 1: ingresarDatos(&C1); break;
        case 2: borrarDato(&C1); break;
        case 3: showQ(&C1); break;
        case 4: front(&C1); break;
        case 5: back(&C1); break;
        case 6: cout << endl << "Ha decidido salir del programa" << endl; condicion = false; break;
        default: cout << "Ninguna de las opciones que ha seleccionado es valida, vuelva a intentarlo." << endl; break;
        }
    }while(condicion);
    return 0;
}

//Funciones
void ingresarDatos(Queue *C){
    int m = 0;
    nName:
    cout << "Ingrese la cantidad de datos que desea ingresar: "; cin >> m;
    if (m < 0){
        cout << endl << "No se pueden ingresar la cantidad de datos que ha seleccionado, vuelva a intentarlo." <<  endl;
        cout << "Si no desea ingresar ningun dato, digite '0'" << endl << endl;
        goto nName;
    }

    string q;
    int w = 0;
    char e;
    for (int i = 0 ; i < m ; i++){
        cin.ignore();
        cout << endl << "Digite el string que desea ingresar: "; getline(cin, q);
        cout << "Digite el entero que desea ingresar: "; cin >> w;
        cin.ignore();
        cout << "Digite el char que desea ingresar: "; cin >> e;
        push(C, q, w, e);
    }
}

void borrarDato(Queue *C){
    int cantidadBorrar = 0;
    nLINE:
    cout << endl << "Ingrese cuantos datos desea retirar de su cola: "; cin >> cantidadBorrar;
    if (cantidadBorrar > size(C) || cantidadBorrar < 0){
        cout << "El valor que ha introducido no es valido para realizar esta operacion." << endl;
        cout << "Ingrese un valor menor o igual a: " << size(C) << endl;
        cout << "Si la cola esta vacia ingrese  '0' para regresar al menu" << endl;
        goto nLINE;
    }
    
    for (int i = 0 ; i < cantidadBorrar ; i++){
        pop(C);
    } 
    cout << endl << "Los datos se han borrado correctamente." << endl;   
}