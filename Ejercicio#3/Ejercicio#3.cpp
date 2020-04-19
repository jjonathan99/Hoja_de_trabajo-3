/*Un empresa que se dedica a la venta de seguros de vehiculos, calcula el importe
según el modelo y color del automovil, asi como la edad del conductor.

Modelo       Color             Precio
A              Blanco           240.50
                  Metalizado    330.00
                Otros             270.50
B               Blanco          300.00
                 Metalizado     360.50
                 Otros             330.00
           
Incremento de precio
Edad            % Incremento
<31                    25%
Entre 31 y 65    0%
>65                   30%

Determine el importe a pagar mostrandolo en pantalla según los datos del vehículo (modelo y color)
y la edad del conductor.*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct datos{
	char  modelo;  // Modelo A o B
	int   edad;     // numero entero
	char  color[10];   // solo una letra
	float precio; // numeros con decimales
}est;

void menu();
void pedirdatos();
void aniadir();
void leer();


	int colores, aumento;

int main(){
	menu();	
	system("pause");
}

void menu(){
	int menu;

	do{
		system("cls");
		cout<<"\t\t\t\t------Seguros de Vehiculos------"<<endl;
		cout<<"\t\t\t\t--------------------------------"<<endl;
		cout<<"\t\t\t\t1.Ingresar Vehiculo"<<endl;
		cout<<"\t\t\t\t2.Ver datos de vehiculos"<<endl;
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
	do{
		cout<<"Ingrese A o B para el Modelo de Vehiculo:  ";
		cin>>est.modelo;
		est.modelo=toupper(est.modelo);
	}while((est.modelo !='A') && (est.modelo!='B'));
	do{
		cout<<"\n--Color del vehiculo--"<<endl;
		cout<<"1. Blanco "<<endl;
		cout<<"2. Metalizado"<<endl;
		cout<<"3. Otros"<<endl;
		cout<<"Elija una de las 3 opciones: ";
		cin>>colores;
	}while((colores!=1) && (colores!=2) && (colores!=3));
	do{
		cout<<"\nIngrese la edad del conductor: ";
		cin>>est.edad;
	}while(est.edad>=100);

	
	if(colores == 1){
		strcpy(est.color,"Blanco");
	}else if(colores == 2){
		strcpy(est.color,"Metalizado");
	}else if(colores == 3){
		strcpy(est.color,"Otros");
	}
	
	if(est.modelo == 'A' && colores == 1){
		est.precio = 240.50;
	}else if(est.modelo == 'A' && colores == 2){
		est.precio = 330.00;
	}else if(est.modelo == 'A' && colores == 3){
		est.precio = 270.50;
	}else if(est.modelo == 'B' && colores == 1){
		est.precio = 300.00;
	}else if(est.modelo == 'B' && colores == 2){
		est.precio = 360.50;
	}else if(est.modelo == 'B' && colores == 3){
		est.precio = 330.00;
	}
		
	if(est.edad<31){
		aumento = est.precio * 0.25;
		est.precio = est.precio + aumento;
	}else if(est.edad>65){
		aumento = est.precio * 0.30;
		est.precio = est.precio + aumento;
	}
}

void aniadir(){
		ofstream archivo;
				
		try {
		archivo.open("datos.txt",ios::app);
		archivo<<est.modelo<<"\t"<<est.color<<"\t"<<est.edad<<"\t"<<est.precio<<"\n";
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
	string carro;
	int lineas=0, i;

			
		leer.open("datos.txt",ios::in); 
				
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
				
		while(getline(leer,carro)){
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
  			leer>>vector[i].modelo>>vector[i].color>>vector[i].edad>>vector[i].precio;
		}
		
		cout<<"\t\t\tMODELO  ||  	COLOR	   ||  EDAD  ||  iMPORTE A PAGAR   ||"<<endl;
		for(i=0;i<lineas;i++){
			cout<<"\t\t\t  "<<vector[i].modelo<<"\t\t"<<vector[i].color<<"\t"<<vector[i].edad<<"\t\t"<<vector[i].precio<<endl;
		}
		cout<<"\n";
		system("pause");
		leer.close();
}
