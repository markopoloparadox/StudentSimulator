#include "Celija.h"
#include <iostream>


Celija::Celija(double _x, double _y) {
	id = brojCelija++;
	tijelo.setSize(sf::Vector2f(sirinaCelije, visinaCelije));
	tijelo.setPosition(_x, _y);
	tijelo.setFillColor(sf::Color(50, 50, 50));
}

void Celija::azuriraj() {

}

void Celija::prikazi(sf::RenderWindow* win) {
	win->draw(tijelo);
}
void Celija::promjeniBoju(unsigned int r, unsigned int g, unsigned int b) {
	tijelo.setFillColor(sf::Color(r, g, b));

}

void Celija::postaviProhodnost(bool var) {
	prohodnost = var;
	if (var == false) {
		promjeniBoju(255, 255, 255);
	} else {
		promjeniBoju(50, 50, 50);
	}
}

unsigned int Celija::brojCelija = 0;
