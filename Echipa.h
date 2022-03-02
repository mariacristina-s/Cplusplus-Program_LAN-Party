#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Player.h"

using namespace std;

class Echipa {
	int nr;
	string nume;
	Player *players;
	public:
		Echipa();
		Echipa(int, string, Player*);
		~Echipa(); 
		Echipa(const Echipa &);
		Echipa& operator=(const Echipa&);
		friend ostream& operator<<(ostream &, const Echipa&);
   	friend istream& operator>>(istream &, Echipa&);
   	float getScor();
   	void afisareEchipa(ostream&);
   	float setScorNou();
   	string getName();
   	
};
