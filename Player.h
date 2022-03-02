#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class Player {
   string firstName;
   string secondName;
   int points;
   public:
   	Player();
   	Player(string, string, int);
   	~Player();
   	friend ostream& operator<<(ostream &, Player&);
   	friend istream& operator>>(istream &, Player&);
   	int getPoints();
   	int marirePoints();
};	
