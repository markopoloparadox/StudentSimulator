#include "StudentSP.h"

StabloPonasanja::Cvor * StudentSP::kreirajStablo(Agent * agent) {
	StudentSP::Selektor* sel1 = new Selektor();

	sel1->dodajDjete(new daLiImaCilj(agent));
	sel1->dodajDjete(new postaviCilj(agent));

	StudentSP::Sekvenca* sek1 = new Sekvenca();
	sek1->dodajDjete(sel1);
	sek1->dodajDjete(new dojdiDoCIlja(agent));


	return sek1;
}