/* Nombre del programa: Número de pesas (Ep14)
Elaboró: Ricardo Leal Cabrera	No. Lista: 14
Fecha 13-10-2020
Descropcion: Programa que calcula el número de pesas para determinar cierto peso menor a 5000 gramos*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main ()
{
	int peso, x;
	cout<<"Ingresa el peso en gramos: ";
	cin>>peso;
	x=peso/1000;
	peso-peso-x*1000;
	cout<<"Número de pesas de 1000g necesarias: "<<x<<endl;
	x=peso/500;
	peso=peso-x*500;
	cout<<"Número de pesas de 500g necesarias: "<<x<<endl;
	x=peso/100;
	peso=peso-x*100;
	cout<<"Número de pesas de 100g necesarias: "<<x<<endl;
	x=peso/50;
	peso=peso-x*50;
	cout<<"Número de pesas de 50g necesarias: "<<x<<endl;
	x=peso/10;
	peso=peso-x*10;
	cout<<"Número de pesas de 10g necesarias: "<<x<<endl;
	x=peso/5;
	peso=peso-x*5;
	cout<<"Número de pesas de 5g necesarias: "<<x<<endl;
	x=peso/2;
	peso=peso-x*2;
	cout<<"Número de pesas de 2g necesarias: "<<x<<endl;
	x=peso;
	peso=peso;
	cout<<"Número de pesas de 1g necesarias: "<<x<<endl;
	getch();
	return 0;
}
