#include "FuerzaBruta.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

FuerzaBruta::FuerzaBruta()
{
}

void FuerzaBruta::searchAll(string const& text, string const& patron) 
{
	// text y patron son direcciones constantes donde se almacenan strings
	// mecanismo que asegura y optimiza
	int const endPos = (text.size() - patron.size() + 1);	
	int num = 0;
	int result = 0;
	for (int x = 0; x <endPos; x++) 
	{
		num++;
		result = text.compare(x, patron.size(), patron);

		cout << setw(2)<< x<<setw(3) << "|" <<text[x]<<text[x+1]<<text[x+2]<<"|"<<setw(5)<<result;
		
		if (result == 0) 
		{
			cout << "<---- MATCH";
		}
		cout << endl;
	
	}
	cout << "Total de comparaciones: " << num<<endl;
	cout << "Total de chars comparados: " <<( text.size()-patron.size()+1)*patron.size() << endl<<endl;



}

FuerzaBruta::~FuerzaBruta()
{
}
