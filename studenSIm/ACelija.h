#pragma once
#include "Celija.h"

class ACelija : public Objekt {
public:
	ACelija(Celija*);
	~ACelija() {};

	void resetiraj();

	unsigned int dohvatiF();

	unsigned int dohvatiG();
	unsigned int dohvatiId();

	void izracunaj(ACelija* _roditelj, unsigned int);


	bool prohodan();
	ACelija* roditelj = nullptr;

private:
	//H heuristicno
	unsigned int H = 0;
	unsigned int izracunajH8(unsigned int);
	unsigned int izracunajH4(unsigned int);

	//Cijena dolaska
	unsigned int G = 0;
	unsigned int izracunajG();

	//Sveukupna cijena
	unsigned int F = 0;
	unsigned int izracunajF(unsigned int);

	

	Celija* celija = nullptr;
	ACelija* noviRoditelj = nullptr;
};

