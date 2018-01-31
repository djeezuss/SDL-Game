#include "Image.h"



namespace SDL_Game
{
	Image::Image(Application * app, SDL_Texture * texture)
	{
		logger = app->GetLogger();
		this->texture = texture;
	}


	Image::Image(Application * app, std::string path)
	{
		SDL_Surface * surface = IMG_Load(path.c_str());

		if (surface == NULL)
		{
			logger->Error("Could not load image " + path + "! SDL_Image Error : " + IMG_GetError());
		}
		else
		{
			texture = SDL_CreateTextureFromSurface(app->GetRenderer(), surface);
			if (texture ==  NULL)
			{
				logger->Error("Unable to create texture from " + path + "! SDL Error: " + SDL_GetError());
			}
			SDL_FreeSurface(surface);
		}
	}

	Image::~Image()
	{
		if (crop != NULL)
			delete crop;
		SDL_DestroyTexture(texture);
	}

	void Image::Draw(SDL_Renderer * renderer)
	{
		SDL_RenderCopy(renderer, texture, crop, &source);
	}

	SDL_Rect Image::GetCrop()
	{
		return *crop;
	}

	void Image::SetCrop(SDL_Rect dim)
	{
		if (crop == NULL)
		{
			crop = new SDL_Rect();
		}

		*crop = dim;
	}
}
