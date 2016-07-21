#pragma once
#include "Vrsta.h"
#include "Objekt.h"
#include "StabloPonasanja.h"
#include <SFML\Graphics.hpp>
#include <memory>
#include "AZvijezda.h"


class Agent : public Objekt {
public:
	Agent(int, AZvijezda*);
	Agent(std::string = "", std::string = "");
	~Agent();

	void kreirajVrstu(std::string);

	void azuriraj();
	void prikazi(sf::RenderWindow*);

	unsigned int nalazimSe(unsigned int s) {
		unsigned int w = 64;
		unsigned int h = 64;
		unsigned int celijaId = std::floor(x / w) + std::floor(y / h) * s;
		return celijaId;
	}

	void postaviStabloP(StabloPonasanja::Cvor* _cvor) { sp.postaviGlavu(_cvor); }

	void postaviCilj(int _celijaCilj) {
		celijaCilj = _celijaCilj;
	}

	bool odiDo(unsigned int celijaId);
	
	AZvijezda* aZvijezda;
	int celijaCilj = -1;
private:
	static nlohmann::json sveVrsteJSON;

	std::string ime = "";
	std::string prezime = "";
	int starost = -1;
	sf::CircleShape tijelo;
	
	Vrsta vrsta;
	StabloPonasanja sp;
	std::vector<std::unique_ptr<sf::CircleShape>> pratnja;
	double tretBrzina = 1;

	double r = rand() % 255;
	double g = rand() % 255;
	double b = rand() % 255;

};

