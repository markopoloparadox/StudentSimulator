#include "game.h"
#include "PodatkovniSloj.h"
#include "Mapa.h"
#include <ctime>
#include <cassert>


int main() {

	PodatkovniSloj::upisiULog("----------POCETAK----------");
	srand(time(NULL));
	Game game;
	while (game.prozorOtvoren()) {
		game.upravljajUlazom();
		game.azuriraj();
		game.prikazi();
	}

	PodatkovniSloj::upisiULog("-----------KRAJ------------");
	return 0;

}