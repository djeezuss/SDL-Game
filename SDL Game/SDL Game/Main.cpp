#include <SDL.h>
#include "Application.h"

int main(int argc, char *args[])
{
	SDL_Game::Application app("SDL Game", 640, 400);

	app.StartGame();

	return 0;
}
