#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Player.h"

using namespace std;

Player::Player() {
	//cout << "constr fara param player" << endl;
	firstName = "";
	secondName = "";
	points = 0;
}

Player::Player(string nume, string prenume, int puncte) {
	//cout << "constr cu param player" << endl;
	firstName = nume;
	secondName = prenume;
	points = puncte;
}

Player::~Player() {
	//cout << "destr player" << endl;
}

ostream& operator<<(ostream &dev, Player &p) {
	dev << p.firstName << " ";
	dev << p.secondName << " ";
	dev << p.points;
	return dev;
}

istream& operator>>(istream &devi, Player &p) {
	devi >> p.firstName;
	devi >> p.secondName;
	devi >> p.points;
	return devi;
}

int Player::getPoints() {
	return points;
}

int Player::marirePoints() {
	this->points = this->points + 1;
	return points;
}


