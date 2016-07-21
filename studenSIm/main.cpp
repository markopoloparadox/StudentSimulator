#include <cassert>
#include "game.h"
#include "PodatkovniSloj.h"
#include "StabloPonasanja.h"
#include <ctime>


int main() {
	int init;

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