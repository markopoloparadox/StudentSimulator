#pragma once
class Objekt {
public:
	Objekt();
	~Objekt();

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
	

protected:
	//Relativni id objekta
	unsigned int id = 0;
	//Stvarni id objekta
	unsigned int stvarniId = 0;

	//Koordinate objekta
	double x = -1;
	double y = -1;

private:
	static unsigned int brojObjekata;
};
