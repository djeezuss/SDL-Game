#pragma once
#include <string>
#include "Application.h"
#include "Tileset.h"
#include "Camera.h"

namespace SDL_Game
{
	class World
	{
	private:
		Tileset * tileset;
		Camera camera;
	public:
		World(Application * app, Tileset * tileset);
		~World();
	};
}

