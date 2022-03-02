#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Coada.h"

class Stiva {
	Echipa team;
	Stiva *next;
	public:
		void adaugareStiva(Stiva *&, Echipa);
		void sortareStive(Stiva *&, Stiva *&, Coada *&);
		void afisareStiva(ostream &, Stiva *&) const;
		void stergereStiva(Stiva *&);
		void StivaInFisier(Stiva *&);
};


