// Carlos Emiliano Castro Trejo A01422062
// Estructura de Datos
// Proyecto implementa dos tipo de algoritmos de busqueda. El primero llamado FuerzaBruta el cual paso con paso busa lo dedesado
// el segundo llamado KMP, el cual crea una tabla con prefijos ya hechos y busca con base a esos

#include<iostream>
#include<string>
#include"FuerzaBruta.h"
#include "KMPTable.h"
#include<assert.h>
#include<fstream>

using namespace std;

int main() 
{
	// Variable entera que toma valor para elegir en el menu
	int eleccion = 0;

	// Variable string que toma valor del conjunto de datos en el cual se buscara el patron
	string textoDeDatos;

	// Variable string que toma valor del patron a buscar
	string patron;

	// Varibale intera que toma el valor del metodo a usar del algoritmo de busqueda
	int metodo = 0;

	cout << "Fuente del texto: \n";
	cout << "0. Salir\n";
	cout << "1. Teclea el usuario\n";
	cout << "2. Archivo\n";
	cin >> eleccion;
	if (eleccion == 1)
	{
		cout << "Ingresa el texto de datos completo: \n";
		string temp;
		getline(cin,temp);
		getline(cin,textoDeDatos);
	}
	cout << "Ingresa el Patron a buscar: \n";
	cin >> patron;
	cout << "Metodo a usar:\n";
	cout << "1. Fuerza Bruta\n";
	cout << "2. Knuth-Morris-Pratt\n";
	cin >> metodo;

	switch (eleccion)
	{
	case 0:
	{
		cout << "ADIOS\n";

	}break;
	case 1:
	{
		cout << "Opcion " << eleccion << endl;
		cout <<"Texto: "<< textoDeDatos<< endl;
		cout << "Patron: " << patron << endl << endl;;

		switch (metodo)
		{
		case 1:
		{
			FuerzaBruta busqueda;
			busqueda.searchAll(textoDeDatos, patron);
		}break;
		case 2:
		{
			KMPTable tabla(patron);
			tabla.KMP_table(patron);
			tabla.KMP_print(patron);
			tabla.checarExistente(textoDeDatos, patron);

		}break;
		default:
			break;
		}
	}break;
	case 2:
	{
		cout << "Opcion " << eleccion << endl;
		ifstream archivo;
		archivo.open("llenarDatos.csv");
		int x = 0, y = 0;
		if (archivo.is_open())
		{
			while (!archivo.eof())
			{
				getline(archivo, textoDeDatos);
			}

			archivo.close();
		}
		else
		{
			cout << "Archivo inexistente o faltan permisos para abrirlo" << endl;
		}


		
		switch (metodo)
		{
		case 1:
		{
			FuerzaBruta busqueda;
			busqueda.searchAll(textoDeDatos, patron);
		}break;
		case 2:
		{
			KMPTable tabla(patron);
			tabla.KMP_table(patron);
			tabla.KMP_print(patron);
			tabla.checarExistente(textoDeDatos, patron);
		}break;
		default:
			break;
		}
	}break;

	default:
		break;
	}
	system("pause");
}

