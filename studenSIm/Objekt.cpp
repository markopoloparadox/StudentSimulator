#include "Objekt.h"
#include <iostream>



Objekt::Objekt() : id(brojObjektaKreiranih++) {}


Objekt::~Objekt() {
	std::cout << id << ": Mrtav sam!" << std::endl;
}

unsigned int Objekt::brojObjektaKreiranih = 0;
