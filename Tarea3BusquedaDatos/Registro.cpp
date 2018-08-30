#include "Registro.h"

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

Registro::Registro()
{
}


Registro::~Registro()
{

}

string Registro::getHead()
{
	return head;
}

int Registro::getH()
{
	return H;
}

int Registro::getKMP()
{
	return KMP;
}

ostream& operator<< (ostream& out, Registro const& r)
// Sobrecarga operador << de la clase Registro
{
	out << setw(r.head.length()) << r.head << setw(r.pat.length() - r.head.length() + 1) << " " << setw(3) << r.H << setw(3) << r.KMP << endl;
	return out;
}
