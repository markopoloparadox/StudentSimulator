#pragma once
#include "StabloPonasanja.h"
#include "Agent.h"
class GeneralNpcSP : public StabloPonasanja {
public:
	static StabloPonasanja::Cvor* kreirajStablo(Agent*);

	GeneralNpcSP() {};
	~GeneralNpcSP() {};

	class daLiJeDosadno : public GeneralNpcSP::Cvor {
	public:
		daLiJeDosadno(Agent* _agent) : agent(_agent) {}
		
		Status azuriraj() {
			++agent->dosada;
			if (agent->dosada > 100)
				return Status::Uspjeh;
			return Status::Neuspjeh;
		}

	private:
		Agent* agent;
	};

	class ispisiTekst : public GeneralNpcSP::Cvor {
	public:
		ispisiTekst(Agent* _agent) : agent(_agent) {}

		void inicijaliziraj() override {
			agent->postaviText("Pozdrav");
			vrijemeCekanja = 0;
		}

		Status azuriraj() {
			++vrijemeCekanja;
			if (vrijemeCekanja > 100) {
				agent->postaviText("");
				agent->dosada = 0;
				return Status::Uspjeh;
				
			}
			return Status::NijeGotov;
		}

	private:
		unsigned int vrijemeCekanja;
		Agent* agent;
	};

};