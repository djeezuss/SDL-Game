#pragma once
#include <SDL.h>
#include <string>
#include "Image.h"

namespace SDL_Game
{
	class Tileset
	{
	private:
		Image * tileset;
		int column;
		int row;
	public:
		// Column and Row are the number of Tiles that each one of them has
		Tileset(Application * app, std::string path, int tileWidth, int tileHeight, int column, int row);
		~Tileset();

		void Draw(SDL_Renderer * renderer, int tileId);
	};
}

