//Pila de platos-Stack
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;

struct Plato{
	string material;
	string color;
	bool estado;
};

//Apodo
typedef struct Plato Platos;

stack <Platos> PilaSucia;
stack <Platos> PilaLimpia;

//Prototipo
void AgregarPlato();
void Ensuciar1Plato();

int main(){
	int cP;
	int opcion;
	cout<<"\t || PILA DE PLATOS ||\n\n";
	
	
	bool continuar= true;
    cout<<"\n MENU----------\n";
    do{
    	cout<<"1. Agregar platos \n";
        cout<<"2. Ensuciar 1 plato \n";
        cout<<"3. Ensuciar N platos \n";
        cout<<"4. Limpiar 1 pato \n";
        cout<<"5. Mostrar pila limpia \n";
        cout<<"6. Mostrar pila sucia \n";
        cout<<"7. Salir \n";
        cout<<"Opcion: ";
        cin>>opcion;
    
        switch(opcion){
            case 1: cin.ignore(); AgregarPlato(); break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: continuar=false; break;
            default: cout<<"OPCION NO VALIDA \n\n"; break;
        }
        
    }while(continuar);
    
    
	
}

void AgregarPlato()
{
	int n= 0;
	Platos e;
	cout<<"Ingrese cuantos platos desea agregar: "; lINGRESAR: cin >> n;
	if (n < 0)
    {
        cout << "No se pueden agregar menos de 1 plato intente otra vez: ";
        goto lINGRESAR;
    }
    else
    {
        for (int i = 0; i < n ; i++)
        {
            cin.ignore();
            cout << "Ingrese el material del plato: "; getline(cin, e.material);
            gLINE:
            cout << "Ingrese el color del plato: "; cin >> e.color;


            PilaLimpia.push(e);
        }   
    }
    cout << "Se han agregado los platos , volvera al menu...\n";
}
void EnsuciarPlato()
{
    Platos Sucios = PilaLimpia.top();
    PilaLimpia.pop();
    PilaSucia.push(Sucios);
}

void EnsuciarNPlatos()
{
    int nVECES;
    cout << "Escriba la cantidad de platos que desea ensuciar: "; cin >> nVECES;
    if (nVECES > PilaLimpia.size() || nVECES < 0)
    {
        cout << "No puede ensuciar la cantidad de platos que ha seleccionado";
    }
    else 
    {
        
    }

}
