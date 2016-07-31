#include "Celija.h"
#include <iostream>


Celija::Celija(double _x, double _y) {
	x = _x;
	y = _y;
	id = dohvatiPozicijuUMrezi();
}

void Celija::azuriraj() {

}

void Celija::prikazi(sf::RenderWindow* win) {
	for (auto& elem : pozadinaSloj) {
		elem->prikazi(win);
	}
}

void Celija::postaviProhodnost(bool var) {
	prohodan = var;
}
