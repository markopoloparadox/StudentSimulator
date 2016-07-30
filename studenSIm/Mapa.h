#pragma once
#include "Celija.h"
#include "AZvijezda.h"
#include "json.h"
#include "Predmet.h"
#include <memory>
//#include <set>

class Mapa {
public:
	Mapa();
	~Mapa();

	//Broj æelija po stupcu i redovima
	static unsigned int redovi;
	static unsigned int stupci;

	//Veliæina æelijeu
	static unsigned int sirinaCelije;
	static unsigned int visinaCelije;

	std::vector<std::unique_ptr<Celija>> celije;
	AZvijezda aZvijezda;

private:
	void ucitajMapu();
	void parsirajPostavke(nlohmann::json j);
	void parsirajCelije(nlohmann::json j);

	std::vector<std::unique_ptr<Predmet>> predmeti;
};

