#include "Celija.h"
#include <iostream>


Celija::Celija() : id(brojCelijaKreiranih++) {
	tijelo.setSize(sf::Vector2f(w,h));

}

Celija::Celija(double _x, double _y): id(brojCelijaKreiranih++) {
	tijelo.setSize(sf::Vector2f(w, h));
	tijelo.setPosition(_x, _y);
	tijelo.setFillColor(sf::Color(50, 50, 50));
}


Celija::~Celija() {
	std::cout << id << ":(C) je dealocirana!";
}

void Celija::azuriraj() {


}

void Celija::prikazi(sf::RenderWindow* win) {
	win->draw(tijelo);
}

unsigned int Celija::dohvatiId() {
	return id;
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

unsigned int Celija::brojCelijaKreiranih = 0;
