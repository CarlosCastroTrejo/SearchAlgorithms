#include "KMPTable.h"


#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

KMPTable::~KMPTable()
{
}

KMPTable::KMPTable(string s)
{
	Registro aux;
	string saux = "";
	for (size_t j = 0; j <= s.length(); j++)
	{
		// Crea m+1 renglones para tablaKMP para m=s.length
		aux.pat = s;	// inicializa patrón
		aux.head = saux;	// inicialilza valor de head
		aux.H = j;		// inicializa H (longitude del head)
		if (j == 0)
			aux.KMP = -1;	// se coloco un -1 para la posicion 0
		else
			aux.KMP = 0;
		saux = saux + s[j];
		Table.push_back(aux);// inserta renglón en tablaKMP
	}
}

void KMPTable::KMP_print(string s)
{
	cout << "\nTabla KMP, patron= " << s << endl;
	Registro aux;
	vector<Registro>::iterator iter = Table.begin();
	while (iter != Table.end())
	{
		cout << *iter << endl;
		iter++;
	}
}

void KMPTable::KMP_table(string patron)
{
	int m = patron.length(), k;
	for (int i = 1; i <= m; i++)
	{
		k = Table[i - 1].KMP;
		while (k >= 0)
			if (patron[k] == patron[i - 1])
				break;
			else
				k = Table[k].KMP;
		Table[i].KMP = k + 1;
	}
}


Registro KMPTable::KMPEntry(string s, int i)
{
	Registro aux;
	aux.head = "";
	aux.H = 0;
	aux.KMP = 0;
	if (i >= 0 && i < Table.size())	// imprime renglones válidos
		aux = Table[i];
	else
		cout << " Address " << i << " out of range" << endl;
	return aux;
}

void KMPTable::checarExistente(string texto,string patron)
{
	int desplazamiento = 0;
	bool founded = false;
	int num = 0;
	while (!founded)
	{
		founded = true;
		vector<Registro>::iterator iter = Table.begin();
		int x = 1;

		while (iter != Table.end())
		{
			if (Table[x].getHead() == patron) 
			{
				iter = Table.end();
				founded = true;
				cout << "Si esta el patron" << endl;
				cout << "Numero total de comparaciones: " << num << endl<<endl;
				break;

			}

			num++;
			if (texto.compare(desplazamiento,Table[x].getHead().size(), Table[x].getHead())==0)
			{
				cout << "si esta: " << Table[x].getHead() << endl;
				iter++;
				x++;
			}
			else 
			{
				cout << "ya no esta: " << Table[x].getHead() << endl;
				cout << desplazamiento << endl;
				founded = false;
				iter = Table.end();
				break;
			}
		}
		
		if (Table[x].getKMP()==0) 
		{
			desplazamiento += 1;
		
		}
		else 
		{
			desplazamiento = Table[x].getH() - Table[x].getKMP();

		}

	}


}
