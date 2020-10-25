#include <iostream>
#include <queue>
using namespace std;

struct Lista {
    string name;
    string artist;
    string gender;
    int time;
};
struct Lista lista;

queue<Lista> sad,metal,estudios;

void mostrar(queue<Lista> q) {
    if (q.empty())
    {
        cout<<"underflow!"<< endl;
    } else
    {
        queue<Lista> aux = q;
    
    while (!aux.empty()) {
        cout << "*" << aux.front().name << "--" << aux.front().artist << "*" << endl;
        cout << "Genero: " << aux.front().gender <<  endl;
        cout << "Duracion: " << aux.front().time<<" segundos." <<  endl;
        aux.pop();
    }
    }
    
    
    
}

void vaciar(queue<Lista> q) {
    if (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            q.pop();
        }
        
} else
{
    cout<<"underflow!"<< endl;
}

    }
    
    


void menu() {
    int option;
    bool status = true;
    while(status) {
        bool status2 = true, status3= true, status4 =true;
        cout << "\n" << "***** MENU DE CANCIONES *****" << endl;
        cout << "1. Agregar cancion a lista de reproduccion Sad" << endl;
        cout << "2. Agregar cancion a lista de reproduccion de Metal hardcore" << endl;
        cout << "3. Agregar cancion a lista de reproduccion de Estudio" << endl;
        cout << "4. Eliminar primera cancion de lista de reproduccion" << endl;
        cout << "5. Mostrar cola seleccionada" << endl;
        cout << "6. Vaciar cola seleccionada" << endl;
        cout << "7. Terminar el programa" << endl;

        cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "\n" << "Añadiendo cancion a lista de reproduccion Sad... "<< endl;

                cout << "Ingrese el nombre de la cancion" << endl;
                cin >> lista.name;
                cout << "Ingrese el artista de la cancion" << endl;
                cin >> lista.artist;
                cout << "Ingrese el genero de la cancion" << endl;
                cin >> lista.gender;
                cout << "Ingrese la duracion de la cancion (en segundos)" << endl;
                cin >> lista.time;
                if (lista.time<=0)
                {
                    cout << "Tiempo no valido, intentelo de nuevo: " << endl;
                    cin >> lista.time;
                }

                sad.push(lista);

                break;
            case 2:
                cout << "\n" << "Agregando cancion a lista de reproduccion Metal hardcore... "<< endl;

                cout << "Ingrese el nombre de la cancion" << endl;
                cin >> lista.name;
                cout << "Ingrese el artista de la cancion" << endl;
                cin >> lista.artist;
                cout << "Ingrese el genero de la cancion" << endl;
                cin >> lista.gender;
                cout << "Ingrese la duracion de la cancion (en segundos)" << endl;
                cin >> lista.time;
                if (lista.time<=0)
                {
                    cout << "Tiempo no valido, intentelo de nuevo: " << endl;
                    cin >> lista.time;
                }
                

                metal.push(lista);

                break;
            case 3:
                cout << "\n" << "Añadiendo cancion a lista de reproduccion Estudios... "<< endl;

                cout << "Ingrese el nombre de la cancion" << endl;
                cin >> lista.name;
                cout << "Ingrese el artista de la cancion" << endl;
                cin >> lista.artist;
                cout << "Ingrese el genero de la cancion" << endl;
                cin >> lista.gender;
                cout << "Ingrese la duracion de la cancion (en segundos)" << endl;
                cin >> lista.time;
                if (lista.time<=0)
                {
                    cout << "Tiempo no valido, intentelo de nuevo: " << endl;
                    cin >> lista.time;
                }

                estudios.push(lista);

                break;
            case 4:
                int optionx;
                
                while(status2) {
                    cout << "\n" << "***** Seleccione la lista de reproduccion para eliminar cancion o regrese*****" << endl;
                     cout << "1. Sad" << endl;
                     cout << "2. Metal Hardcore" << endl;
                     cout << "3. Estudios" << endl;
                     cout << "4. Regresar al menu anterior" << endl;
                     cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
                     cin >> optionx;
                     
                switch(optionx){
                case 1:
                sad.pop();
                cout << "Cancion eliminada, regresando al menu anterior..." << endl;
                break;
                
                case 2:
                metal.pop();
                cout << "Cancion eliminada, regresando al menu anterior..." << endl;
                break;
                
                case 3:
                estudios.pop();
                cout << "Cancion eliminada, regresando al menu anterior..." << endl;
                break;

                case 4:
                cout << "Regresando al menu anterior..." << endl;
                status2 = false;
                break;
                
                default:
                cout << "Opción no válida, intentelo de nuevo" << endl;
                break;
        }
    }
                break;
            case 5:
             int optiony;
                
                while(status3) {
                    cout << "\n" << "***** Seleccione la lista de reproduccion a mostrar o regrese*****" << endl;
                     cout << "1. Sad" << endl;
                     cout << "2. Metal Hardcore" << endl;
                     cout << "3. Estudios" << endl;
                     cout << "4. Regresar al menu anterior" << endl;
                     cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
                     cin >> optiony;
                     
                switch(optiony){
                case 1:
                mostrar(sad);
                cout << "Regresando al menu anterior..." << endl;
                break;
                
                case 2:
                mostrar(metal);
                cout << "Regresando al menu anterior..." << endl;
                break;
                
                case 3:
                mostrar(estudios);
                cout << "Regresando al menu anterior..." << endl;
                break;

                case 4:
                cout << "Regresando al menu anterior..." << endl;
                status3 = false;
                break;
                
                default:
                cout << "Opción no válida, intentelo de nuevo" << endl;
                break;
                }}
                break;
                
            case 6:
            int optionz;
                
                while(status4) {
                    cout << "\n" << "***** Seleccione la lista de reproduccion a mostrar o regrese*****" << endl;
                     cout << "1. Sad" << endl;
                     cout << "2. Metal Hardcore" << endl;
                     cout << "3. Estudios" << endl;
                     cout << "4. Regresar al menu anterior" << endl;
                     cout << "\n" << "Ingrese la opcion que desea ejecutar: ";
                     cin >> optionz;
                     
                switch(optionz){
                case 1:
                vaciar(sad);
                cout << "Lista vaciada. Regresando al menu anterior..." << endl;
                break;
                
                case 2:
                vaciar(metal);
                cout << "Lista vaciada. Regresando al menu anterior..." << endl;
                break;
                
                case 3:
                vaciar(estudios);
                cout << "Lista vaciada. Regresando al menu anterior..." << endl;
                break;

                case 4:
                cout << "Regresando al menu anterior..." << endl;
                status4 = false;
                break;
                
                default:
                cout << "Opción no válida, intentelo de nuevo" << endl;
                break;
                }}
                
                break;
            case 7:
                cout << "Fin del programa" << endl;
                status = false;
                break;
            default: 
                cout << "Opción no válida" << endl;
                break;
        }
    }
}

int main() {
    menu();

    return 0;
}