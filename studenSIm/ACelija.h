#pragma once
#include "Celija.h"
class ACelija {
public:
	ACelija();
	ACelija(Celija*, unsigned int, unsigned int);
	~ACelija();

	void resetiraj();

	unsigned int izracunajH(unsigned int);
	unsigned int izracunajG();
	unsigned int izracunajF(unsigned int);
	unsigned int dohvatiF();
	unsigned int dohvatiG();
	unsigned int dohvatiId();
	void postaviF(unsigned int);
	void postaviG(unsigned int);

	void izracunaj(ACelija* _roditelj, unsigned int);


	bool prohodan();
	ACelija* roditelj = nullptr;

private:
	unsigned int H = 0;
	unsigned int G = 0;
	unsigned int F = 0;

	Celija* celija = nullptr;
	ACelija* noviRoditelj = nullptr;
	unsigned r;
	unsigned s;
};

