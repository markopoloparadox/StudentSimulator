#pragma once
#include "Objekt.h"
#include "Tip.h"
class Predmet : public Objekt {
public:
	Predmet(nlohmann::json, unsigned int);
	~Predmet();

	void azuriraj() {};
	void prikazi(sf::RenderWindow* win) { win->draw(*tijelo); };
	void postaviXY(double, double);

	bool dohvatiProhodnost() { return tip.prohodan; }

private:
	Tip tip;
	std::unique_ptr<sf::RectangleShape> tijelo;
	sf::Texture tekstura;
};

