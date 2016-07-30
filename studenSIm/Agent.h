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
	void azuriraj() override;
	void prikazi(sf::RenderWindow*) override;

	//Postavljanje umjetne inteligencije
	void postaviStabloP(StabloPonasanja::Cvor* _cvor) { sp.postaviGlavu(_cvor); }

	void postaviCilj(int _celijaCilj) { celijaCilj = _celijaCilj; }

	bool odiDo(unsigned int celijaId);
	
	void postaviText (std::string sadrzaj) override;
	
	unsigned int dosada = 0;

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
	double tretBrzina = 15;

	double r = rand() % 255;
	double g = rand() % 255;
	double b = rand() % 255;
};

