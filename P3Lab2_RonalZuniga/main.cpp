#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void imprimirArreglo(int []);
void arregloOrdenado(int [], int);
string evaluarToken(string);

int main(int argc, char** argv) {
	int opcion = 0;
	while(opcion != 4) {
		cout << "----MENU----" << endl;
		cout << "1. Ejercicio 1" << endl;
		cout << "2. Ejercicio 2" << endl;
		cout << "3. Ejercicio 3" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese la opcion que desea: ";
		cin >> opcion;
		cout << endl;
		
		while(opcion < 0 || opcion > 4) {
			cout << "Ingrese una opcion dentro del rango" << endl;
			cout << "Ingrese la opcion que desea: ";
			cin >> opcion;
			cout << endl;
		}//fin while validacion

		if(opcion == 1) {
			cout << "Tablas de Verdad" << endl;
			string cadena = "", subcadena = "";
			int contador = 0;
			string resultado = "";
			cout << "Ingrese la cadena a evaluar: ";
			cin >> cadena;
			cout << endl << endl;
			for (int i = 0; i < cadena.length(); i++) {//la cadena original se separa en tokens o subcadenas
				char letra = cadena[i];
				if (letra == '1' || letra == '0') {
					subcadena += letra;
					contador++;
					if(contador == 2) {
						cout << "La subcadena es: " << subcadena << endl;
						resultado = evaluarToken(subcadena);
						cout << "El resultado de la comparacion es: " << resultado << endl;
						subcadena = "";
						subcadena += resultado;
						contador = 1;
					}//fin de decision interna
				} else {
					subcadena += letra;
				}//fin de decision anidada
			}//fin del for
			if (resultado == "1") {//evalua la solucion final y muestra resultado en pantalla
				cout << "Solucion = true" << endl << endl;
			} else {
				cout << "Solucion = false" << endl << endl;
			}//fin de decision anidada
			cout << endl;
		}//fin opcion 1

		if(opcion == 2) {
			cout << "Arreglo en orden Ascendente" << endl;
			cout << "Arreglo Original" << endl;
			int arr [20];
			srand((unsigned)time(0));
			for(int i = 0; i < 20; i++) {//llena el arreglo con numeros aleatorios
				arr[i] = 0 + (rand()%99);
				cout << arr[i] << "   ";
			}
			cout << endl;
			cout << "Arreglo ordenado" << endl;
			arregloOrdenado(arr, 20);
			cout << endl;
		}//fin opcion 2

		if(opcion == 3) {
			
		}//fin opcion 3

	}//fin while Menu
	return 0;
}//fin del main


void arregloOrdenado(int arreglo[], int tamano) {
	if(tamano == 1) {
		return;
		imprimirArreglo(arreglo);
	} else {
		for (int i = 0; i < tamano - 1; i++) {
			if (arreglo[i] > arreglo[i+1]) {
				int temp = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = temp;
			}
		}
		imprimirArreglo(arreglo);
		arregloOrdenado(arreglo, tamano-1);
	}//fin decision anidada
}//fin metodo recursivo de ordenamiento

void imprimirArreglo(int arreglo[]) {
	for	(int i = 0; i < 20; i++) {
		cout << arreglo [i] << "  ";
	}
	cout << endl;
}//fin metodo imprimir

string evaluarToken(string token) {//metodo para evaluar las subcadenas o tokens
	string resultado = "";
	if (token.length() == 5) {//si la longitud de la subcadena es 5, es porque lleva AND como comparador
		//validacion de AND
		if (token[0] == '1' && token[4] == '1') {
			resultado = "1";
		} else if (token[0] == '0' && token[4] == '0') {
			resultado = "0";
		} else {
			resultado = "0";
		}
	} else if (token.length() == 4) {//si la longitud de la subcadena es 4, es porque lleva OR como comparador
		if (token[0] == '1' && token[3] == '1') {
			resultado = "1";
		} else if (token[0] == '0' && token[3] == '0') {
			resultado = "0";
		} else {
			resultado = "1";
		}
	}
	return resultado;
}//fin metodo evaluacion de subcadena
