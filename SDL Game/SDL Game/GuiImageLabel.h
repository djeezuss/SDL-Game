#pragma once
#include "GuiObject.h"
#include "SDL.h"

namespace SDL_Game {
	class GuiImageLabel : public GuiObject
	{
	private:
		SDL_Texture * Image;
		SDL_Rect pos;

	public:
		GuiImageLabel(SDL_Texture* texture);
		~GuiImageLabel();

		void Draw(void* sdl_renderer) override;
		void PrepareRenderer(std::set<GuiObject*>* list) override;
	};
}