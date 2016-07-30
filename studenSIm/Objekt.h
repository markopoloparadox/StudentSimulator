#pragma once
#include <SFML\Graphics.hpp>
class Objekt {
public:
	Objekt();
	~Objekt();

	//Svaki objekt moze implementirati svoje azriranje i prikaz
	virtual void azuriraj() {}
	virtual void prikazi(sf::RenderWindow*) {}

	//Broj æelija po stupcu su poznate objektu
	static unsigned int redovi;
	static unsigned int stupci;

	//Veliæina æelije su poznate objektu
	static unsigned int sirinaCelije;
	static unsigned int visinaCelije;

	//Svaki objekt ima svoj ID
	unsigned int dohvatiId() const { return stvarniId; }

	//Svaki objekt ima koordinate gdje se nalazi
	const double X() const { return x; }
	const double Y() const { return y; }
	void postaviXY(double, double);

	//Svaki objekt može prikazati svoju lokaciju kao poziciju unutar mreže æelija
	unsigned int dohvatiPozicijuUMrezi();

	virtual void postaviText(std::string sadrzaj) { text.setString(sadrzaj); }
	

protected:
	//Relativni id objekta
	unsigned int id = 0;
	//Stvarni id objekta
	unsigned int stvarniId = 0;

	//Koordinate objekta
	double x = -1;
	double y = -1;

	//Tekst za prikaz
	sf::Font font;
	sf::Text text;

private:
	static unsigned int brojObjekata;
};
