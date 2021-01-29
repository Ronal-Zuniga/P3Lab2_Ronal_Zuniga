#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void imprimirArreglo(int []);
void arregloOrdenado(int [], int);

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
			string cadena;
			cout << "Ingrese la cadena a evaluar: ";
			cin >> cadena;
			for (int i = 0; i < cadena.length(); i++) {

			}
		}//fin opcion 1

		if(opcion == 2) {
			cout << "Arreglo en orden Ascendente" << endl;
			cout << "Arreglo Original" << endl;
			int arr [20];
			srand((unsigned)time(0));
			for(int i = 0; i < 20; i++) {
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
}


void arregloOrdenado(int arreglo[], int tamano) {
	if(tamano == 1) {
		return;
		imprimirArreglo(arreglo);
	}
	for (int i = 0; i < tamano - 1; i++){
		if (arreglo[i] > arreglo[i+1]) {
			int temp = arreglo[i];
			arreglo[i] = arreglo[i+1];
			arreglo[i+1] = temp;
		}
	}
	imprimirArreglo(arreglo);
	arregloOrdenado(arreglo, tamano-1);
	//cout << endl;
}

void imprimirArreglo(int arreglo[]) {
	for	(int i = 0; i < 20; i++) {
		cout << arreglo [i] << "  ";
	}
	cout << endl;
}
