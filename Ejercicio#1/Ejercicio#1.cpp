/*Ejercicio # 1:
El presidente de un club de futbol requiere calcular el sueldo de sus jugadores
si se tiene como dato la edad y la nacionalidad del jugador.

Ademas se sabe que el sueldo se calculara de la siguiente manera:
Sueldo fijo $2500.00
Si es extranjero recibe un bono de $500.00

Si la edad esta entre 15 y 20, el salario incrementa en $1400.00
Si la edad esta entre 21 y 25, el salario incrementa en $1500.00
Si la edad esta entre 26 y 30, el salario incrementa en $1200.00
Si la edad es mayor a 30, el salario incrementa en $800.00
Determine el sueldo del jugador si se tiene como datos la edad y nacionalidad.

Mostrar un reporte del total a pagar de planilla, así como el total de jugadores por
los rangos de edad. Ademas de indicar que rango de edad es el mas remunerado.*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct datos{
	int   edad;
	char  nacionalidad[20];
	int pago;
}est;

void menu();
void pedirdatos();
void aniadir();
void leer();

int main(){
	menu();
	system("pause");
}

void menu(){
	int menu;
	do{
		system("cls");
		cout<<"\t\t\t\t---------club de futbol---------"<<endl;
		cout<<"\t\t\t\t--------------------------------"<<endl;
		cout<<"\t\t\t\t1.Ingresar sueldo del jugador"<<endl;
		cout<<"\t\t\t\t2.Mostrar pago de planilla"<<endl;
		cout<<"\t\t\t\t3.Salir"<<endl;
		cout<<"\t\t\t\t  Elija una opcion: ";
		cin>>menu;
		
		switch(menu){
			case 1:
				system("cls");
				pedirdatos();
				aniadir();
				break;
			case 2:
				system("cls");
				leer();
				break;
			case 3:
				menu = 3;
				break;
	
		}
	}while(menu!=3);
}

void pedirdatos(){
	int pago, sueldo=2500, bono=500;
	char pais[] = "guatemala";
	
	system("cls");
	cin.ignore();
	cout<<"Ingrese la nacionalidad del jugador: ";
	cin.getline(est.nacionalidad,20,'\n');
	strlwr(est.nacionalidad);
	do{
	cout<<"Ingrese la edad del jugador de 15 en adelante: ";
	cin>>est.edad;
	
	if(est.edad>14 && est.edad<21){
		pago = 1400;
	}else if(est.edad>20 && est.edad<26){
		pago = 1500;
	}else if(est.edad>25 && est.edad<31){
		pago = 1200;
	}else{
		pago = 800;
	}
    }while(est.edad<15);
    
    if(strcmp(est.nacionalidad,pais) != 0){
    	est.pago = pago + sueldo + bono;
	}else{
		est.pago = pago + sueldo;
	}
}

void aniadir(){
		ofstream archivo;
				
		try {
		archivo.open("datos.txt",ios::app);
		archivo<<est.edad<<"\t"<<est.nacionalidad<<"\t"<<est.pago<<endl;
		archivo.close();
		cout<<"Datos grabados en el archivo"<<endl<<endl;
		}
		catch(exception X){
			cout<<"Error al grabar en el archivo"<<endl<<endl;
		} //fin try/catch
		system("PAUSE");
		archivo.close();
}

void leer(){
	system("cls");
	ifstream leer;
	string jugador;
	int lineas=0, i, total;
	int cont=0, cont1=0, cont2=0, cont3=0;
	int aux=0, aux1=0, aux2=0, aux3=0;
			
		leer.open("datos.txt",ios::in); 
				
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
				
		while(getline(leer,jugador)){
			lineas++;
		}	
	leer.close(); 	
					
	datos vector[lineas];
			
		leer.open("datos.txt",ios::in);
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo!!!";
			exit(1);
		}
		
		for(i=0;i<lineas;i++){    
  			leer>>vector[i].edad>>vector[i].nacionalidad>>vector[i].pago;
		}
		
		cout<<"\t\t\t\t  Edad   |     Nacionalidad  |    Pago     | "<<endl;
		for(i=0;i<lineas;i++){
			cout<<"\t\t\t\t "<<vector[i].edad<<"\t\t"<<vector[i].nacionalidad<<"\t  "<<vector[i].pago<<endl;
		}
		
		for(i=0;i<lineas;i++){
				if(vector[i].edad>14 && vector[i].edad<21){
					cont++;
					aux += vector[i].pago;
				}
				if(vector[i].edad>20 && vector[i].edad<26){
					cont1++;
					aux1 += vector[i].pago;
				}
				if(vector[i].edad>25 && vector[i].edad<31){
				    cont2++;
				    aux2 += vector[i].pago;
				}
				if(vector[i].edad>30){
					cont3++;
					aux3 += vector[i].pago;
				}			    
		}
			
		cout<<"\n\nTotal de jugadores por rango de edad"<<endl;
		cout<<"*Edad de 15 a 20 "<<cont<<endl;
		cout<<"*Edad de 21 a 25 "<<cont1<<endl;
		cout<<"*Edad de 26 a 30 "<<cont2<<endl;
		cout<<"*Edad de 30 en adelante "<<cont3<<endl<<endl;
		
		if(aux>aux1 && aux>aux2 && aux>aux3){
			cout<<"El rango de edad de 15 a 20 es el mas renumerado"<<endl<<endl;
		}else if(aux1>aux && aux1>aux2 && aux1>aux3){
			cout<<"El rango de edad de 21 a 25 es el mas renumerado"<<endl<<endl;
		}else if(aux2>aux && aux2>aux1 && aux2>aux3){
			cout<<"El rango de edad de 26 a 30 es el mas renumerado"<<endl<<endl;
		}else{
			cout<<"El rango de edad de 31 en adelante es el mas renumerado"<<endl<<endl;
		}
		system("pause");
		leer.close();
}

