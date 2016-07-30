#include "Predmet.h"

Predmet::Predmet(nlohmann::json j, unsigned int Id) {
	tip.popuni(j, Id);

	tijelo = std::make_unique<sf::RectangleShape>();
	tijelo->setSize(sf::Vector2f(sirinaCelije, visinaCelije));

	std::string sId = std::to_string(Id - 1);
	std::string putanja = j["tilesets"][0]["tiles"][sId]["image"];

	tekstura.loadFromFile(putanja);
	tijelo->setTexture(&tekstura);
}

Predmet::~Predmet() {}

void Predmet::postaviXY(double _x, double _y) {
	x = _x; 
	y = _y;
	tijelo->setPosition(x, y);

}
