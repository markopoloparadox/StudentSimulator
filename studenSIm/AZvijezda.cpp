#include "AZvijezda.h"
#include <iostream>

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
	auto tP = trenutnaPozicija;
	if (zeljenaPozicija < 0 || zeljenaPozicija >= redovi * stupci) {
		return std::vector<unsigned int>(tP);
	}

	std::vector<ACelija*> otvorenaLista;
	std::vector<ACelija*> zatvorenaLista;
	std::vector<unsigned int> ruta;

	auto daLiJeUListiZ = [&zatvorenaLista](unsigned int id) -> bool {
		for (auto& elem : zatvorenaLista)
			if (elem->dohvatiId() == id)
				return true;
		return false;
	};

	auto daLiJeUListiO = [&otvorenaLista](unsigned int id) -> bool {
		for (auto& elem : otvorenaLista)
			if (elem->dohvatiId() == id)
				return true;
		return false;
	};

	otvorenaLista.push_back(AZvijezda::aCelije[trenutnaPozicija].get());

	while (1) {
		if (otvorenaLista.size() == 0) {
			//std::cout << tP << " " << "Nejde";
			std::vector<unsigned int> greska;
			greska.push_back(tP);
			return greska;
		}

		std::sort(otvorenaLista.begin(), otvorenaLista.end(), [](ACelija* a, ACelija* b) ->bool {
			return a->dohvatiF() < b->dohvatiF();
		});

		zatvorenaLista.push_back(otvorenaLista[0]);
		otvorenaLista.erase(otvorenaLista.begin());

		trenutnaPozicija = zatvorenaLista.back()->dohvatiId();

		if (trenutnaPozicija == zeljenaPozicija) {
			break;
		}

		auto susjedi = pronadjiSusjede8(trenutnaPozicija);
		for (auto& susjed : susjedi) {
			if (aCelije[susjed]->prohodan()) {
				if (!daLiJeUListiZ(susjed)) {
					aCelije[susjed]->izracunaj(aCelije[trenutnaPozicija].get(), zeljenaPozicija);
					if (!daLiJeUListiO(susjed))
						otvorenaLista.push_back(aCelije[susjed].get());
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
	std::vector<unsigned int> susjedi;

	int d1 = p - stupci - 1;
	int d2 = p - stupci + 1;
	int d3 = p + stupci - 1;
	int d4 = p + stupci + 1;
	
	int u = p - stupci;
	int l = p - 1;
	int r = p + 1;
	int d = p + stupci;

	if (p == 0) {
		susjedi.push_back(r);
		susjedi.push_back(d4);
		susjedi.push_back(d);
	} else if (p == stupci - 1) {
		susjedi.push_back(d);
		susjedi.push_back(d3);
		susjedi.push_back(l);
	} else if (p == (redovi - 1) * stupci) {
		susjedi.push_back(u);
		susjedi.push_back(d2);
		susjedi.push_back(r);
	} else if (p == (redovi  * stupci) - 1) {
		susjedi.push_back(l);
		susjedi.push_back(d1);
		susjedi.push_back(u);
	} else if (p % stupci == 0) {
		susjedi.push_back(u);
		susjedi.push_back(d2);
		susjedi.push_back(r);
		susjedi.push_back(d4);
		susjedi.push_back(d);
	} else if (p % stupci == stupci - 1) {
		susjedi.push_back(d);
		susjedi.push_back(d3);
		susjedi.push_back(l);
		susjedi.push_back(d1);
		susjedi.push_back(u);
	} else if (p < stupci) {
		susjedi.push_back(r);
		susjedi.push_back(d4);
		susjedi.push_back(d);
		susjedi.push_back(d3);
		susjedi.push_back(l);
	} else if (p > (redovi - 1) * stupci) {
		susjedi.push_back(l);
		susjedi.push_back(d1);
		susjedi.push_back(u);
		susjedi.push_back(d2);
		susjedi.push_back(r);
	} else {
		susjedi.push_back(d1);
		susjedi.push_back(u);
		susjedi.push_back(d2);
		susjedi.push_back(r);
		susjedi.push_back(d4);
		susjedi.push_back(d);
		susjedi.push_back(d3);
		susjedi.push_back(l);
	}

	return susjedi;
}