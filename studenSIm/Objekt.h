#pragma once
class Objekt {
public:
	Objekt();
	~Objekt();

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
