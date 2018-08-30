#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include "Registro.h"
using namespace std;
class KMPTable
{
public:
	
	// Vector de objetos Registro, sirve como arreglo
	vector<Registro> Table;

	// constructor
	KMPTable(string);		

	// despliega contenido de la tabla
	void KMP_print(string);	

	// procesa columna tablaKMP[H]
	void KMP_table(string);	

	// regresa ith entrada de tablaKMP
	Registro KMPEntry(string, int);	

	/* Checar Exitente: Metodo encargado de checar si existe el patron
		Input: variable string const que toma valor del texto entero al cual se va a buscar el patron, variable string const que toma valor del patron
		Output: Ninguno
	*/
	void checarExistente(string,string); 

	// Destructor
	~KMPTable();

};
