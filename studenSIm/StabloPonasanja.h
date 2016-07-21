#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <string>
class StabloPonasanja {
public:
	StabloPonasanja();
	~StabloPonasanja();

	class Cvor {
	public:
		enum class Status {
			Uspjeh,
			Neuspjeh,
			NijeGotov,
			Nevazec
		};
		virtual Status azuriraj() = 0;
		virtual void inicijaliziraj() {};
		virtual void terminiraj(Status s) {};

		Status Tick() {
			if (status != Status::NijeGotov) {
				inicijaliziraj();
			}

			status = azuriraj();

			if (status != Status::NijeGotov) {
				terminiraj(status);
			}

			return status;
		}
	private:
		Status status = Status::Nevazec;
	};

	class KompozitniCvor : public Cvor {
	public:
		void dodajDjete(Cvor* djete) { djeca.emplace_back(djete); }
		const std::vector<Cvor*>& dohvatiDjecu() const { return djeca;  }
	private:
		std::vector<Cvor*> djeca;
	};

	class Sekvenca : public KompozitniCvor {
	public:
		Status azuriraj() override {
			for (auto djete : dohvatiDjecu()) {
				auto status = djete->Tick();

				if (status != Status::Uspjeh)
					return status;
			}
			return Status::Uspjeh;
		}
	};

	class Selektor : public KompozitniCvor {
	public:
		Status azuriraj() override {
			for (auto djete : dohvatiDjecu()) {
				auto status = djete->Tick();

				if (status != Status::Neuspjeh)
					return status;
			}
			return Status::Neuspjeh;
		}
	};

	class Glava : public Cvor {
	private:
		Cvor* djete;
		Status azuriraj() override { return djete->Tick(); }
		void postaviDjete(Cvor* _djete) { djete = _djete; }
		friend class StabloPonasanja;
	};

	

	void postaviGlavu(Cvor* djete) { glava.postaviDjete(djete);  } 
	void kreni() { glava.Tick(); }
private:
	Glava glava;
};