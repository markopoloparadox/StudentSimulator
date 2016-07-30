#include "Mapa.h"
#include "PodatkovniSloj.h"
#include "jsonExtend.h"
#include "Objekt.h"

Mapa::Mapa() {
	ucitajMapu();
}

Mapa::~Mapa() {}

void Mapa::ucitajMapu() {
	nlohmann::json j = PodatkovniSloj::dohvatiVrijednostDat("mapa.json");
	parsirajPostavke(j);
	parsirajCelije(j);
}

void Mapa::parsirajPostavke(nlohmann::json j) {
	Objekt::sirinaCelije = Mapa::sirinaCelije = j["tilewidth"].get<unsigned int>();
	Objekt::visinaCelije = Mapa::visinaCelije = j["tileheight"].get<unsigned int>();
	Objekt::stupci = Mapa::stupci = j["width"].get<unsigned int>();;
	Objekt::redovi = Mapa::redovi = j["height"].get<unsigned int>();;
}

void Mapa::parsirajCelije(nlohmann::json _j) {
	auto mrezaCelija = _j["layers"][0]["data"];

	celije.reserve(stupci*redovi);
	predmeti.reserve(mrezaCelija.size());

	for (auto i = 0; i < redovi; ++i) {
		for (auto j = 0; j < stupci; ++j) {
			celije.push_back(std::make_unique<Celija>(j * Objekt::sirinaCelije, i * Objekt::visinaCelije));
			predmeti.push_back(std::make_unique<Predmet>(_j, mrezaCelija[i*stupci + j]));
			predmeti.back()->postaviXY(j * sirinaCelije, i * visinaCelije);
			if (!predmeti.back()->dohvatiProhodnost())
				celije.back()->postaviProhodnost(false);
			celije.back()->ubaciUPozadinaSloj(predmeti.back().get());
			aZvijezda.kreirajACeliju(celije.back().get());
		}
	}
}

unsigned int Mapa::sirinaCelije = 0;
unsigned int Mapa::visinaCelije = 0;
unsigned int Mapa::stupci = 0;
unsigned int Mapa::redovi = 0;