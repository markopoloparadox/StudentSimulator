#include "Celija.h"
#include <iostream>


Celija::Celija(double _x, double _y) {
	x = _x;
	y = _y;
	id = dohvatiPozicijuUMrezi();
	tijelo.setSize(sf::Vector2f(sirinaCelije, visinaCelije));
	tijelo.setPosition(_x, _y);
	textura.loadFromFile("1.png");
	tijelo.setTexture(&textura);
}

void Celija::azuriraj() {

}

void Celija::prikazi(sf::RenderWindow* win) {
	for (auto elem : pozadinaSloj) {
		elem->prikazi(win);
	}
}
void Celija::promjeniBoju(unsigned int r, unsigned int g, unsigned int b) {
	tijelo.setFillColor(sf::Color(r, g, b));

}

void Celija::postaviProhodnost(bool var) {
	prohodan = var;
	if (var == false) {
		textura.loadFromFile("2.png");
	} else {
		textura.loadFromFile("1.png");
	}
}
