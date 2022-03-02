#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "ArboreBST.h"

using namespace std;

Arbore::Arbore(Echipa ech) {
	echipa = ech;
	left = right = NULL;
}

Arbore::Arbore():left(NULL), right(NULL) {
	
}

Arbore* Arbore::adaugareArbore(Arbore *&tree, Echipa ech) {
	Arbore *aux;
	aux = tree;
	//cout << " test adaugare arbore initial " << endl;
	if (aux == NULL) {
		aux = new Arbore;
		aux->echipa = ech;
		aux->left = aux->right = NULL;
		//cout << "adaugare arbore aici aux==null test" <<endl;
	} 	else if (ech.getScor() < aux->echipa.getScor())
			aux->left = adaugareArbore(aux->left, ech);
 		else if (ech.getScor() > aux->echipa.getScor())
 			aux->right = adaugareArbore(aux->right, ech);
		else if (ech.getScor() == aux->echipa.getScor()) {
			if (ech.getName() < aux->echipa.getName()) 
				aux->left = adaugareArbore(aux->left, ech);
			else 
				aux->right = adaugareArbore(aux->right, ech);
		}
	//cout << "test arbore";
	return aux;
}

void Arbore::afisareArbore(ostream &dev, Arbore *&tree) {
	if (!tree) return;
	afisareArbore(dev, tree->right);
	string lines = "                                  -  ";
	string nu = tree->echipa.getName();
	lines.replace(0, nu.length(), nu);
	dev << lines << fixed << setprecision(2) << tree->echipa.getScor() << endl;
	afisareArbore(dev, tree->left);
}

void Arbore::listainArbore(Lista*& head, Arbore *&tree) {
	Lista *aux = head;
	while (aux != NULL) {
		tree = adaugareArbore(tree, aux->getEchipa());
		aux = aux->getNext();
	}
	//cout << "test lista in arbore" << endl;
}








