#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Echipa.h"

using namespace std;

class Lista {
	Echipa echipa;
	Lista *next;
	public:
		Lista();
		Lista(Echipa, Lista*);
		~Lista();
		void creareLista(Lista*&, fstream&, bool, int &);	
		void afisareLista(ostream &, Lista *&) const;
		float calculareScorMinim(Lista *&);
		int getPutere(int);
		int getNrEchipe();
		Echipa getEchipa();
		void eliminareNod(Lista*&);
		void eliminareListaScoruriMici(Lista *&, int &);
		void scriereListaInFisier(Lista*&);
		Lista* getNext();
		void stergereLista(Lista *&);
};
