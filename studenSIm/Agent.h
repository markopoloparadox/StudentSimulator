#pragma once
#include "Vrsta.h"
#include "Objekt.h"
#include "StabloPonasanja.h"
#include "AZvijezda.h"

class Agent : public Objekt {
public:
	Agent(AZvijezda*);
	~Agent();

	//Potrebne metode koja svaka klasa treba implementirati
	void azuriraj();
	void prikazi(sf::RenderWindow*);


	void postaviStabloP(StabloPonasanja::Cvor* _cvor) { sp.postaviGlavu(_cvor); }

	void postaviCilj(int _celijaCilj) {
		celijaCilj = _celijaCilj;
	}

	bool odiDo(unsigned int celijaId);
	
	AZvijezda* aZvijezda;
	int celijaCilj = -1;


	const double XCilj() const { return xCilj; }
	const double YCilj() const { return yCilj; }



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

	double xCilj = -1;
	double yCilj = -1;

};

