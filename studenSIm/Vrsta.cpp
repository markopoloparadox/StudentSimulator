#include "Vrsta.h"
#include "PodatkovniSloj.h"
#include "jsonExtend.h"


Vrsta::Vrsta() {}

Vrsta::Vrsta(nlohmann::json j) { popuni(j); }

Vrsta::~Vrsta() {

}


void Vrsta::popuniFunkcije() {
	auto f1 = [this](std::string _ime) {ime = _ime; };
	funkcije.insert({ "ime", f1 });

	auto f2 = [this](std::string _opis) {opis = _opis; };
	funkcije.insert({ "opis", f2 });
}

void Vrsta::popuni(nlohmann::json j) {
	popuniFunkcije();

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
	std::cout << "Ovo je: " << int(this) << std::endl;
}
