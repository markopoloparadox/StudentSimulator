#include "PodatkovniSloj.h"
#include <fstream>
#include "date.h"
#include <iomanip>


PodatkovniSloj::PodatkovniSloj() {}


PodatkovniSloj::~PodatkovniSloj() {}

nlohmann::json PodatkovniSloj::dohvatiVrijednostDat(std::string putanja) {
	std::ifstream dat;

	dat.open(putanja);
	if (!dat.is_open()) {
		std::string poruka = "Datoteka " + putanja + " ne postoji!";
		upisiULog(poruka);
		exit(1);
	}

	std::string linija = "";
	std::string tekst = "";
	while (std::getline(dat, linija)) {
		tekst += linija;
		tekst.push_back('\n');
	}
	
	using namespace nlohmann;
	json j;
	
	try {
		j = json::parse(tekst);
	} catch (const std::exception e) {
		std::string poruka = "Datoteka " + putanja + " se ne moze (json) parsirati!";
		upisiULog(poruka);
		exit(1);
	}
	

	return j;
}

void PodatkovniSloj::upisiULog(std::string poruka) noexcept {
	std::ofstream dat;
	dat.open("log.txt", std::ofstream::app);

	using namespace date;
	using namespace std::chrono;

	auto tp = system_clock::now();
	dat << '\n' << '\n' << tp << '\n' << poruka;
}


