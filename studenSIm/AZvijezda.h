#pragma once
#include "ACelija.h"
#include <memory>
#include <unordered_map>
class AZvijezda : public Objekt {
public:
	AZvijezda();
	~AZvijezda();

	void kreirajACeliju(Celija*);
	void pocisti();
	std::vector<unsigned int> kreirajRutu(unsigned int trenutnaPozicija, unsigned int zeljenaPozicij);


private:
	std::vector<std::unique_ptr<ACelija>> aCelije;
	//Pronalazak susjeda u 4 smjera
	std::vector<unsigned int> pronadjiSusjede4(unsigned int);
	//Pronalazak susjeda u 8 smjera
	std::vector<unsigned int> pronadjiSusjede8(unsigned int);
};

