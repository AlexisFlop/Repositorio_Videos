#include <iostream>
#include <queue>

using namespace std;

void add();
void deletea();
void deleteall();
void viewall();

struct actividad
{
    string titulo;
    int hora;
    int minutos;
    string descripcion;
};
typedef actividad Actividad;

Actividad act;

queue<Actividad>agenda; 

int main(){

    act.hora = 0;
    act.minutos =0;
    
    bool continuar = true;

    do
    {
        int opcion = 0;
        cout<<"Escoja una de las siguientes opciones."<<endl;
        cout<<"1. Agregar actvidad."<<endl;
        cout<<"2. Borrar actividad."<<endl;
        cout<<"3. Borrar agenda."<<endl;
        cout<<"4. Ver agenda."<<endl;
        cout<<"5. Salir."<<endl;
        cout<<"Opcion: ";cin>>opcion;cin.ignore();

        switch (opcion)
        {
        case 1: void add();break;
        case 2: void deletea();break;
        case 3: void delete_all();break;
        case 4: void viewall();break;
        case 5: continuar = false; break;
        default: cout<<"Opcion no valida"<<endl; break;
        }
    } while (continuar);
    
    return 0;
}

void add(){
    
    Actividad unaact;
    cout<<"Digite el titulo de la actividad: ";getline(cin,unaact.titulo);
    cout<<"Hora en que se realizara la actividad: ";cin>>unaact.hora;cin.ignore();
    cout<<"Minuto en el cual se realizara la actividad: ";cin>>unaact.minutos;cin.ignore();
    cout<<"Descricion de la actividad: ";getline(cin,unaact.descripcion);

    agenda.push(unaact);
}

void deletea(){
    
    if (!agenda.empty())
    {
        cout<<"Se eliminara la actividad:"<<endl;
        agenda.front();
        agenda.pop();
    }
    else
    {
        cout<<"No se han puesto actividades en la agenda"<<endl;
    }
    
}

void delete_all(){

    if (!agenda.empty())
    {
        cout<<"Se borraran "<<agenda.size()<<" elementos de tu agenda"<<endl;
        for (int i = 0; i < agenda.size(); i++)
        {
            agenda.pop();
        }
        
    }
    else
    {
        cout<<"No se han puesto actividades en esta agenda"<<endl;
    }
    
}

void viewall(){

    Actividad backup;

    if (!agenda.empty())
    {
        for (int i = 0; i < agenda.size(); i++)
        {
            agenda.front() = backup;
            agenda.front();
            agenda.pop();
            agenda.push(backup);
        }
        
    }
    else
    {
        cout<<"La agenda esta vacia"<<endl;
    }
    
}