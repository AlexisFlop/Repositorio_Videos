#include <iostream>
#include <string>

using namespace std;
 

 /*
Perdon Ingeniero, no pude continuar con pilas desde 0, queria usar el codigo de Henry Banchon pero no pude continuar
ya que me confundi en las varibales que se usaron para apuntar a otros lados de las estructuras, quiero llorar,
ya no se que hacer con mi vida, si puede dar un refuerzo con pilas de 0 explicadas con manzana le agradeceria demasiado
porque si estoy medio maje para hacer pilas desde 0
 */
void AgregarPlatos();
void EnsuciarPlato();
void EnsuciarNPlatos();
void LimpiarPlato();
void LimpiarNPlatos();
void MostrarLimpios();
void MostrarSucios();


struct Node {
    string Material, Color;
    bool Estado = true;
    struct Node *next;
    struct Node *nextCol;
    struct Node *nextEST;
};
typedef struct Node *Stack;

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, string Material, string Color) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

void pop(Stack *s) {
    if (!empty(s)) {
        struct Node *aux = *s;
        s = (s)->next;
        delete(aux);
    }else {
        return;
    }
}

void showStack(Stack *s) {
    struct Node *clone = *s;
    bool isEmpty = false;
    while (!isEmpty) {
        if (!empty(&clone))
        {
            cout << clone->element << " ";
            clone = clone->next;
        }else {
            isEmpty = true;
        }
    }
}
//------------------------------------------------------------------------------------------------------------------//
// Pila de platos Sucios//

struct Node1 {
    string Material1, Color1;
    bool Estado1 = false;
    struct Node1 *next1;
};
typedef struct Node1 *Stack1;

bool empty1(Stack1 *s1) {
    return *s1 == NULL;
}

void push1(Stack1 *s1, int e1) {
    struct Node1 *node1;
    node1 = (struct Node1 *)malloc(sizeof(struct Node1));
    node1->element1 = e1;
    node1->next1 = *s1;

    *s1 = node1;
}

void pop1(Stack1 *s1) {
    if (!empty1(s1)) {
        struct Node1 *aux1 = *s1;
        s1 = (s1)->next1;
        delete(aux1);
    }else {
        return;
    }
}

void showStack1(Stack1 *s1) {
    struct Node1 *clone1 = *s1;
    bool isEmpty1 = false;
    while (!isEmpty1) {
        if (!empty1(&clone))
        {
            cout << clone->element1 << " ";
            clone = clone->next1;
        }else {
            isEmpty1 = true;
        }
    }
}

struct Platos
{
    string Mat, Col;
    bool Est = true;
}
typedef struct Platos PLA;

int main()
{
    int uOPCION = 0;
    bool uBANDERA = true;
    Stack stack;
    initiliaze(&stack);
    Stack1 stack1;
    initiliaze(&stack1);

    cout << "Bienvenido al programa para llevar el inventario de platos.\n";
    do
    {
        cout << "1: Agregar platos\n2: Ensuciar un plato\n3: Ensuciar N platos\n4: Limpiar un plato\n5: Limpiar N platos\n
        6: Mostrar platos limpios\n 7: Mostrar platos sucios\n8: Salir del programa\n";
        cin >> uOPCION;
        switch(uOPCION)
        {
            case 1:
            AgregarPlatos();
            break;
            case 2:
            EnsuciarPlato();
            break;
            case 3;
            EnsuciarNPlatos();
            break;
            case 4:
            LimpiarPlato();
            break;
            case 5:
            LimpiarNPlatos();
            break;
            case 6:
            MostrarLimpios();
            break;
            case 7:
            MostrarSucios();
            break;
            case 8:
            cout << "Ha decidido salir del programa.\n";
            uBANDERA = false;
            default:
            cout << "Ninguna de las opciones que ha seleccinado es valida, vuelva a intentarlo.\n";
            break;
        }
    }while (uBANDERA);

}

void AgregarPlatos()
{
    PLA plat;
    int nPLATOS = 0;
    cout << "Ingrese cuantos platos quiere agregar a su pila (limpios): "; pLINE: cin >> nPLATOS;
    if ( nPLATOS < 0)
    {
        cout << "\nNo es posible agregar la cantidad de platos que ha ingresdo, vuelva a intentarlo: ";
        goto pLINE;
    }
    for ( int i = 0 ; i < nPLATOS ; i++)
    {
        cin.ignore();
        cout << "Ingrese el material del plato: "; cin >> plat.Mat;
        cout << "Ingrese el color del plato: "; cin.ignore(); cin >> plat.Col;
        plat.Est = true;
        push(s, plat);

    }
}



