#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Stiva.h"

using namespace std;

void Stiva::adaugareStiva(Stiva *&stiva, Echipa ech) {
	Stiva *aux;
	aux = new Stiva;
	if (stiva == NULL) {
		aux->team = ech;
		aux->next = NULL;
		stiva = aux;
	} else {
		aux->team = ech;
		aux->next = stiva;
		stiva = aux;
	}
}

void Stiva::sortareStive(Stiva *&castigatori, Stiva *&invinsi, Coada *&coada) {

	Coada *p;
	p = coada;
	while (p!= NULL) {
		if (p->getEchipa1().getScor() > p->getEchipa2().getScor()) {
			adaugareStiva(castigatori, p->getEchipa1());
			adaugareStiva(invinsi, p->getEchipa2());
		} else {
			adaugareStiva(castigatori, p->getEchipa2());
			adaugareStiva(invinsi, p->getEchipa1());
		}
		p = p->getUrm();
	}
}


void Stiva::afisareStiva(ostream &dev, Stiva *& stiva) const {
	Stiva *aux = stiva;
	string s = "                                  -  ";
   int size = s.length();
   string nu;
	if (aux == NULL) dev << "stiva goala";
	while (aux != NULL) {
		s = "                                  -  ";
		nu = aux->team.getName();
		s.replace(0, nu.length(), nu);
		dev << s << fixed << setprecision(2) << aux->team.setScorNou() << endl;
		aux = aux->next;
	}
}

void Stiva::stergereStiva(Stiva *&stiva) { 
	Stiva *aux;
	aux = stiva;
	while (aux != NULL) {
		stiva = stiva->next;
		delete aux;
		aux = stiva;
	}
}

void Stiva::StivaInFisier(Stiva *&head) {
	fstream fisier("temp.dat", ios::out);
	if (!fisier)
		cout << "Eroare deschidere fisier ex 3" << endl;
	Stiva *element;
	element = head;
	while (element != NULL) {
		element->team.afisareEchipa(fisier);
		element = element->next;
	}
	fisier.close();
}


