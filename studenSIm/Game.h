#pragma once
#include "Agent.h"
#include "Mapa.h"

class Game {
public:
	Game();
	~Game();
	//Potrebne metode koja svaka klasa treba implementirati
	void upravljajUlazom();
	void azuriraj();
	void prikazi();


	bool prozorOtvoren() noexcept;

private:
	std::unique_ptr<sf::RenderWindow> win;
	std::vector<std::unique_ptr<Agent>> agenti;
	sf::View kamera;

	Mapa mapa;
	AZvijezda aZvijezda;

	
};
