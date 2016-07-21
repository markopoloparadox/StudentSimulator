#pragma once
#include "json.h"
#include <vector>
#include <unordered_map>


class Vrsta {
public:
	Vrsta(nlohmann::json j);
	Vrsta();
	~Vrsta();

	void popuni(nlohmann::json j);
	

private:
	void popuniFunkcije();

	std::unordered_map<std::string, std::function<void(std::string)>> funkcije;
	Vrsta* roditelj;
	std::string opis;
	std::string ime;
};

