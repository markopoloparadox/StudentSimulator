#pragma once
#include "jsonExtend.h"
#include <SFML\Graphics.hpp>
#include <unordered_map>
class Tip {
public:
	Tip();
	~Tip();

	void popuni(nlohmann::json, unsigned int);

	bool prohodan = true;
	bool unikatan = true;
	unsigned int visina = 0;
	unsigned int sirina = 0;
	std::string ime = "Placeholder";
private:
	void popuniFunkcije();
	std::unordered_map<std::string, std::function<void(std::string)>> funkcije;
};

