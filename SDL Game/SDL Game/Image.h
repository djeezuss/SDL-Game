#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Application.h"
#include "Logger.h"

namespace SDL_Game
{
	class Image
	{
	protected:
		// The Rect that will be drawn to the screen
		SDL_Rect source;
		// The Rect that will crop the texture
		SDL_Rect * crop;
		SDL_Texture * texture;

		Logger * logger;
	public:
		// Use an already existing texture
		Image(Application * app, SDL_Texture * texture);
	
		// Create a new texture to the Image
		Image(Application * app, std::string pathToFile);
	
		~Image();

		void Draw(SDL_Renderer * renderer);

		SDL_Rect GetCrop();
		void SetCrop(SDL_Rect dim);
	};
}
