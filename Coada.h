#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Lista.h"

using namespace std;

class Coada {  
   Echipa echipa1, echipa2;  
   Coada *urm; 
	public: 
		void getInfoFisier(Coada*&, int &);
		void afisareCoada(ostream &,Coada*&);
		Coada* getUrm();
		Echipa getEchipa1();
		Echipa getEchipa2();
		void stergeCoada(Coada*&);
};
