#include "Tileset.h"


namespace SDL_Game
{
	Tileset::Tileset(Application * app, std::string path, int tileWidth, int tileHeight, int column, int row)
	{
		tileset = new Image(app, path);
		tileset->SetCrop({ 0, 0, tileWidth, tileHeight });

		this->column = column;
		this->row = row;
	}


	Tileset::~Tileset()
	{
		delete tileset;
	}

	void Tileset::Draw(SDL_Renderer * renderer, int tileId)
	{
		SDL_Rect crop = tileset->GetCrop();

		crop.x = tileId % column * crop.w;
		crop.y = tileId / column * crop.h;

		tileset->SetCrop(crop);

		tileset->Draw(renderer);
	}
}
