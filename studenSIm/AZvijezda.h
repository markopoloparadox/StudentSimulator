#pragma once
#include "ACelija.h"
#include <vector>
#include <memory>
#include <unordered_map>
class AZvijezda {
public:
	AZvijezda();
	AZvijezda(unsigned int, unsigned int);
	~AZvijezda();

	void kreirajACeliju(Celija*);
	void pocisti();
	void inicijaliziraj(unsigned int, unsigned int);
	std::vector<unsigned int> kreirajRutu(unsigned int trenutnaPozicija, unsigned int zeljenaPozicij);

private:

	std::vector<std::unique_ptr<ACelija>> aCelije;
	std::vector<unsigned int> pronadjiSusjede(unsigned int);
	unsigned int redci;
	unsigned int stupci;
};

