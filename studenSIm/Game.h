#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include "Agent.h"
#include "StudentSP.h"

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
	std::vector<std::unique_ptr<Celija>> mapa;
	AZvijezda aZvijezda;
	sf::View kamera;
};
