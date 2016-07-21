#include "Agent.h"
#include "PodatkovniSloj.h"
#include <memory>


Agent::Agent(AZvijezda* _aZvijeda): aZvijezda(_aZvijeda) {
	//std::cout << sveVrsteJSON.dump(4) << "\n";
	//std::cout << sveVrsteJSON["Igrac"].dump(4) << "\n";
	tijelo.setRadius(10);
	tijelo.setFillColor(sf::Color(r, g, b));
	x = 0;
	y = 0;
	tijelo.setPosition(x, y);
}

/*
Agent::Agent(std::string _vrsta, std::string _karakter) {
	if (_vrsta != "") {
		if (sveVrsteJSON[_vrsta] != "") {
			vrsta.popuni(sveVrsteJSON[_vrsta]);
			std::cout << "Uspjelo je!";
		}
	}
}
*/

Agent::~Agent() {}


void Agent::azuriraj() {
	sp.kreni();
	tijelo.setPosition(x, y);
	/*
	auto novaPratnja = std::make_unique<sf::CircleShape>(3, 3);
	novaPratnja->setPosition(x+10, y+10);
	novaPratnja->setFillColor(sf::Color(r, g, b));
	pratnja.push_back(std::move(novaPratnja));

	if (pratnja.size() > 50)
		pratnja.erase(pratnja.begin());
		*/
}

void Agent::prikazi(sf::RenderWindow* win) {
	win->draw(tijelo);
	for (auto& prat : pratnja)
		win->draw(*prat);
}

bool Agent::odiDo(unsigned int celijaId) {
	int p = celijaId;
	double xP = p % stupci;
	double yP = p / stupci;

	xP = xP * sirinaCelije + sirinaCelije / 2;
	yP = yP * visinaCelije + visinaCelije / 2;


	if (x == xP && y == yP) {
		return true;
	}

	double xUdaljOdCilj = x - xP;
	if (xUdaljOdCilj > (-tretBrzina) && xUdaljOdCilj < tretBrzina) {
		x = xP;
	} else if (xUdaljOdCilj > 0) {
		x = x - tretBrzina;
	} else if (xUdaljOdCilj < 0) {
		x = x + tretBrzina;
	}

	double yUdaljOdCilj = y - yP;
	if (yUdaljOdCilj >(-tretBrzina) && yUdaljOdCilj < tretBrzina) {
		y = yP;
	} else if (yUdaljOdCilj > 0) {
		y = y - tretBrzina;
	} else if (yUdaljOdCilj < 0) {
		y = y + tretBrzina;
	}

	postaviXY(x, y);

	return false;
}

nlohmann::json Agent::sveVrsteJSON = PodatkovniSloj::dohvatiVrijednostDat("vrste.json");
