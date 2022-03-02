#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Coada.h"

using namespace std;

void Coada::getInfoFisier(Coada*& head, int &n) {
	fstream fisier("temp.dat", ios::in | ios::out);
	if (!fisier)
		cout << "Eroare deschidere fisier ex 3" << endl;
		
	Coada *a, *b;
	Echipa aux1, aux2;
	fisier >> aux1 >> aux2;
	head = new Coada;
	head->echipa1 = aux1;
	head->echipa2 = aux2;
	head->urm = NULL;
	a = head;
	for (int i = 0; i < n/2-1; i++) {
		b = new Coada;
		fisier >> aux1;
		fisier >> aux2;
		b->echipa1 = aux1;
		b->echipa2 = aux2;
		b->urm = NULL;
		a->urm = b;
		a = b;
	}
	
	fisier.close();
}

void Coada::afisareCoada(ostream &dev, Coada*& head) {
	Coada *elem = head;
	while (elem != NULL) {
		string nu1="                                 -";
		string nu2="                                 ";
		
		nu1.erase(0, elem->echipa1.getName().length());
		nu2.erase(nu2.length() - elem->echipa2.getName().length(), nu2.length());
		
		dev << elem->echipa1 << nu1;
		dev << nu2 << elem->echipa2 << endl;	
		
		elem =  elem->urm;
	}
}

Coada* Coada::getUrm() {
	return urm;
}

Echipa Coada::getEchipa1() {
	return echipa1;
}

Echipa Coada::getEchipa2() {
	return echipa2;
}

void Coada::stergeCoada(Coada*& coada) {
	Coada *aux;
	aux = coada;
	while (aux != NULL) {
		coada = coada->urm;
		delete aux;
		aux = coada;
	}
	
}



