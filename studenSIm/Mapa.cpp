#include "Mapa.h"
#include "PodatkovniSloj.h"
#include "jsonExtend.h"
#include "Objekt.h"

void Mapa::inicijaliziraj() {
	jPos = PodatkovniSloj::dohvatiVrijednostDat("mapa.json");
	kreirajPostavke();
	kreirajCelije();
	kreirajTexture();
	kreirajPredmete();

}

void Mapa::kreirajPostavke() {
	Objekt::sirinaCelije = jPos["tilewidth"].get<unsigned int>();
	Objekt::visinaCelije = jPos["tileheight"].get<unsigned int>();
	Objekt::stupci = jPos["width"].get<unsigned int>();;
	Objekt::redovi = jPos["height"].get<unsigned int>();;
}

void Mapa::kreirajCelije() {
	celije.reserve(Objekt::stupci*Objekt::redovi);

	for (auto i = 0; i < Objekt::redovi; ++i) {
		for (auto j = 0; j < Objekt::stupci; ++j) {
			celije.push_back(std::make_unique<Celija>(j * Objekt::sirinaCelije, i * Objekt::visinaCelije));
			aZvijezda.kreirajACeliju(celije.back().get());
		}
	}

}

void Mapa::kreirajTexture() {
	std::set<unsigned int> iskoristene;
	auto podaci = jPos["layers"][0]["data"];

	for (unsigned int elem : podaci) {
		auto poz = iskoristene.find(elem);
		if (poz == iskoristene.end() && elem != 0) {
			auto tex = std::make_unique<sf::Texture>();
			std::string sId = std::to_string(elem - 1);
			std::string putanja = jPos["tilesets"][0]["tiles"][sId]["image"];
			tex->loadFromFile(putanja);
			teksture.insert({ elem, std::move(tex)});
			iskoristene.insert(elem);
		}
	}
}

void Mapa::kreirajPredmete() {
	auto podaci = jPos["layers"][0]["data"];

	for (auto i = 0; i < Objekt::redovi; ++i) {
		for (auto j = 0; j < Objekt::stupci; ++j) {
			unsigned int elem = podaci[i];
			if (elem != 0) {
				auto predmet = std::make_unique<Predmet>(jPos, elem, teksture[elem].get());
				predmet->postaviXY(j * Objekt::visinaCelije, i * Objekt::sirinaCelije);
				celije[i * Objekt::stupci + j]->ubaciUPozadinaSloj(predmet.get());
				predmeti.insert(std::move(predmet));
			}
		}
	}
}