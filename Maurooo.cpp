#include <iostream>
#include <queue>
using namespace std;

struct Cancion{
    string titulo;
    string cantante;
    string genero;
    int duracion;
};

struct Cancion cancion;

void vaciarCola(queue<Cancion>);
void ShowPlaylist(queue<Cancion>);
void menu(queue<Cancion>,queue<Cancion>,queue<Cancion>);

int main(){
    queue<Cancion> feliz;
    queue<Cancion> triste;
    queue<Cancion> estudiar;

    menu(feliz,triste,estudiar);
}

void vaciarCola(queue<Cancion> feliz){
    while (!feliz.empty())
    {
        feliz.pop();
    }
    cout << "La playlist se ha vaciado" << endl;
}

void ShowPlaylist(queue<Cancion> feliz){
    queue<Cancion> aux = feliz;
    cout << "Mostrando cola" << endl;
    while (!aux.empty())
    {
        cout << aux.front().titulo << "," << aux.front().cantante << "," << aux.front().genero << "," << aux.front().duracion << endl;
        aux.pop();
    }
}

void menu(queue<Cancion> feliz, queue<Cancion> triste, queue<Cancion> estudiar){
    int opcion;
    bool status = true;
    bool tipos = true;
    while (status)
    {
        cout << "====== PLAYLIST =====" << endl;
        cout << "1. Agregar una cancion" << endl;
        cout << "2. Eliminar una cancion" << endl;
        cout << "3. vaciar playlist " << endl;
        cout << "4. Mostrar playlist " << endl;
        cout << "5. Salir" << endl;
        
        cout << "\t Digite la opcion que desea ejecutar" << endl;
        cout << "opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            tipos = true;
        case 1:
            while (tipos)
            {
            int opcion2;
            cout << "\t Mostrando playlist" << endl;
            cout << "1. Feliz" << endl;
            cout << "2. Triste" << endl;
            cout << "3. Estudiar" << endl;
            cout << "4. Salir" << endl;
            cout << "opcion: ";
            cin >> opcion2;

            switch (opcion2)
            {
            case 1:
                cout << "Ingrese el titulo de la cancion: ";
                cin.ignore();
                getline(cin,cancion.titulo);
                cout << "Ingrese el cantante: ";
                cin.ignore();
                getline(cin,cancion.cantante);
                cout << "Ingrese el genero: ";
                cin.ignore();
                getline(cin, cancion.genero);
                cout << "Ingrese la duracion en SEGUNDOS de la cancion: ";
                cin >> cancion.duracion;

                feliz.push(cancion);
                break;
            
            case 2:
                cout << "Ingrese el titulo de la cancion: ";
                cin.ignore();
                getline(cin,cancion.titulo);
                cout << "Ingrese el cantante: ";
                cin.ignore();
                getline(cin,cancion.cantante);
                cout << "Ingrese el genero: ";
                cin.ignore();
                getline(cin, cancion.genero);
                cout << "Ingrese la duracion en SEGUNDOS de la cancion: ";
                cin >> cancion.duracion;

                triste.push(cancion);
                break;

            case 3:
                cout << "Ingrese el titulo de la cancion: ";
                cin.ignore();
                getline(cin,cancion.titulo);
                cout << "Ingrese el cantante: ";
                cin.ignore();
                getline(cin,cancion.cantante);
                cout << "Ingrese el genero: ";
                cin.ignore();
                getline(cin, cancion.genero);
                cout << "Ingrese la duracion en SEGUNDOS de la cancion: ";
                cin >> cancion.duracion;

                estudiar.push(cancion);
                break;

            case 4:
                cout << "Saliendo del menu" << endl;
                tipos = false;
                break;

            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
            }
            break;
        case 2:
            while (tipos)
            {
            int opcion2;
            cout << "\t En que playlist desea eliminar una cancion" << endl;
            cout << "1. Feliz" << endl;
            cout << "2. Triste" << endl;
            cout << "3. Estudiar" << endl;
            cout << "4. Salir" << endl;
            cout << "opcion: ";
            cin >> opcion2;
            switch (opcion2)
            {
            case 1:
                feliz.pop();
                break;
            case 2:
                triste.pop();
                break;
            case 3:
                estudiar.pop();
                break;
            case 4:
                cout << "Saliendo del menu" << endl;
                tipos = false;
                break;
            
            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
            }
            break;
        case 3:
            while (tipos)
            {
            int opcion2;
            cout << "\t Seleccion que playlist desea vaciar" << endl;
            cout << "1. Feliz" << endl;
            cout << "2. Triste" << endl;
            cout << "3. Estudiar" << endl;
            cout << "4. Salir" << endl;
            cout << "opcion: ";
            cin >> opcion2;

            switch (opcion2)
            {
            case 1:
                vaciarCola(feliz);
                break;
            case 2:
                vaciarCola(triste);
                break;
            case 3:
                vaciarCola(estudiar);
                break;
            case 4:
                cout << "Saliendo del menu" << endl;
                tipos = false;
                break;
            
            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
            }
            break;
        case 4:
            while (tipos)
            {
                int opcion2;
            cout << "\t Seleccion que playlist desea vaciar" << endl;
            cout << "1. Feliz" << endl;
            cout << "2. Triste" << endl;
            cout << "3. Estudiar" << endl;
            cout << "4. Salir" << endl;
            cout << "opcion: ";
            cin >> opcion2;

            switch (opcion2)
            {
            case 1:
                ShowPlaylist(feliz);
                break;
            case 2:
                ShowPlaylist(triste);
                break;
            case 3:
                ShowPlaylist(estudiar);
                break;
            case 4:
                cout << "Saliendo del menu" << endl;
                status = false;
                break;
            
            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
            break;
            }
            
        case 5:
            cout << "Saliendo del programa" << endl;
            status = false;
            break;  

        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    }
}