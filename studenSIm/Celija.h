#pragma once
#include <vector>
#include "SFML\Graphics.hpp"
#include "Predmet.h"
class Celija : public Objekt{
public:
	Celija(double, double);
	~Celija() {};

	//Potrebne metode koja svaka klasa treba implementirati
	void azuriraj() override;
	void prikazi(sf::RenderWindow*) override;

	//Dohvaca se relativni ID
	unsigned int dohvatiId() { return id; }
		
	//Postavljanje prohodnosti
	void postaviProhodnost(bool);
	bool dohvatiProhodnost() { return prohodan; }


	void ubaciUPozadinaSloj(Predmet* _predmet) { pozadinaSloj.push_back(_predmet); postaviProhodnostAuto();}

private:
	//Slojevi za prikaz
	std::vector<Predmet* > pozadinaSloj;

	void postaviProhodnostAuto();
	bool prohodan = true;
};

