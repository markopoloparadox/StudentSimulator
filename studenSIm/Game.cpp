#include "Game.h"
#include "PodatkovniSloj.h"
#include "AZvijezda.h"


Game::Game() {
	aZvijezda.inicijaliziraj(redki, stupci);

	nlohmann::json j = PodatkovniSloj::dohvatiVrijednostDat("postavke.json");
	unsigned int sirina = j["sirinaProzora"].get<unsigned int>();
	unsigned int visina = j["visinaProzora"].get<unsigned int>();
	win = std::make_unique<sf::RenderWindow>(sf::VideoMode(sirina, visina), "Student Simulator");

	for (int i = 0; i < 10; ++i) {
		agenti.push_back(std::make_unique<Agent>(2, &aZvijezda));
		agenti.back()->postaviStabloP(StudentSP::kreirajStablo(agenti.back().get()));
	}

	win->setFramerateLimit(60);


	for (auto i = 0; i < redki; ++i) {
		for (auto j = 0; j < stupci; ++j) {
			mapa.push_back(std::make_unique<Celija>(j * 64, i * 64));
			aZvijezda.kreirajACeliju(mapa.back().get());
		}
	}

	win->setView(kamera);



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
			unsigned int w = 64;
			unsigned int h = 64;
			if (coord_pos.x < 0 || coord_pos.y < 0) {
			} else {
				unsigned int celijaId = std::floor(coord_pos.x / w) + std::floor(coord_pos.y / h) * 12;
				bool tretProh = mapa[celijaId]->dohvatiProhodnost();
				if (tretProh) {
					tretProh = false;
				} else {
					tretProh = true;
				}
				mapa[celijaId]->postaviProhodnost(tretProh);
			}
		}
	}
}

void Game::azuriraj() {
	for (auto& agent : agenti) {
		agent->azuriraj();
	}
		

	for (auto& celija : mapa)
		celija->azuriraj();

}

void Game::prikazi() {
	win->clear();
	for (auto& celija : mapa)
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
