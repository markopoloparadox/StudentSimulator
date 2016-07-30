#pragma once
#include <SFML\Graphics.hpp>
class Objekt {
public:
	Objekt();
	~Objekt();

	//Svaki objekt moze implementirati svoje azriranje i prikaz
	virtual void azuriraj() {}
	virtual void prikazi(sf::RenderWindow*) {}

	//Broj �elija po stupcu su poznate objektu
	static unsigned int redovi;
	static unsigned int stupci;

	//Veli�ina �elije su poznate objektu
	static unsigned int sirinaCelije;
	static unsigned int visinaCelije;

	//Svaki objekt ima svoj ID
	unsigned int dohvatiId() const { return stvarniId; }

	//Svaki objekt ima koordinate gdje se nalazi
	const double X() const { return x; }
	const double Y() const { return y; }
	void postaviXY(double, double);

	//Svaki objekt mo�e prikazati svoju lokaciju kao poziciju unutar mre�e �elija
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
