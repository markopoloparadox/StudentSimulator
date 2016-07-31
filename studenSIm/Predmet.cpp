#include "Predmet.h"

Predmet::Predmet(nlohmann::json _j, unsigned int Id, sf::Texture* tex) {
	tip.popuni(_j, Id);
	ime = tip.ime;

	tijelo.setSize(sf::Vector2f(tip.sirina, tip.visina));
	tijelo.setTexture(tex);

}

Predmet::~Predmet() {}

void Predmet::postaviXY(double _x, double _y) {
	x = _x; 
	y = _y;
	tijelo.setPosition(x, y);
}
