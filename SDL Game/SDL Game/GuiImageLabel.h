#pragma once
#include "GuiObject.h"
#include "SDL.h"

class GuiImageLabel : public GuiObject
{
private:
	SDL_Texture* Image;

public:
	GuiImageLabel();
	~GuiImageLabel();

	void Draw(SDL_Renderer* renderer);
};

