#pragma once
#include <vector>
#include "SFML\Graphics.hpp"
#include "Objekt.h"
class Celija : public Objekt{
public:
	Celija(double, double);
	~Celija() {};

	//Potrebne metode koja svaka klasa treba implementirati
	void azuriraj();
	void prikazi(sf::RenderWindow*);

	//Dohvaca se relativni ID
	unsigned int dohvatiId() { return id; }
		
	//Postavljanje prohodnosti
	void postaviProhodnost(bool);
	bool dohvatiProhodnost() { return prohodnost; }

	//Promijena boja
	void promjeniBoju(unsigned int, unsigned int, unsigned int);
	

private:
	sf::RectangleShape tijelo;

	bool prohodnost = true;
};

