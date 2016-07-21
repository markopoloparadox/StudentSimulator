#pragma once
#include <vector>
#include "SFML\Graphics.hpp"
class Celija {
public:
	Celija();
	Celija(double, double);
	~Celija();

	void azuriraj();
	void prikazi(sf::RenderWindow*);
	unsigned int dohvatiId();
	bool dohvatiProhodnost() { return prohodnost; }

	void promjeniBoju(unsigned int, unsigned int, unsigned int);
	void postaviProhodnost(bool);

private:
	unsigned int id = 0;
	unsigned int w = 64;
	unsigned int h = 64;

	double xCentar = -1;
	double yCentar = -1;

	bool prohodnost = true;

	sf::RectangleShape tijelo;

	static unsigned int brojCelijaKreiranih;
};

