#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "ArboreBST.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	Lista *v, *head, *lista8;
	Coada *c, *prim;
	Arbore *a = NULL, *arb;
	Stiva *castigatori = NULL, *invinsi = NULL, *call;
	
	int n, m;
	int runda = 0;
	int task[5];
	
	fstream fin(argv[2], ios::in);
	fstream fcerinte(argv[1], ios::in);
	fstream fisier(argv[3], ios::out);
	if (!fin) 
		cout << "Eroare deschidere fisier d.in" << endl;
	if (!fisier) 
		cout << "Eroare deschidere fisier r.out" << endl;
	if (!fcerinte) 
		cout << "Eroare deschidere fisier c.in" << endl;
	
	for (int i = 0; i < 5; i++) {
		fcerinte >> task[i];
	}
		
	for (int i = 0; i < 5; i++) {
		switch (i) {
			case 0: {
				if (task[0] == 1) {
						v->creareLista(head, fin, 1, n);
						if (task[1] == 0) {
							v->afisareLista(fisier, head);
						}
				}
				break;
			}
			case 1: {
				if (task[1] == 1) {
					v->eliminareListaScoruriMici(head, n);
					v->afisareLista(fisier, head);
				}
				break;
			}
			case 2: {
				if (task[2] == 1) {
					v->scriereListaInFisier(head);
					fisier<<endl;
					while (n > 1) {
						c->getInfoFisier(prim, n);
						runda++;
						fisier << "--- ROUND NO:" << runda << endl;
						c->afisareCoada(fisier, prim);
						fisier << endl;
						call->sortareStive(castigatori, invinsi, prim);
						c->stergeCoada(prim);
						fisier << "WINNERS OF ROUND NO:" << runda << endl;
						call->afisareStiva(fisier, castigatori);
						if(n!=2)
						fisier << endl;
						call->stergereStiva(invinsi);
						call->StivaInFisier(castigatori);
						call->stergereStiva(castigatori);
						if (n == 16) {
							fstream r("temp.dat", ios::in);
							v->creareLista(lista8, r, 0, m);
						}
						n = n/2;
					}
				}
				break;
			}
			case 3: {
				if (task[3] == 1) {
					fisier<<endl;
					fisier << "TOP 8 TEAMS:" << endl;
					arb->listainArbore(lista8, a);
					arb->afisareArbore(fisier, a);
				}
				break;
			}
			case 4: {
				if (task[4] == 1) {
					
				}
				break;
			}
			default: {
				cout << "Error!" << endl;
				break;
			} 
		}
	}

	fcerinte.close();
	fin.close();
	fisier.close();
	
	return 0;
}
