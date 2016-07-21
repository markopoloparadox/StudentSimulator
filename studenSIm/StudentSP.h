#pragma once
#include "StabloPonasanja.h"
#include "Agent.h"
class StudentSP : public StabloPonasanja{
public:
	StudentSP() {};
	~StudentSP() {};

	static StabloPonasanja::Cvor* kreirajStablo(Agent*);

	class daLiImaCilj : public StudentSP::Cvor {
	public:
		daLiImaCilj(Agent* _agent): agent(_agent) { }
		Status azuriraj() override {
			if (agent->celijaCilj == -1) {
				//std::cout << agent->dohvatiId() << ": Nema cilja u zivotu...\n";
				return Status::Neuspjeh;
			}
			return Status::Uspjeh;
		}
	private:
		Agent* agent;
	};

	class postaviCilj : public StudentSP::Cvor {
	public:
		postaviCilj(Agent* _agent) : agent(_agent) {}
		Status azuriraj() override {
			agent->postaviCilj(rand() % 150);
			//std::cout << agent->dohvatiId() << ": Sad ima cilja u zivotu :D\n";
			return Status::Uspjeh;
		}
	private:
		Agent* agent;
	};

	class dojdiDoCIlja : public StudentSP::Cvor {
	public:
		dojdiDoCIlja(Agent* _agent) : agent(_agent) {}

		void inicijaliziraj() override {
			p = 0;
			ruta.clear();
			agent->aZvijezda->pocisti();
			ruta = agent->aZvijezda->kreirajRutu(agent->dohvatiPozicijuUMrezi(), agent->celijaCilj);
		}

		Status azuriraj() override {
			if (p == ruta.size()) {
				agent->celijaCilj = -1;
				return Status::Uspjeh;
			}

			if (agent->odiDo(ruta[p])) {
				++p;
			}

			return Status::NijeGotov;
		}
	private:
		Agent* agent;
		std::vector<unsigned int> ruta;
		unsigned int p;
	};

private:

};

