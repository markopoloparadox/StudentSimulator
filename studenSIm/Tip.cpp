#include "Tip.h"
#include "PodatkovniSloj.h"

Tip::Tip() {}

Tip::~Tip() {}

void Tip::popuniFunkcije() {
	auto f1 = [this](std::string _prohodan) {prohodan = pretvoriUBool(_prohodan); };
	funkcije.insert({ "prohodan", f1 });

	auto f2 = [this](std::string _unikatan) {unikatan = pretvoriUBool(_unikatan); };
	funkcije.insert({ "unikatan", f2 });

}


void Tip::popuni(nlohmann::json _j, unsigned int Id) {
	popuniFunkcije();
	std::string sId = std::to_string(Id - 1);
	auto j = _j["tilesets"][0]["tileproperties"][sId];
	for (auto atribut = j.begin(); atribut != j.end(); ++atribut) {
		auto pro = funkcije.find(atribut.key());
		std::string vri = pretvoriUString(atribut.value());
		if (pro != funkcije.end()) {
			pro->second(vri);
		} else {
			std::string greska = "Atribut " + atribut.key() + " ne postoji kod vrsta";
			PodatkovniSloj::upisiULog(greska);
		}
	}
}
