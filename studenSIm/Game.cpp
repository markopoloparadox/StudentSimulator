#include "Game.h"
#include "PodatkovniSloj.h"
#include "AZvijezda.h"
#include "StudentSP.h"
#include "GeneralNpcSP.h"


Game::Game() {
	//U�itavanje postavki
	nlohmann::json j = PodatkovniSloj::dohvatiVrijednostDat("postavke.json");
	unsigned int sirina = j["sirinaProzora"].get<unsigned int>();
	unsigned int visina = j["visinaProzora"].get<unsigned int>();
	

	mapa.inicijaliziraj();

	//Kreiranje prozora
	win = std::make_unique<sf::RenderWindow>(sf::VideoMode(sirina, visina), "Student Simulator");
	win->setFramerateLimit(j["brzinaSlike"].get<unsigned int>());
	kamera.setCenter(sf::Vector2f(1000, 1000));
	win->setView(kamera);

	//Kreiranje agenta
	for (int i = 0; i < 10; ++i) {
		agenti.push_back(std::make_unique<Agent>(&mapa.aZvijezda));
		agenti.back()->postaviStabloP(StudentSP::kreirajStablo(agenti.back().get()));
	}

}

Game::~Game() {}


void Game::upravljajUlazom() {
	sf::Event event;
	while (win->pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed)
			win->close();
		if (event.type == sf::Event::MouseWheelScrolled) {
			if (event.mouseWheelScroll.delta > 0) {
				kamera.zoom(1.1f);
				win->setView(kamera);
			} else {
				kamera.zoom(0.9f);
				win->setView(kamera);
			}
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			sf::Vector2i pixel_pos = sf::Mouse::getPosition(*win);
			sf::Vector2f coord_pos = win->mapPixelToCoords(pixel_pos);
			if (coord_pos.x < 0 || coord_pos.y < 0) {
			} else {
				unsigned int celijaId = std::floor(coord_pos.x / Objekt::sirinaCelije) + std::floor(coord_pos.y / Objekt::visinaCelije) * Objekt::stupci;
				bool tretProh = mapa.celije[celijaId]->dohvatiProhodnost();
				if (tretProh) {
					tretProh = false;
				} else {
					tretProh = true;
				}
				mapa.celije[celijaId]->postaviProhodnost(tretProh);
			}
		}
	}
}

void Game::azuriraj() {

	for (auto& agent : agenti) {
		agent->azuriraj();
	}
		

	for (auto& celija : mapa.celije)
		celija->azuriraj();

}

void Game::prikazi() {
	win->clear();
	for (auto& celija : mapa.celije)
		celija->prikazi(win.get());

	for (auto& agent : agenti)
		agent->prikazi(win.get());

	win->display();
}

bool Game::prozorOtvoren() noexcept {
	if (win->isOpen())
		return true;
	return false;
}
