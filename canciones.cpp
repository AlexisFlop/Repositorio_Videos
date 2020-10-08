#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct canciones
{
    string Cantante, Titulo, Genero;
    int Duracion = 0;
};

typedef struct canciones Canciones;

queue <Canciones> Feliz;
queue <Canciones> Triste;
queue <Canciones> Estudiar;

void IngresarCancion();
void BorrarCancion();
void BorrarCanciones();
void MostrarCanciones();

int main()
{
    int uOPCION = 0;
    bool uBANDERA = true;

    do
    {
        cout << "\nBienvenido al menu de administracion de sus Playlist" << endl;
        cout << "1: Ingresar canciones\n2: Borrar una cancion \n3: Eliminar todas las canciones\n4: Mostrar canciones";
        cout << "\n5: Salir del programa\n";
        cout << "Ingrese la opcion a la que desea acceder: "; cin >> uOPCION;

        switch (uOPCION)
        {
        case 1:
        IngresarCancion();
        break;

        case 2:
        BorrarCancion();
        break;

        case 3:
        BorrarCanciones();
        break;

        case 4:
        MostrarCanciones();
        break;

        case 5:
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

void IngresarCancion()
{
    int OPCION = 0;
    bool BANDERA = true;
    Canciones Usuario;
    do
    {
        cout << "1: Playlist Feliz\n2: Playlist Sad \n3: Playlist Estudiar\n4: Regresar al menu principal\n";
        cout << "Ingrese la opcion a la que desea agregar una cancion: "; cin >> OPCION;
        switch(OPCION)
        {
            case 1:
            cin.ignore();
            cout << "Ingrese el nombre del Cantante: "; getline(cin, Usuario.Cantante);
            cin.ignore();
            cout << "Ingrese el Titulo de la cancion: "; getline(cin, Usuario.Titulo);
            cin.ignore();
            cout << "Ingrese el Genero de la cancion: "; getline(cin, Usuario.Genero);
            fLINE:
            cout << "Ingrese la duracion de la cancion en segundos: "; cin >> Usuario.Duracion;
            if (Usuario.Duracion <= 0)
            {
                cout << "\nNo puedes ingresar valores menores o igual a 0.\n";
                goto fLINE;
            }
            Feliz.push(Usuario);
            break;

            case 2:
            cin.ignore();
            cout << "Ingrese el nombre del Cantante: "; getline(cin, Usuario.Cantante);
            cin.ignore();
            cout << "Ingrese el Titulo de la cancion: "; getline(cin, Usuario.Titulo);
            cin.ignore();
            cout << "Ingrese el Genero de la cancion: "; getline(cin, Usuario.Genero);
            sLINE:
            cout << "Ingrese la duracion de la cancion en segundos: "; cin >> Usuario.Duracion;
            if (Usuario.Duracion <= 0)
            {
                cout << "\nNo puedes ingresar valores menores o igual a 0.\n";
                goto sLINE;
            }
            Triste.push(Usuario);
            break;

            case 3:
            cin.ignore();
            cout << "Ingrese el nombre del Cantante: "; getline(cin, Usuario.Cantante);
            cin.ignore();
            cout << "Ingrese el Titulo de la cancion: "; getline(cin, Usuario.Titulo);
            cin.ignore();
            cout << "Ingrese el Genero de la cancion: "; getline(cin, Usuario.Genero);
            tLINE:
            cout << "Ingrese la duracion de la cancion en segundos: "; cin >> Usuario.Duracion;
            if (Usuario.Duracion <= 0)
            {
                cout << "\nNo puedes ingresar valores menores o igual a 0.\n";
                goto tLINE;
            }
            Estudiar.push(Usuario);
            break;

            case 4:
            cout << "\nHa decidido salir del programa\n";
            BANDERA = false;
            break;

            default:
            cout << "\nNinguna de las opciones que ha ingresado es valida, vuelva a intentarlo.\n";
            break;
        }
    } while (BANDERA);  
}

void BorrarCancion()
{
    int OPCION = 0;
    bool BANDERA = true;
    cout << "\nEsta a punto de Borrar una cancion.\n";
    do
    {
        cout << "1: Playlist Feliz\n2: Playlist Sad \n3: Playlist Estudiar\n4: Regresar al menu principal\n";
        cout << "Ingrese la Playlist de la que desea borrar la ultima primera cancion agregada: "; cin >> OPCION;
        switch(OPCION)
        {
            case 1:
            Feliz.pop();
            break;

            case 2:
            Triste.pop();
            break;

            case 3:
            Estudiar.pop();
            break;

            case 4:
            cout << "\nHa decidido salir de este menu\n";
            BANDERA = false;
            break;

            default:
            cout << "\nNinguna de las opciones que ha ingresado es valida, vuelva a intentarlo.\n";
            break;
        }
    }while (BANDERA);     
}

void BorrarCanciones()
{
    int OPCION = 0;
    bool BANDERA = true;
    cout << "\nEsta a punto de Borrar todas las canciones de una playlist.\n";
    do
    {
        cout << "1: Playlist Feliz\n2: Playlist Sad \n3: Playlist Estudiar\n4: Regresar al menu principal\n";
        cout << "Ingrese la Playlist de la que desea borrar todas las canciones: "; cin >> OPCION;
        switch(OPCION)
        {
            case 1:
            if (Feliz.empty())
            {
                cout << "\nLa playlist esta vacia, regresado al menu principal\n";
                return;
            }

            for (int i = 0; i < Feliz.size(); i++)
            {
                Feliz.pop();
            }
            cout << "\nSe han borrado correctamente todas las caciones\n";
            break;

            case 2:
            if (Triste.empty())
            {
                cout << "\nLa playlist esta vacia, regresado al menu principal\n";
                return;
            }

            for (int i = 0; i < Triste.size(); i++)
            {
                Triste.pop();
            }
            cout << "\nSe han borrado correctamente todas las caciones\n";
            break;

            case 3:
            if (Estudiar.empty())
            {
                cout << "\nLa playlist esta vacia, regresado al menu principal\n";
                return;
            }

            for (int i = 0; i < Estudiar.size(); i++)
            {
                Estudiar.pop();
            }
            cout << "\nSe han borrado correctamente todas las caciones\n";
            break;

            case 4:
            cout << "\nHa decidido salir de este menu\n";
            BANDERA = false;
            break;

            default:
            cout << "\nNinguna de las opciones que ha ingresado es valida, vuelva a intentarlo.\n";
            break;
        }
    }while (BANDERA);    
}

void MostrarCanciones()
{
    int OPCION = 0;
    bool BANDERA = true;
    Canciones Auxiliar;

    cout << "\nEsta a punto de Mostrar todas las canciones de una playlist.\n";
    do
    {
        cout << "1: Playlist Feliz\n2: Playlist Sad \n3: Playlist Estudiar\n4: Regresar al menu principal\n";
        cout << "Ingrese la Playlist de la que desea mostrar todas las canciones: "; cin >> OPCION;
        switch(OPCION)
        {
            case 1:
            if (Feliz.empty())
            {
                cout << "\nLa playlist esta vacia, regresado al menu principal\n";
                return;
            }

            for (int i = 0; i < Feliz.size(); i++)
            {
                Auxiliar = Feliz.front();
                cout << "\nTitulo: " << Auxiliar.Titulo << endl;
                cout << "Cantante: " << Auxiliar.Cantante << endl;
                cout << "Genero: " << Auxiliar.Genero << endl;
                cout << "Duracion: " << Auxiliar.Duracion << " segundos.\n";
                Feliz.pop();
                Feliz.push(Auxiliar);
            }
            break;

            case 2:
            if (Triste.empty())
            {
                cout << "\nLa playlist esta vacia, regresado al menu principal\n";
                return;
            }

            for (int i = 0; i < Triste.size(); i++)
            {
                Auxiliar = Triste.front();
                cout << "\nTitulo: " << Auxiliar.Titulo << endl;
                cout << "Cantante: " << Auxiliar.Cantante << endl;
                cout << "Genero: " << Auxiliar.Genero << endl;
                cout << "Duracion: " << Auxiliar.Duracion << " segundos.\n";
                Triste.pop();
                Triste.push(Auxiliar);
            }
            break;

            case 3:
            if (Estudiar.empty())
            {
                cout << "\nLa playlist esta vacia, regresado al menu principal\n";
                return;
            }

            for (int i = 0; i < Estudiar.size(); i++)
            {
                Auxiliar = Estudiar.front();
                cout << "\nTitulo: " << Auxiliar.Titulo << endl;
                cout << "Cantante: " << Auxiliar.Cantante << endl;
                cout << "Genero: " << Auxiliar.Genero << endl;
                cout << "Duracion: " << Auxiliar.Duracion << " segundos.\n";
                Estudiar.pop();
                Estudiar.push(Auxiliar);
            }
            break;

            case 4:
            cout << "\nHa decidido salir de este menu\n";
            BANDERA = false;
            break;

            default:
            cout << "\nNinguna de las opciones que ha ingresado es valida, vuelva a intentarlo.\n";
            break;
        }
    }while (BANDERA);    
}