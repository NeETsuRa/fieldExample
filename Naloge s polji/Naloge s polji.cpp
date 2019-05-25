// Naloge s polji.cpp : Defines the entry point for the console application.


#include "stdafx.h" //ne smemo ga izbrisat in vse moramo pisati za tem
#include <iostream>
#include "Polje.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    CPolje p(10);
	p.napolniLinearno();
	p.izpis();
	cout<<endl;
	cout << p.bisekcija(5);
	cout<<endl;


	
	p.premesaj();
	p.izpis();
	cout<<endl;
	p.hitrourejanje();
	p.izpis();
	cout<<endl;
	cout<<p.stRazlicnih();
	cout<<endl;
	

	cin.ignore();
	cin.get();
	
}

