#pragma once
#include <tuple>
class Objekt {
public:
	Objekt();
	~Objekt();

	void postaviKoord(double _x, double _y) {
		x = _x;
		y = _y;
	}

	const double XCilj() const { return xCilj; }
	const double YCilj() const { return yCilj; }
	const double X() const { return x; }
	const double Y() const { return y; }

	const unsigned int dohvatiId() const { return id; }

protected:
	double x = -1;
	double y = -1;
	double xCilj = -1;
	double yCilj = -1;

	double volumen = -1;
	double masa = -1;

	unsigned int id = 0;

private:
	static unsigned int brojObjektaKreiranih;
};
