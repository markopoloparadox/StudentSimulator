#include "GeneralNpcSP.h"


StabloPonasanja::Cvor * GeneralNpcSP::kreirajStablo(Agent * agent) {
	GeneralNpcSP::Sekvenca* sek1 = new Sekvenca();
	sek1->dodajDjete(new daLiJeDosadno(agent));
	sek1->dodajDjete(new ispisiTekst(agent));



	return sek1;
}