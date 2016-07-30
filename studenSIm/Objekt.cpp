#include "Objekt.h"
#include <iostream>


Objekt::Objekt() : stvarniId(brojObjekata++) {
	
}
Objekt::~Objekt() {}

void Objekt::postaviXY(double _x, double _y) { x = _x; y = _y; }

unsigned int Objekt::dohvatiPozicijuUMrezi() {
	return (unsigned int)(std::floor(x / sirinaCelije) + std::floor(y / visinaCelije) * stupci);
}


unsigned int Objekt::brojObjekata = 0;
unsigned int Objekt::redovi = 0;
unsigned int Objekt::stupci = 0;
unsigned int Objekt::visinaCelije = 0;
unsigned int Objekt::sirinaCelije = 0;