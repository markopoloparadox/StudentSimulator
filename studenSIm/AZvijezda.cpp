#include "AZvijezda.h"
#include <iostream>
#include <set>

AZvijezda::AZvijezda() {}


AZvijezda::~AZvijezda() {}


void AZvijezda::kreirajACeliju(Celija* celija) {
	aCelije.push_back(std::make_unique<ACelija>(celija));
}

void AZvijezda::pocisti() {
	for (auto& aCelija : AZvijezda::aCelije)
		aCelija->resetiraj();
}

std::vector<unsigned int> AZvijezda::kreirajRutu(unsigned int trenutnaPozicija, unsigned int zeljenaPozicija) {
	if (zeljenaPozicija < 0 || zeljenaPozicija >= redovi * stupci) {
		std::vector<unsigned int> greska{ trenutnaPozicija };
		return greska;
	}
	if (!aCelije[zeljenaPozicija]->prohodan()) {
		std::vector<unsigned int> greska{ trenutnaPozicija };
		return greska;
	}


	std::set<unsigned int> otvorenaListaId;
	std::set<unsigned int> zatvorenaListaId;
	std::vector<ACelija*> otvorenaLista;
	std::vector<ACelija*> zatvorenaLista;
	std::vector<unsigned int> ruta;

	otvorenaLista.reserve(50);
	zatvorenaLista.reserve(200);
	ruta.reserve(50);
	
	auto daLiJeUListiZ = [&zatvorenaListaId](unsigned int id) -> bool {
		auto pronadjen = zatvorenaListaId.find(id);
		if (pronadjen != zatvorenaListaId.end())
			return true;

		return false;
	};
	

	auto daLiJeUListiO = [&otvorenaListaId](unsigned int id) -> bool {
		auto pronadjen = otvorenaListaId.find(id);
		if (pronadjen != otvorenaListaId.end())
			return true;

		return false;
	};


	otvorenaLista.push_back(AZvijezda::aCelije[trenutnaPozicija].get());
	otvorenaListaId.insert(trenutnaPozicija);
	
	auto tP = trenutnaPozicija;
	while (1) {
		if (otvorenaLista.size() == 0) {
			std::vector<unsigned int> greska{ tP };
			return greska;
		}

		std::sort(otvorenaLista.begin(), otvorenaLista.end(), [](ACelija* a, ACelija* b) ->bool {
			return a->dohvatiF() < b->dohvatiF();
		});

		zatvorenaLista.push_back(otvorenaLista[0]);
		zatvorenaListaId.insert(otvorenaLista[0]->dohvatiId());

		otvorenaListaId.erase(otvorenaLista[0]->dohvatiId());
		otvorenaLista.erase(otvorenaLista.begin());
		

		tP = zatvorenaLista.back()->dohvatiId();

		if (tP == zeljenaPozicija) {
			break;
		}

		auto susjedi = pronadjiSusjede8(tP);
		for (auto& susjed : susjedi) {
			if (aCelije[susjed]->prohodan()) {
				if (!daLiJeUListiZ(susjed)) {
					aCelije[susjed]->izracunaj(aCelije[tP].get(), zeljenaPozicija);
					if (!daLiJeUListiO(susjed)) {
						otvorenaLista.push_back(aCelije[susjed].get());
						otvorenaListaId.insert(aCelije[susjed].get()->dohvatiId());
					}
						
				}
			}
		}
	}

	ACelija* trenCelija = zatvorenaLista.back();
	while (trenCelija != nullptr) {
		ruta.push_back(trenCelija->dohvatiId());
		trenCelija = trenCelija->roditelj;
	}

	std::reverse(ruta.begin(), ruta.end());

	return ruta;
}

std::vector<unsigned int> AZvijezda::pronadjiSusjede4(unsigned int p) {
	/*
	X  X u  X X
	X  l  p  r  X
	X  X d  X X
	X  X  X  X  X
	*/

	//Nije optimizirano! Pogledaj primjer pronadjiSusjede8()!
	std::vector<unsigned int> susjedi;


	int u = p - stupci;
	int l = p - 1;
	int r = p + 1;
	int d = p + stupci;

	if (p == 0) {
		susjedi.push_back(r);
		susjedi.push_back(d);
	} else if (p == stupci - 1) {
		susjedi.push_back(d);
		susjedi.push_back(l);
	} else if (p == (redovi - 1) * stupci) {
		susjedi.push_back(u);
		susjedi.push_back(r);
	} else if (p == (redovi  * stupci) - 1) {
		susjedi.push_back(l);
		susjedi.push_back(u);
	} else if (p % stupci == 0) {
		susjedi.push_back(u);
		susjedi.push_back(r);
		susjedi.push_back(d);
	} else if (p % stupci == stupci - 1) {
		susjedi.push_back(d);
		susjedi.push_back(l);
		susjedi.push_back(u);
	} else if (p < stupci) {
		susjedi.push_back(r);
		susjedi.push_back(d);
		susjedi.push_back(l);
	} else if (p >(redovi - 1) * stupci) {
		susjedi.push_back(l);
		susjedi.push_back(u);
		susjedi.push_back(r);
	} else {
		susjedi.push_back(u);
		susjedi.push_back(r);
		susjedi.push_back(d);
		susjedi.push_back(l);
	}

	return susjedi;
}

std::vector<unsigned int> AZvijezda::pronadjiSusjede8(unsigned int p) {
	/*
	X  d1 u  d2 X
	X  l  p  r  X
	X  d3 d  d4 X
	X  X  X  X  X
	*/

	//susjedi.reserve(10);

	int d1 = p - stupci - 1;
	int d2 = p - stupci + 1;
	int d3 = p + stupci - 1;
	int d4 = p + stupci + 1;

	int u = p - stupci;
	int l = p - 1;
	int r = p + 1;
	int d = p + stupci;

	if (p == 0) {
		std::vector<unsigned int> susjedi(3);

		susjedi[0] = r;
		susjedi[1] = d4;
		susjedi[2] = d;

		return susjedi;
	} else if (p == stupci - 1) {
		std::vector<unsigned int> susjedi(3);

		susjedi[0] = d;
		susjedi[1] = d3;
		susjedi[2] = l;

		return susjedi;
	} else if (p == (redovi - 1) * stupci) {
		std::vector<unsigned int> susjedi(3);

		susjedi[0] = u;
		susjedi[1] = d2;
		susjedi[2] = r;

		return susjedi;
	} else if (p == (redovi  * stupci) - 1) {
		std::vector<unsigned int> susjedi(3);

		susjedi[0] = l;
		susjedi[1] = d1;
		susjedi[2] = u;

		return susjedi;
	} else if (p % stupci == 0) {
		std::vector<unsigned int> susjedi(5);

		susjedi[0] = u;
		susjedi[1] = d2;
		susjedi[2] = r;
		susjedi[3] = d4;
		susjedi[4] = d;

		return susjedi;
	} else if (p % stupci == stupci - 1) {
		std::vector<unsigned int> susjedi(5);

		susjedi[0] = d;
		susjedi[1] = d3;
		susjedi[2] = l;
		susjedi[3] = d1;
		susjedi[4] = u;

		return susjedi;
	} else if (p < stupci) {
		std::vector<unsigned int> susjedi(5);

		susjedi[0] = r;
		susjedi[1] = d4;
		susjedi[2] = d;
		susjedi[3] = d3;
		susjedi[4] = l;

		return susjedi;
	} else if (p > (redovi - 1) * stupci) {
		std::vector<unsigned int> susjedi(5);

		susjedi[0] = l;
		susjedi[1] = d1;
		susjedi[2] = u;
		susjedi[3] = d2;
		susjedi[4] = r;

		return susjedi;
	}

	std::vector<unsigned int> susjedi(8);
	susjedi[0] = d1;
	susjedi[1] = u;
	susjedi[2] = d2;
	susjedi[3] = r;
	susjedi[4] = d4;
	susjedi[5] = d;
	susjedi[6] = d3;
	susjedi[7] = l;

	return susjedi;
}