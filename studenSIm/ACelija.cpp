#include "ACelija.h"


ACelija::ACelija(Celija* _celija): celija(_celija){ }

unsigned int ACelija::izracunajH8(unsigned int z) { 
	int p = celija->dohvatiId();
	int xP = p % Objekt::stupci;
	int yP = p / Objekt::stupci;

	int xZ = z % Objekt::stupci;
	int yZ = z / Objekt::stupci;

	unsigned int trosak = 0;

	while (xP != xZ || yP != yZ) {
		if (xP < xZ && yP < yZ) {
			trosak += 14;
			++xP;
			++yP;
		} else if (xP > xZ && yP > yZ) {
			trosak += 14;
			--xP;
			--yP;
		} else if (xP < xZ && yP > yZ) {
			trosak += 14;
			++xP;
			--yP;
		} else if (xP > xZ && yP < yZ) {
			trosak += 14;
			--xP;
			++yP;
		} else if (xP > xZ) {
			trosak += 10;
			--xP;
		} else if (xP < xZ) {
			trosak += 10;
			++xP;
		} else if (yP > yZ) {
			trosak += 10;
			--yP;
		} else if (yP < yZ) {
			trosak += 10;
			++yP;
		}
	}

	return trosak;
}

unsigned int ACelija::izracunajH4(unsigned int z) {
	int p = celija->dohvatiId();
	int xP = p % Objekt::stupci;
	int yP = p / Objekt::stupci;

	int xZ = z % Objekt::stupci;
	int yZ = z / Objekt::stupci;

	unsigned int trosak = 0;

	while (xP != xZ || yP != yZ) {
		if (xP > xZ) {
			trosak += 10;
			--xP;
		} else if (xP < xZ) {
			trosak += 10;
			++xP;
		} else if (yP > yZ) {
			trosak += 10;
			--yP;
		} else if (yP < yZ) {
			trosak += 10;
			++yP;
		}
	}
	return trosak;
}

unsigned int ACelija::izracunajG() { 
	unsigned int trosak = 0;
	unsigned int trPoz = this->dohvatiId();
	unsigned int rodPoz = noviRoditelj->dohvatiId();

	if (rodPoz == trPoz - 1 || rodPoz == trPoz + 1 || rodPoz == trPoz - Objekt::stupci || rodPoz == trPoz + Objekt::stupci) {
		trosak += 10;
	} else {
		trosak += 14;
	}

	if (roditelj != nullptr) {
		trosak += noviRoditelj->dohvatiG();
	}

	return  trosak;

}

unsigned int ACelija::izracunajF(unsigned int z) { return izracunajG() + izracunajH8(z); }

unsigned int ACelija::dohvatiF() {
	return F;
}

unsigned int ACelija::dohvatiG() {
	return G;
}

unsigned int ACelija::dohvatiId() {
	return celija->dohvatiId();
}

void ACelija::postaviF(unsigned int _F) { F = _F; }


void ACelija::resetiraj() { roditelj = nullptr; }


void ACelija::izracunaj(ACelija * _roditelj, unsigned int z) {
	unsigned int rodPoz = _roditelj->dohvatiId();
	noviRoditelj = _roditelj;
	if (roditelj == nullptr) {
		roditelj = _roditelj;
		F = izracunajF(z);
		G = izracunajG();
		H = izracunajH8(z);
	} else {
		unsigned int noviF = izracunajF(z);
		if (noviF < F) {
			roditelj = _roditelj;
			F = noviF;
			G = izracunajG();
			H = izracunajH8(z);
		} else {
			return;
		}
	}
}

bool ACelija::prohodan() {
	return celija->dohvatiProhodnost();
}
