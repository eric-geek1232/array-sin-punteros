#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int indice = 0;	
int arreglo_numeros[] = { };


class Myarreglo{		
		
	public:			
		void agregar(int tamano){
			int numero;	
				
			if (indice == 0) { // si al arreglo esta vacio
				arreglo_numeros[tamano]; // asignar un tamaño
				
				cout<< "\nDAME LOS NUMEROS\n\n";
						
				for (int posicion = 0; posicion < tamano; posicion++) { // pedir numeros y llenar el arreglo
						cin>> numero;
						
					arreglo_numeros[posicion] = numero;
					indice++; // referencia el numero de elementos 			
				}
			} else {
				int aux;
				aux = indice; // contador aux
				
				cout<< "\nDAME LOS NUMEROS\n\n";	
				for(int posicion = aux; posicion < tamano+aux; posicion++){
						cin>> numero;
						
					arreglo_numeros[posicion] = numero;
					indice++; // referencia el numero de elementos 				
				}
			}																	
		}
		
		void insertar(int posicion){							
			if(posicion < indice){
				int numero;	
				
				cout<< "\nDAME EL VALOR: ";
					cin>> numero;
								
				for(int i = indice; i >= posicion; i--){							
					arreglo_numeros[i+1] = arreglo_numeros[i];
				}
									
				arreglo_numeros[posicion] = numero;
				indice++; //incrementar a nuevo 5 a 6 a 7
				
				cout<< "\n\tNUEVA LISTA:\n\n";
				mostrar();
				cout<< "\n";	
			}else{				
				cout<< "\nESTA POSICION NO EXISTE \n"<< endl;
			}	
  		}
  		
  		void eliminar(int numero){
  			int posicion = buscar(numero);
			  
			if(posicion < indice){                                    //SI LA ENCONTRO 
						
				for(int y = posicion; y < indice; y++){                 //ESTE SIRVE PARA BARRAR
  					arreglo_numeros[y] = arreglo_numeros[y + 1];      
				}
				
				indice--;
				
				cout<< "\n\tNUEVA LISTA:\n"<< endl; //SE MUESTRAN LOS DATOS
				
				if(indice == 0){
					cout<< "\t***LISTA VACIA***"<< endl;
				} else {
					mostrar();
				}
				
				cout<< "\n";		 
			}else{
				cout<< "\nEL NUMERO NO SE HA ENCONTRADO\n"<< endl;
			}	
		}
		
		void mostrar(){
			for(int posicion = 0; posicion < indice; posicion++){              //SE MUESTRAN LOS DATOS
					cout<< "Posicion ["<< posicion<< "] "<< "= "<< arreglo_numeros[posicion]<< endl;
			}	
		}
		
		void modificar(int numero){
			int posicion = buscar(numero);
			  
			if(posicion < indice){                 //SI LA ENCONTRO
			    cout<< "\nQUE NUMERO QUIERES: ";
					cin>> numero; 
				
				arreglo_numeros[posicion] = numero; // modificar
				
				cout<< "\n\tNUEVA LISTA:\n"<< endl; //SE MUESTRAN LOS DATOS
				mostrar();
				cout<< "\n";	              		 
			}else{
				
				cout<< "EL NUMERO NO SE HA ENCONTRADO"<< endl;
			}	
			
		}
		
		int buscar(int numero){
			int posicion = 0;
  			while(posicion < indice && arreglo_numeros[posicion] != numero){    //ENCONTRAMOS LA POSICION
  				posicion++;
			}
			return posicion;	
		}
		
};        

int main(){
    int opcion=0, numero, posicion;		
    
    Myarreglo arreglo;
   
    
    do{
    	cout<< "\t..::MENU::..\n"<<endl;
	 	cout<< " 1 AGREGAR \n 2 INSERTAR EN POSICION \n 3 ELIMINAR \n 4 MODIFICAR \n 5 BUSCAR \n 6 MOSTRAR LOS DATOS\n 7 SALIR"<< endl;
	 	cout<< "\n\tELIGE LA OPCION QUE DESEAS: ";
	 		cin>> opcion;
	 		
	    system("cls");
	    
   		switch (opcion){
			case 1:
				cout<< "\t***AGREGAR***"<< endl;
				cout<< "\nCUANTOS NUMEROS DESEA INGRESAR: ";
					cin >>numero;
											
				arreglo.agregar(numero);
				
				cout << "\n";
				system("pause");
				system("cls");			
			break;
			
			case 2:
			    if(indice != 0){
			    	cout<< "\t***INSERTAR EN POSICION***\n"<< endl;
			    	
			    	arreglo.mostrar();
			    	
			    	cout<< "\nEN QUE POSICION DESEA INSERTAR: ";
						cin>> posicion;
			
					arreglo.insertar(posicion);
				} else {
					cout<< "\nAUN NO TIENES ELEMENTOS, selecciona agregar\n\n";
				}
			    
			    system("pause");
				system("cls");
			break;
			
			
			case 3:
				if(indice != 0){
					cout<< "\t***ELIMINAR***\n"<< endl;
					
					arreglo.mostrar();
					
					cout<< "\nQUE NUMERO DESEA ELIMINAR: ";
						cin>>numero;
						
					arreglo.eliminar(numero);	
				} else{
					cout<< "\nAUN NO TIENES ELEMENTOS, selecciona agregar\n\n";
				}
					
				system("pause");
				system("cls");
			break;
			
			case 4:
				if(indice != 0){
					cout<< "\t***MODIFICAR***\n"<< endl;
					
					arreglo.mostrar();
					
					cout<< "\nQUE NUMERO DESEA MODIFICAR\n";
						cin>>numero;
						
					arreglo.modificar(numero);	
				} else{
					cout<< "\nAUN NO TIENES ELEMENTOS, selecciona agregar\n\n";
				}
				
				system("pause");
				system("cls");
			break;
				
			case 5:
				if(indice != 0){
			    	int resultado;
			    	
					cout<< "\t***BUSCAR***"<< endl;
					cout<< "\nQUE NUMERO DESEA BUSCAR: ";
						cin>> numero;
						
			   		resultado = arreglo.buscar(numero);  //BUSCAR LA POSICION para obtener el numero
			   		
					if(resultado < indice ){
						cout<< "\nSE ENCONTRO EL NUMERO: "<<arreglo_numeros[resultado]<<"\n"<< endl;  //MOSTRAR EL NUMERO del arreglo variable gobal en la posicion
					} else {
						cout<< "\nNO SE ENCONTRO EL NUMERO: "<<numero<<"\n"<< endl;
					}
				} else {
					cout<< "\nAUN NO TIENES ELEMENTOS, selecciona agregar\n\n";
				}
				
				system("pause");
				system("cls");
			break;		
				
			case 6:
				if(indice != 0){
			    	cout<< "\t***MOSTRAR DATOS***\n"<< endl;
			    	arreglo.mostrar();
			    	cout<< "\n";
				} else {
					cout<< "\nAUN NO TIENES ELEMENTOS, selecciona agregar\n\n";
				}
				
				system("pause");
				system("cls");
			break;
			
			case 7:
				system("cls");
				cout<< "\t***GRACIAS***\n"<< endl;
				system("pause");
				system("cls");
				break;
				
			default:
				char answer;
				system("cls");
				cout<< "\tERROR: no escogiste una opcion valida...\n"<< endl;
				
				cout<< "DESEA SALIR s/n"<< endl;
					cin>> answer;
					
				if(answer == 's' || answer == 'S'){
					opcion = 7;
					system("cls");
					cout<< "\t***GRACIAS***\n"<< endl;
					system("pause");
					system("cls");
				} else {
					opcion = 0;
				}
				
				system("cls");
				break;
		}
	} while(opcion != 7);
	
return 0;}

	
//Agregar *
//Insertar *
//Eliminar *


//Modificar
//Buscar
//Mostrar los datos.
