#include <iostream>
#include <stack>
using namespace std;

//Definiendo estructura Libro, la cual va a componer a la pila
struct Libro {
    string titulo;
    string autor;
    int edicion;
    string categoria;
    int isbn;
};

//Definiendo estructura Revista, la cual va a componer a la pila
struct Revista {
    string titulo;
    string autor;
    int volumen;
    int issue;
    string categoria;
    int issn;
};

//Definiendo estructura Estudiante, la cual va a componer la lista enlazada
struct Estudiante {
    string nombre;
    string apellido;
    int carnet;
    Libro *libro = NULL;
    Revista *revista = NULL; 
    struct Estudiante *sig;
};

//Definiendo la estructura ListaSimple, que contiene un puntero Estudiante
struct ListaSimple {
    Estudiante *inicio;
};
typedef struct ListaSimple Lista;

//Función que inicializa la lista
void inicializar(Lista *listaEstudiantes) {
    listaEstudiantes->inicio = NULL;
}

//Función que verfica si la lista está vacía
bool estaVacia(Lista *listaEstudiantes) {
    return (listaEstudiantes->inicio == NULL) ? true : false;
}

//Función para insertar un nuevo estudiante al inicio de la lista
void insertarInicio(Lista *listaEstudiantes, string nombre, string apellido, int carnet) {
    //Reservando espacio necesario para un registro Estudiante
    Estudiante *nuevo = new Estudiante;

    //Asignando los valores a todos los parametros del registro
    nuevo->nombre = nombre;
    nuevo->apellido = apellido;
    nuevo->carnet = carnet;

    //Dado que este nuevo estudiante se va a insertar al inicio, su puntero siguiente debe igualarse al puntero inicio de la lista
    nuevo->sig = listaEstudiantes->inicio;

    //Se modifica el puntero inicio de la lista al nuevo estudiante para tener la lista enlazada con el nuevo agregado al principio
    listaEstudiantes->inicio = nuevo;
}

void insertarFinal(Lista *listaEstudiantes, string nombre, string apellido, int carnet) {
    //Reservando espacio necesario para un registro Estudiante
    Estudiante *nuevo = new Estudiante;

    //Asignando los valores a todos los parametros del registro
    nuevo->nombre = nombre;
    nuevo->apellido = apellido;
    nuevo->carnet = carnet;

    //Dado que este nuevo estudiante se va a insertar al final, su puntero siguiente debe estar vacío
    nuevo->sig = NULL;

    //Verificamos si el puntero inicio de la lista contiene un elemento
    if(listaEstudiantes->inicio == NULL) {
        //Si no contiene nada, el nuevo estudiante se le asigna al inicio, y de igual manera se convierte en el final de la lista
        listaEstudiantes->inicio = nuevo;
    }else {
        //Crear un puntero estudiante auxiliar que almacene todo lo del puntero inicio de la lista
        Estudiante *p = listaEstudiantes->inicio;
        //Crear un puntero estudiante auxiliar que se inicializa como NULL
        Estudiante *q = NULL;
        //Recorremos la lista por medio del auxiliar p
        while(p) {
            //El puntero auxiliar q toma todo el contenido del puntero auxiliar p
            q = p;
            //Utilizamos el puntero p para movernos en la lista
            p = p->sig;
        }
        //Una vez finalizado el recorrido de la lista, el contenido en q es el ultimo elemento existente en la lista
        //Por lo que asignamos el nuevo estudiante en el puntero sig de q
        q->sig = nuevo;
    }
}

//Función que verifica si el estudiante ya tiene asignado un libro o revista
bool puedeAsignar(Estudiante *estudiante) {
    //Tanto como el libro y revista del estudiante tiene que estar NULL, si uno no es NULL no se puede ingresar otro libro o revista
    if(estudiante->libro == NULL && estudiante->revista == NULL) {
        return true;
    }else {
        return false;
    }
}

bool asignarLibro(Lista *listaEstudiantes, int carnet, Libro *libro) {
    //Creación de la bandera asignado que va a retornar la función
    bool asignado = false;

    //Verifico si hay estudiantes en la lista
    if (estaVacia(listaEstudiantes)) {
        cout << "No se puede asignar el libro, no hay estudiantes en la lista" << endl;
        return asignado;
    }else{
        //Bandera booleana que verifica si ya se encontró el estudiante con el carnet deseado
        bool encontrado = false;

        //Creación de un puntero estudiante auxiliar para recorrer la lista
        Estudiante *aux = listaEstudiantes->inicio;

        //Recorrer la lista por medio de un while
        while(aux) {
            //Verifico si el estudiante en la posición actual tiene el mismo carnet que el carnet pedido por el usuario
            if (aux->carnet == carnet) {
                //Modificación de la bandera found a verdadero
                encontrado = true;

                //Verificar si el estudiante ya tiene un libro o revista asignado
                if (!puedeAsignar(aux)) {
                    cout << "No se le pudo asignar el libro al estudiante porque ya tiene otro libro o una revista asignado" << endl;
                    return asignado;
                }else {
                    //Le asigno al estudiante el libro
                    aux->libro = libro;

                    //Modificación de la bandera asignado a verdadero
                    asignado = true;

                    /* El siguiente cout se muestra de la siguiente manera:
                    El libro '<titulo>' de <autor>, Edición <numero_de_edición>. ISBN #<isbn>.
                    Fue asignado al estudiante <nombre> <apellido>, con carnet <carnet>
                    */
                    cout << "El libro '" << aux->libro->titulo << "' de " << aux->libro->autor 
                        << ", Edición " << aux->libro->edicion << ". ISBN #" << aux->libro->isbn << "."
                        << endl;
                    cout << "Fue asignado al estudiante " << aux->nombre << " " << aux->apellido
                        << ", con carnet: " << aux->carnet << endl;
                    return asignado;
                }
            }else {
                //Moviéndose al siguiente elemento
                aux = aux->sig;
            }
        }
        
        //Verificando si el estudiante deseado no estaba en la lista
        if(encontrado == false) {
            cout << "El carnet ingresado no pertenece a ningún estudiante de la lista" << endl;
        }

        return asignado;
    }
}

bool asignarRevista(Lista *listaEstudiantes, int carnet, Revista *revista) {
    //Creación de la bandera asignado que va a retornar la función
    bool asignado = false;

    //Verifico si hay estudiantes en la lista
    if (estaVacia(listaEstudiantes)) {
        cout << "No se puede asignar la revista, no hay estudiantes en la lista" << endl;
        return asignado;
    }else{
        //Bandera booleana que verifica si ya se encontró el estudiante con el carnet deseado
        bool found = false;

        //Creación de un puntero estudiante auxiliar para recorrer la lista
        Estudiante *aux = listaEstudiantes->inicio;

        //Recorrer la lista por medio de un for
        while(aux) {
            //Verifico si el estudiante en la posición actual tiene el mismo carnet que el carnet pedido por el usuario
            if (aux->carnet == carnet) {
                //Modificación de la bandera found a verdadero
                found = true;

                //Verificar si el estudiante ya tiene una revista o libro asignado
                if (!puedeAsignar(aux)) {
                    cout << "No se le pudo asignar el libro al estudiante porque ya tiene otro libro o una revista asignado" << endl;
                    return asignado;
                }else {
                    //Le asigno al estudiante la revista
                    aux->revista = revista;

                    //Modificación de la bandera asignado a verdadero
                    asignado = true;

                    /* El siguiente cout se muestra de la siguiente manera:
                    La revista '<titulo>' de <autor>, (Vol. <numero_volumen>) Issue #<numero_issue>. ISSN #<issn>.
                    Fue asignado al estudiante <nombre> <apellido>, con carnet <carnet>
                    */
                    cout << "La revista '" << aux->revista->titulo << "' de " << aux->revista->autor 
                        << ", (Vol. " << aux->revista->volumen << ") Issue #" << aux->revista->issue
                        << ". ISSN #" << aux->revista->issn << "." << endl;
                    cout << "Fue asignado al estudiante " << aux->nombre << " " << aux->apellido
                        << ", con carnet: " << aux->carnet << endl;
                    return asignado;
                }   
            }else {
                aux = aux->sig;
            }
        }
        
        //Verificando si el estudiante deseado no estaba en la lista
        if(found == false) {
            cout << "El carnet ingresado no pertenece a ningún estudiante de la lista" << endl;
        }

        return asignado;
    }
}

int main() {
    //Inicializando lista
    Lista listaEstudiantes;
    inicializar(&listaEstudiantes);

    //Creando e inicializando la pila de libros y la pila de revistas
    stack<Libro> pilaLibros;
    stack<Revista> pilaRevista;
    //Creando bandera booleana para iterar el while
    bool status = true;

    //Menu por medio de while, verificando variable status por cada iteración
    while(status) {
        //Imprimiendo en consola las opciones del menú
        cout << "********** MENU **********" << endl;
        cout << "1. Ingresar libro a la pila" << endl;
        cout << "2. Ingresar revista a la pila" << endl;
        cout << "3. Ingresar estudiante a la lista" << endl;
        cout << "4. Asignar libro a un estudiante de la lista" << endl;
        cout << "5. Asignar revista a un estudiante de la lista" << endl;
        cout << "6. Salir del programa" << endl;

        //Creación de variable entera que servirá para ejecutar una opción del menú
        int option;

        //Pidiéndole al usuario que ingrese la opción por medio de consola
        cout << "\n" << "Ingrese la opción del menú que desea ejecutar: ";
        cin >> option;
        cin.ignore();

        //Creación de variable de tipo Libro
        Libro libro;

        //Creación de variable de tipo Revista
        Revista revista;

        //Creación de variables string y entera para llenar los campos de un estudiante
        string nombre, apellido;
        int carnet;
        

        //Case para verificar la opción ingresada
        switch (option){
            case 1:
                //Caso en el que se añade un libro a la pila previamente creada

                //Pidiéndole al usuario los datos del libro
                cout << "Ingrese el titulo del libro" << endl;
                getline(cin, libro.titulo);

                cout << "Ingrese el autor del libro" << endl;
                getline(cin, libro.autor);

                cout << "Ingrese el número de edición del libro" << endl;
                cin >> libro.edicion;
                cin.ignore();

                cout << "Ingrese el género del libro" << endl;
                getline(cin, libro.categoria);

                cout << "Ingrese el ISBN del libro" << endl;
                cin >> libro.isbn;

                //Agregando el libro, ya con los datos, a la pila
                pilaLibros.push(libro);
                break;
            case 2:
                //Caso en el que se añade una revista a la pila previamente creada

                //Pidiéndole al usuario los datos de la revista
                cout << "Ingrese el titulo de la revista" << endl;
                getline(cin, revista.titulo);

                cout << "Ingrese el autor de la revista" << endl;
                getline(cin, revista.autor);

                cout << "Ingrese el número de volumen de la revista" << endl;
                cin >> revista.volumen;

                cout << "Ingrese el número de issue de la revista" << endl;
                cin >> revista.issue;
                cin.ignore();

                cout << "Ingrese la categoría de la revista" << endl;
                getline(cin, revista.categoria);

                cout << "Ingrese el ISSN de la revista" << endl;
                cin >> revista.issn;

                //Agregando la revista, ya con los datos, a la pila
                pilaRevista.push(revista);
                break;
            case 3:
                //Caso en el que se añade un estudiante a la lista simple

                //Pidiéndole al usuario la información del estudiante
                cout << "Ingrese el nombre del estudiante" << endl;
                getline(cin, nombre);
                cout << "Ingrese el apellido del estudiante" << endl;
                getline(cin, apellido);
                cout << "Ingrese el carnet del estudiante" << endl;
                cin >> carnet;

                //Creación de un entero que sirva como opción para menú secundario
                int option2;

                //Seleccionar en donde se desea insertar al estudiante en la lista
                cout << "¿Dónde desea insertar al estudiante?" << endl;
                cout << "1. Insertar al inicio" << endl;
                cout << "2. Insertar al final" << endl;
                cin >> option2;

                switch(option2) {
                    case 1:
                        //Insertando al principio de la lista
                        insertarInicio(&listaEstudiantes, nombre, apellido, carnet);
                        break;
                    case 2:
                        //Insertando al final de la lista
                        insertarFinal(&listaEstudiantes, nombre, apellido, carnet);
                        break;
                    default:
                        cout << "Opción no válida" << endl;
                        break;
                }
                break;
            case 4:
                //Caso en el que se le asigna un libro a un estudiante

                //Verificamos que la pila de libros no esté vacía
                if(pilaLibros.empty()){
                    cout << "No se pueden asignar libros, la pila de libros está vacía" << endl;
                }else {
                    //Asigno a una variable libro el libro que se encuentra hasta arriba de la pila
                    Libro libro = pilaLibros.top();

                    //Creando variable entera donde se va a almacenar el carnet del estudiante al que se le desea asignar el libro
                    int carnet;

                    //Pidiéndole el carnet al usuario
                    cout << "Ingrese el carnet del estudiante al que le desea asignar el libro" << endl;
                    cin >> carnet;

                    //Mandando a llamar a la función para asignar, con la lista completa de estudiantes, el carnet deseado y la pila del libro
                    if(asignarLibro(&listaEstudiantes, carnet, &libro)) {
                        //Eliminamos el libro hasta arriba de la pila porque ya fue asignado a un estudiante
                        pilaLibros.pop();
                    }
                }
                break;
            case 5:
                //Caso en el que se le asigna una revista a un estudiante

                //Verificamos que la pila de revistas no esté vacía
                if(pilaRevista.empty()) {
                    cout << "No se pueden asignar revistas, la pila de revista está vacía" << endl;
                }else {
                    //Asigno a una variable *revista la revista que se encuentra hasta arriba de la pila
                    Revista revista = pilaRevista.top();

                    //Creando variable entera donde se va a almacenar el carnet del estudiante al que se le desea asignar el libro
                    int carnet;

                    //Pidiéndole el carnet al usuario
                    cout << "Ingrese el carnet del estudiante al que le desea asignar la revista" << endl;
                    cin >> carnet;

                    //Mandando a llamar a la función para asignar, con la lista completa de estudiantes, el carnet deseado y la pila de revistas
                    if(asignarRevista(&listaEstudiantes, carnet, &revista)){
                        //Eliminamos la revista hasta arriba de la pila porque ya fue asignado a un estudiante
                        pilaRevista.pop();
                    }
                }
                break;
            case 6:
                status = false;
                cout << "Fin del programa." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    }
    return 0;
}