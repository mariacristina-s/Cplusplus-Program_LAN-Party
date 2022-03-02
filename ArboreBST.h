#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Stiva.h"

class Arbore {
	Echipa echipa;
	Arbore *left, *right;
	public:
		Arbore(Echipa);
		Arbore();
		Arbore* adaugareArbore(Arbore *&, Echipa);
		void afisareArbore(ostream &,Arbore *&);
		void listainArbore(Lista*&, Arbore *&);
		
};




