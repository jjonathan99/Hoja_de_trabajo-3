/*En la Pizzeria "Gran sabor" se tienen las siguientes ofertas:
Por la compra de una pizza grande (Q80.00), recibe un descuento de 10%
Por la compra de una pizza familiar (Q115.00), recibe un descuento de 15%
Por la compra de una pizza fiesta(Q100.00), recibe un descuento de 20%

Solicitar el tipo de pizza, el precio unitario y hallar el precio a pagar.

Grabar los datos a un archivo y mostrar el total global de la venta del dia y
determinar el total de lo vendido por producto, mostrando tambien el porcentaje
con relacion al total.*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos{
	int precio, preciof, precioff;
	int total, totalf, totalff;
	int totalpizzas, totalpizzaf, totalpizzaff;
}est;

using namespace std;

int main(){
	int menu, menu1, menu2;
	int descuento, salir = 1, totalp=0, totalg=0, totalg1=0, totalg2=0, tt;

	
	do{
		system("cls");
		cout<<"\t\t\t\t----------Pizzeria----------"<<endl;
		cout<<"\t\t\t\t1. ingresar pedido de Pizza."<<endl;
		cout<<"\t\t\t\t2. total de ventas global de pizza del dia."<<endl;
		cout<<"\t\t\t\t3. Total vendido por producto."<<endl;//mostrar tambien porcentaje del total de cada producto con relacion al total de ventas
		cout<<"\t\t\t\t4. Salir."<<endl;
		cout<<"\t\t\t\tIngrese una opcion: ";
		cin>>menu;
		
		switch(menu){
			case 1:
				system("cls");
				cout<<"\t\t\t\t----------Menu de Pizza----------"<<endl;
				cout<<"\t\t\t\t1. Pizza Grande."<<endl;
				cout<<"\t\t\t\t2. Pizza Familiar."<<endl;
				cout<<"\t\t\t\t3. Pizza Fiesta."<<endl;//mostrar tambien porcentaje del total de cada producto con relacion al total de ventas
				cout<<"\t\t\t\tIngrese una opcion: ";
				cin>>menu1;
				
				switch(menu1){
					case 1:
						system("cls");
						cout<<"Pizza grande"<<endl;
						cout<<"ingrese el precio de la pizza: ";
						cin>>est.precio;
						cout<<"Ingrese la cantidad de pizzas: ";
						cin>>est.totalpizzas;
						
						descuento = (est.totalpizzas * est.precio)*0.10;
						
						est.total = (est.totalpizzas * est.precio)- descuento;
						
						cout<<"\n\nEl total a pagar es: "<<est.total;
					
						FILE *abrir;
						
						abrir = fopen("PizzaGrande.txt","a+b");
						
						if(abrir== NULL){
							cout<<"no se pudo abrir el archivo"<<endl;
							exit(1);
						}
						fwrite(&est,sizeof(est),1,abrir);
						cout<<"\nDatos Guardados"<<endl<<endl;
						fclose(abrir);
						system("pause");
						break;
					case 2:
						system("cls");
						cout<<"Pizza Familiar"<<endl;
						cout<<"ingrese el precio de la pizza: ";
						cin>>est.preciof;
						cout<<"Ingrese la cantidad de pizzas: ";
						cin>>est.totalpizzaf;
						
						descuento = (est.totalpizzaf * est.preciof)*0.15;
						
						est.totalf = (est.totalpizzaf * est.preciof)- descuento;
						
						cout<<"\n\nEl total a pagar es: "<<est.totalf;
					
						FILE *abrir1;
						
						abrir1 = fopen("PizzaFamiliar.txt","a+b");
						
						if(abrir1== NULL){
							cout<<"no se pudo abrir el archivo"<<endl;
							exit(1);
						}
						fwrite(&est,sizeof(est),1,abrir1);
						cout<<"\nDatos Guardados"<<endl<<endl;
						fclose(abrir1);
						system("pause");
						break;
					case 3:
						system("cls");
						cout<<"Pizza Fiesta"<<endl;
						cout<<"ingrese el precio de la pizza: ";
						cin>>est.precioff;
						cout<<"Ingrese la cantidad de pizzas: ";
						cin>>est.totalpizzaff;
						
						descuento = (est.totalpizzaff * est.precioff)*0.20;
						
						est.totalff = (est.totalpizzaff * est.precioff)- descuento;
						
						cout<<"\n\nEl total a pagar es: "<<est.totalff;
					
						FILE *abrir2;
						
						abrir2 = fopen("PizzaFiesta.txt","a+b");
						
						if(abrir2== NULL){
							cout<<"no se pudo abrir el archivo"<<endl;
							exit(1);
						}
						fwrite(&est,sizeof(est),1,abrir2);
						cout<<"\nDatos Guardados"<<endl<<endl;
						fclose(abrir2);
						system("pause");
						break;
				}	
				break;			
//--------------------------------------------------------------------------------------------------------------------------------------------------------------				
				case 2:
					system("cls");
					FILE *leer3;
						
						leer3 = fopen("PizzaGrande.txt","r");
						
						if(leer3 == NULL){
							cout<<"no se pudo leer el archivo"<<endl;
							exit(1);
						}
						totalg = 0;
						while(!feof(leer3)){
							fread(&est,sizeof(est),1,leer3);
							totalg += est.total;			
						}
						totalg -=est.total; 
						cout<<"el total en ventas es de pizza grande es de: "<<totalg<<endl;
						fclose(leer3);
						
					
						FILE *leer4;
						
						leer4 = fopen("PizzaFamiliar.txt","r");
						
						if(leer4 == NULL){
							cout<<"no se pudo leer el archivo"<<endl;
							exit(1);
						}
						totalg1 = 0;
						while(!feof(leer4)){
							fread(&est,sizeof(est),1,leer4);
							totalg1 += est.total;			
						}
						totalg1 -=est.total; 
						cout<<"\nEl total en ventas es de pizza Familiar es de: "<<totalg1<<endl;
						fclose(leer4);
						
						FILE *leer5;
						
						leer5 = fopen("PizzaFiesta.txt","r");
						
						if(leer5 == NULL){
							cout<<"no se pudo leer el archivo"<<endl;
							exit(1);
						}
						totalg2 = 0;
						while(!feof(leer5)){
							fread(&est,sizeof(est),1,leer5);
							totalg2 += est.total;			
						}
						totalg2 -=est.total; 
						cout<<"\nEl total en ventas es de pizza Familiar es de: "<<totalg2<<endl;
						fclose(leer5);
						
						tt= totalg + totalg1 + totalg2;
						
						cout<<"\nEl total de ventas de las 3 pizzas es de: "<<tt<<endl;
						system("pause");
				break;
				
//--------------------------------------------------------------------------------------------------------------------------------------------------------------				
			case 3:
				system("cls");
				cout<<"\t\t\t\t------Total vendido------"<<endl;
				cout<<"\t\t\t\t1. Pizza Grande."<<endl;
				cout<<"\t\t\t\t2. Pizza Familiar."<<endl;
				cout<<"\t\t\t\t3. Pizza Fiesta."<<endl;
				cout<<"\t\t\t\tIngrese una opcion: ";
				cin>>menu2;
				
				switch(menu2){
					case 1:
						system("cls");
						FILE *leer;
						
						leer = fopen("PizzaGrande.txt","r");
						
						if(leer == NULL){
							cout<<"no se pudo leer el archivo"<<endl;
							exit(1);
						}
						totalp= 0;
						totalg = 0;
						while(!feof(leer)){
							fread(&est,sizeof(est),1,leer);
							totalp += est.totalpizzas;
							totalg += est.total;
							
						}
						cout<<"el total de pizzas vendidas es de: "<<totalp-est.totalpizzas<<endl;
						cout<<"el total en ventas es de: "<<totalg-est.total<<endl;
						fclose(leer);
						system("pause");
					break;
					
					case 2:
						system("cls");
						FILE *leer1;
						
						leer1 = fopen("PizzaFamiliar.txt","r");
						
						if(leer1 == NULL){
							cout<<"no se pudo leer el archivo"<<endl;
							exit(1);
						}
						totalp= 0;
						totalg1 = 0;
						while(!feof(leer1)){
							fread(&est,sizeof(est),1,leer1);
							totalp += est.totalpizzaf;
							totalg1 += est.totalf;
							
						}
						cout<<"el total de pizzas vendidas es de: "<<totalp-est.totalpizzaf<<endl;
						cout<<"el total en ventas es de: "<<totalg1-est.totalf<<endl;
						fclose(leer1);
						system("pause");
					break;
					
					case 3:
						system("cls");
						FILE *leer2;
						
						leer2 = fopen("PizzaFiesta.txt","r");
						
						if(leer2 == NULL){
							cout<<"no se pudo leer el archivo"<<endl;
							exit(1);
						}
						totalp= 0;
						totalg2 = 0;
						while(!feof(leer2)){
							fread(&est,sizeof(est),1,leer2);
							totalp += est.totalpizzaff;
							totalg2 += est.totalff;
							
						}
						cout<<"el total de pizzas vendidas es de: "<<totalp-est.totalpizzaff<<endl;
						cout<<"el total en ventas es de: "<<totalg2-est.totalff<<endl;
						fclose(leer2);
						system("pause");
					break;
				}		
			break;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------							
			case 4:
				salir = 0;
				break;
		}
		
	}while(salir != 0);
	
	cout<<endl<<endl;
	system("pause");
}
