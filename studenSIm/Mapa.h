#pragma once
#include "Celija.h"
#include "AZvijezda.h"
#include "json.h"
#include "Predmet.h"
#include <memory>
#include <set>
//#include <set>

class Mapa {
public:
	Mapa() {};
	~Mapa() {};

	void inicijaliziraj();

	std::vector<std::unique_ptr<Celija>> celije;
	AZvijezda aZvijezda;

private:
	void kreirajCelije();
	void kreirajTexture();
	void kreirajPredmete();
	void kreirajPostavke();
	


	std::multiset<std::unique_ptr<Predmet>> predmeti;
	std::unordered_map<unsigned int, std::unique_ptr<sf::Texture>> teksture;
	nlohmann::json jPos;
};

