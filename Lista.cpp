#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Lista.h"

using namespace std;

Lista::Lista() {
	/*cout << "constr fara param lista" << endl;*/
	next = NULL;
}

Lista::Lista(Echipa ech, Lista *nxt) {
	//cout << "constr cu param lista" << endl;
	echipa = ech;
	next = nxt;
}

Lista::~Lista() {
	//cout << "destr lista" << endl;
	
}

void Lista::creareLista(Lista*& head, fstream &fisier, bool c, int &n) {
	
	Echipa aux;
	Lista *a, *b;
	if (c == 0) {
		fisier >> aux;
		n = 8;
	} else {
		fisier >> n >> aux;
	}
	head = new Lista;
	head->echipa = aux;
	head->next = NULL;
	a = head;
	for (int i = 0; i < n-1; i++) {
		b = new Lista;
		fisier >> aux;
		b->echipa = aux;
		b->next = head;
		head= b;	
	}
	fisier.close();
}

void Lista::afisareLista(ostream &dev, Lista *&l) const {
	Lista *element;
	element = l;
	while (element != NULL) {
		dev << element->echipa.getName() << endl;
		element = element->next;
	}
}

int Lista::getNrEchipe() {
	ifstream fisier("d.in", ios::in);
	if (!fisier) 
		cout << "eroare deschidere fisier" << endl;
	int n;
	fisier >> n;
	return n;
}

float Lista::calculareScorMinim(Lista *&head) {
	Lista *aux;
	aux = head;
	float min = 1000;
	while (aux != NULL) {
		if (min > (aux->echipa).getScor()) {
			min = (aux->echipa).getScor();
		}
		aux = aux->next;
	}
	return min;
}

int Lista::getPutere (int n) {
	int i = 1;
	while (i <= n) 
		i = i * 2;
	i=i/2;
	cout<<i;
	return i;
}

void Lista::eliminareNod(Lista *&head) {
	Lista *a = head, *b = NULL;
	
	float min = calculareScorMinim(head);

	if (a != NULL && (a->echipa).getScor() == min) {
		head = a->next;
		delete a;
		return;
	}
	
	while (a != NULL && (a->echipa).getScor() != min ) {
		b = a;
		a = a->next;
	}
	if (a == NULL) return;
	b->next = a->next;
	delete a;	
}

void Lista::eliminareListaScoruriMici(Lista *&head, int &n) {
	Lista *aux;
	aux = head;
	int i = getPutere(n);
	while (i != n) {
		aux->eliminareNod(head);
		n--;
	}
}

void Lista::scriereListaInFisier(Lista*& head) {
	fstream fisier("temp.dat", ios::out);
	if (!fisier)
		cout << "Eroare deschidere fisier ex 3" << endl;
	Lista *element;
	element = head;
	while (element != NULL) {
		element->echipa.afisareEchipa(fisier);
		element = element->next;
	}
	fisier.close();
}

Lista* Lista::getNext() {
	return next;
}

Echipa Lista::getEchipa() {
	return echipa;
}

void Lista::stergereLista(Lista *&head) {
	Lista *aux;
	while (head != NULL) {
		aux = head->next;
		delete head;
		head = aux;
	}
	head = NULL;
}





