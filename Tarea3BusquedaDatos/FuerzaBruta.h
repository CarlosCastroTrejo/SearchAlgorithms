#pragma once
#include<iostream>
#include<string>
using namespace std;
class FuerzaBruta
{
public:
	// Constructor
	FuerzaBruta();

	/*Search All
		Input: variable string const que toma valor del texto entero al cual se va a buscar el patron, variable string const que toma valor del patron
		Output: Ninguno
	*/
	void searchAll(string const&,string const&);

	// Destructor
	~FuerzaBruta();
};

