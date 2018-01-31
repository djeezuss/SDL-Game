#include "World.h"


namespace SDL_Game
{
	World::World(Application * app, Tileset * tileset)
	{
		this->tileset = tileset;
	}


	World::~World()
	{ }
}
