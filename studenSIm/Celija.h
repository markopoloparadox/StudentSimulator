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

	//Promijena boja
	void promjeniBoju(unsigned int, unsigned int, unsigned int);

	void ubaciUPozadinaSloj(Predmet* _predmet) { pozadinaSloj.push_back(_predmet); }
	void ubaciUSrednjiSloj(Predmet* _predmet) { srednjiSloj.push_back(_predmet); }
	void ubaciUIznadSloj(Predmet* _predmet) { iznadSloj.push_back(_predmet); }
	

private:
	sf::RectangleShape tijelo;
	sf::Texture textura;


	//Slojevi za prikaz
	std::vector<Predmet* > pozadinaSloj;
	//U slijedu y koordinata
	std::vector<Predmet* > srednjiSloj;
	std::vector<Predmet* > iznadSloj;
	bool prohodan = true;
};

