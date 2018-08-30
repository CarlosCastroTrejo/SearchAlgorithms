#pragma once
#include<iostream>
using namespace std;
class Registro
{
	// Estructura de datos para la tabla KMP
public:
	Registro();
	~Registro();
	string head; // Descripción de la cabeza
	string pat;	// Patrón
	int H;		// Longitud de de la cabeza
	int KMP;    // Punto del inicio de la nueva búsqueda
	friend ostream& operator<< (ostream& out, Registro const& r);

	string getHead();
	int getH();
	int getKMP();

};

