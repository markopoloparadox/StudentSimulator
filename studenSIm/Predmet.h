#pragma once
#include "Objekt.h"
#include "Tip.h"
class Predmet : public Objekt {
public:
	Predmet(nlohmann::json, unsigned int, sf::Texture*);
	~Predmet();

	void azuriraj() {};
	void prikazi(sf::RenderWindow* win) { win->draw(tijelo); };
	void postaviXY(double, double);

	bool dohvatiProhodnost() { return tip.prohodan; }
	std::string dohvatiIme() { return ime; }

private:
	Tip tip;
	sf::RectangleShape tijelo;
	std::string ime;

	friend bool operator<(const Predmet& lhs, const Predmet& rhs) {
		return lhs.ime < rhs.ime;
	}
};