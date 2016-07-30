#include "Agent.h"
#include "PodatkovniSloj.h"
#include <memory>


Agent::Agent(AZvijezda* _aZvijeda): aZvijezda(_aZvijeda) {
	tijelo.setRadius(10);
	tijelo.setFillColor(sf::Color(r, g, b));
	x = 50;
	y = 50;
	tijelo.setPosition(x, y);
	/*
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	*/
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
}

void Agent::prikazi(sf::RenderWindow* win) {
	win->draw(tijelo);
	win->draw(text);
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

void Agent::postaviText(std::string sadrzaj) {
	text.setString(sadrzaj);
	text.setPosition(x - 30, y - 40);
}

nlohmann::json Agent::sveVrsteJSON = PodatkovniSloj::dohvatiVrijednostDat("vrste.json");
