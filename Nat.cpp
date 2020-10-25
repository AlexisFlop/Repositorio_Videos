//CANCIONES.CPP
#include <iostream>
#include <queue>
using namespace std;

struct Canciones {
 string titulo;
 string cantante;
 string genero;
 int duracion;
};
//colas----
 	queue <Canciones> Feliz;
 	queue <Canciones> Triste;
 	queue <Canciones> Estudiar;
 	
//Funciones
void ingresar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar);
void eliminar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar);
void vaciar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar);
void mostrar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar);


int main(){
 	
 	cout<<"\t|| PLAYLIST DE CANCIONES ||\n\n";
    
 //menu----
 bool continuar=true;
 do{
  int opcion=0;
  int opcion2=0;
  cout<<"1. Ingresar cancion\n";
  cout<<"2. Eliminar cancion\n";
  cout<<"3. Mostrar playlist\n";
  cout<<"4. Vaciar playlist\n";
  cout<<"5. Salir\n";
  cout<<"Opcion: ";
  cin>> opcion;
  
  switch(opcion){
   case 1: ingresar(&Feliz, &Triste, &Estudiar); break;			
   case 2: eliminar(&Feliz, &Triste, &Estudiar); break;
   case 3: vaciar(&Feliz, &Triste, &Estudiar); break;
   case 4: mostrar(&Feliz, &Triste, &Estudiar); break;
   case 5: continuar=false; break;
   default: cout<<"Opcion NO valida"; break;
  }
  
 }while(continuar);
    
 return 0;
}
//_________________________________________________________
void ingresar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar){
	int n;
	do{
		cout<<"\tA que playlist quieres agregarla?\n";
		cout<<"\t1. Feliz\n";
		cout<<"\t2. Triste\n";
		cout<<"\t3. Estudiar\n";
		cout<<"Playlist: ";
		cin>>n;
	}while(n<=0);
	
	
	if(n==1){
		struct Canciones nodo;
		cin.ignore();
 		cout<<"Ingrese titulo: ";  getline(cin, nodo.titulo);
 		cin.ignore();
 		cout<<"Ingrese el/la cantante: ";  getline(cin, nodo.cantante);
 		cin.ignore();
 		cout<<"Ingrese el genero: ";  getline(cin, nodo.genero);
 		cout<<"Ingrese la duracion: ";  cin>>nodo.duracion;
 		(*Feliz).push(nodo);
 		
	}else if(n==2){
		struct Canciones nodo;
		cin.ignore();
 		cout<<"Ingrese titulo: "; getline(cin, nodo.titulo);
 		cin.ignore();
 		cout<<"Ingrese el/la cantante: ";  getline(cin, nodo.cantante);
 		cin.ignore();
 		cout<<"Ingrese el genero: ";  getline(cin, nodo.genero);
 		cout<<"Ingrese la duracion: ";  cin>>nodo.duracion;
 		(*Triste).push(nodo);
	}else{
		struct Canciones nodo;
		cin.ignore();
 		cout<<"Ingrese titulo: "; getline(cin, nodo.titulo);
 		cin.ignore();
 		cout<<"Ingrese el/la cantante: "; getline(cin, nodo.cantante);
 		cin.ignore();
 		cout<<"Ingrese el genero: "; getline(cin, nodo.genero);
 		cout<<"Ingrese la duracion: "; cin>>nodo.duracion;
 		(*Estudiar).push(nodo);
	} 
	cout<<"\tSe ha agregado 1 cancion\n";

}
//____________________________________________________________________________
void eliminar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar){
	int n;
	do{
		cout<<"\tA que playlist quieres eliminar 1 cancion?\n";
		cout<<"\t1. Feliz\n";
		cout<<"\t2. Triste\n";
		cout<<"\t3. Estudiar\n";
		cout<<"Playlist: ";
		cin>>n;
	}while(n<=0);
	
	if(n==1){
		Feliz->pop();
	}else if(n==2){
		Triste->pop();
	}else{
		Estudiar->pop();
	}
	cout<<"\tSe ha eliminado 1 cancion\n";
}
//____________________________________________________________
void vaciar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar){
	int n;
	do{
		cout<<"\tA que playlist quieres eliminar 1 cancion?\n";
		cout<<"\t1. Feliz\n";
		cout<<"\t2. Triste\n";
		cout<<"\t3. Estudiar\n";
		cout<<"Playlist: ";
		cin>>n;
	}while(n<=0);
	
	if(n==1){
		if(Feliz->empty()){
			cout<<"UNDERFLOW!";
		}else{
			for(int i=0; i<=Feliz->size(); i++){
  				Feliz->pop();
			}
		}
		cout<<"\tSe ha vaciado 1 playlist\n";
		
	}else if(n==2){
		if(Triste->empty()){
			cout<<"UNDERFLOW!";
		}else{
			for(int i=0; i<=Triste->empty(); i++){
  				Triste->pop();
			}
		}
		cout<<"\tSe ha vaciado 1 playlist\n";
		
	}else{
		if(Estudiar->empty()){
			cout<<"UNDERFLOW!";
		}else{
			for(int i=0; i<=Estudiar->empty(); i++){
  				Estudiar->pop();
			}
		}
		cout<<"\tSe ha vaciado 1 playlist\n";
		
	}
	
}
//______________________________________________________________________
void mostrar(queue <Canciones> *Feliz, queue <Canciones> *Triste, queue <Canciones> *Estudiar){
	int n;
	do{
		cout<<"\tQue playlist quieres mostrar?\n";
		cout<<"\t1. Feliz\n";
		cout<<"\t2. Triste\n";
		cout<<"\t3. Estudiar\n";
		cout<<"Playlist: ";
		cin>>n;
	}while(n<=0);
	
	if(n==1){
		if(Feliz->empty()){
			cout<<"ESTA VACIA :c\n";
		}else{
			for(int i=0; i<Feliz->size(); i++){
				struct Canciones aux;
				aux= Feliz.top();
				cout<<"Titulo: "<<aux.titulo<<"\n";
				cout<<"Cantante: "<<aux.cantante<<"\n";
				cout<<"Genero: "<<aux.genero<<"\n";
				cout<<"Duracion: "<<aux.duracion<<"\n\n";
			
				Feliz.pop();
				Feliz.push(aux);
			}
		}
		
	
		
	}else(n==2){
		if(Triste.empty()){
			cout<<"ESTA VACIA :c\n";
		}else{
			for(int i=0; i<Triste.size(); i++){
				struct Canciones aux;
				aux= Triste.top();
				cout<<"Titulo: "<<aux.titulo<<"\n";
				cout<<"Cantante: "<<aux.cantante<<"\n";
				cout<<"Genero: "<<aux.genero<<"\n";
				cout<<"Duracion: "<<aux.duracion<<"\n\n";
			
				Triste.pop();
				Triste.push(aux);
			}
		}
	}else{
		if(Estudiar.empty()){
			cout<<"ESTA VACIA :c\n";
		}else{
			for(int i=0; i<Estudiar.size(); i++){
				struct Canciones aux;
				aux= Estudiar.top();
				cout<<"Titulo: "<<aux.titulo<<"\n";
				cout<<"Cantante: "<<aux.cantante<<"\n";
				cout<<"Genero: "<<aux.genero<<"\n";
				cout<<"Duracion: "<<aux.duracion<<"\n\n";
			
				Estudiar.pop();
				Estudiar.push(aux);
			}
		}
	}
}


