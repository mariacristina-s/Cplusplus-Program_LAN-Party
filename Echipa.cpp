#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Echipa.h"

using namespace std;

Echipa::Echipa() {
	//cout << "constr fara param echipa" << endl;
	nr = 0;
	nume = "";
	players = NULL;
}

Echipa::Echipa(int n, string nu, Player* ju) {
	//cout << "constr cu param echipa" << endl;
	nr = n;
	nume = nu;
	if (ju != NULL) {
		players = new Player [nr];
		for (int i = 0; i < nr; i++) {
			players[i] = ju[i];
		}
	} else players = NULL;
}

Echipa::~Echipa() {
	//cout << "destr echipa" << endl;
	delete [] players;
}

Echipa::Echipa(const Echipa &ech) {
	//cout << "constr copiere echipa" << endl;
	nr = ech.nr;
	nume = ech.nume;
	if ( ech.players != NULL) {
		players = new Player [nr];
		for (int i = 0; i < nr; i++) {
			players[i] = ech.players[i];
		}
	} else players = NULL;
}

Echipa& Echipa::operator=(const Echipa&ech) {
	//cout << "operator egal echipa" << endl;
	if (this != &ech) {
		nr = ech.nr;
		nume = ech.nume;
		if ( ech.players != NULL) {
			players = new Player [nr];
			for (int i = 0; i < nr; i++) {
				players[i] = ech.players[i];
			}
		} else players = NULL;
	}
	return *this; 
}

ostream& operator<<(ostream &dev, const Echipa &e) {
//	dev << "Numar: " << e.nr << " ";
	
	dev << e.nume;
/*	if (e.players != NULL)
		for (int i = 0; i < e.nr; i++) {
			cout << " test 4 " << endl;
			dev << e.players[i] << endl;
			
		}*/
	return dev;
}

void Echipa::afisareEchipa(ostream &dev) {
	dev << nr << " " << nume << endl;
	if (players != NULL)
		for (int i = 0; i < nr; i++) {
			dev << players[i] << endl;
	}
}


istream& operator>>(istream &devi, Echipa &e) {
	string aux;
	devi >> e.nr;
	getline(devi, aux);
	if (aux[aux.length()-1] == ' ') {
		aux.erase(aux.length()-1, aux.length());
	}
	e.players = new Player[e.nr];
	aux.erase(0,1);
	e.nume = aux;
	for (int i = 0; i < e.nr; i++) {
		devi >> e.players[i];
	}
	return devi;
}

float Echipa::getScor() {
	float s = 0;
	for (int i = 0; i < nr; i++) {
		s = s + players[i].getPoints();
	}
	return s / nr;
}

float Echipa::setScorNou() {
	float s = 0;
	for (int i = 0; i < nr; i++) {
		s = s + players[i].marirePoints();
	}
	return s / nr;
}

string Echipa::getName() {
	return nume;
}

