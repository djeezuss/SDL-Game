#include "GuiImageLabel.h"



SDL_Game::GuiImageLabel::GuiImageLabel(SDL_Texture* texture)
{
	this->Image = texture;
	this->Visible = true;
	pos = { 0,0,100,100 };
}


SDL_Game::GuiImageLabel::~GuiImageLabel()
{
}


void SDL_Game::GuiImageLabel::Draw(void* sdl_renderer)
{
	SDL_Renderer* renderer = (SDL_Renderer*)sdl_renderer;
	SDL_RenderCopy(renderer, Image, NULL, &pos);
	if (this->Name == "Image Label")
	{
		pos.h = 200;
		pos.w = 200;
	}

	pos.x++;
	if (pos.x > 300)
		pos.x = -100;
}

void SDL_Game::GuiImageLabel::PrepareRenderer(std::set<GuiObject*>* list)
{
	if (this->Visible)
	{
		std::set<GuiObject*>::iterator it = list->begin();

		while (it != list->end() && true) it++;
		list->insert(it, this);

		std::set<GuiObject*> children = this->GetChildren();
		it = children.begin();

		while (it != children.end()) {
			(*it)->PrepareRenderer(list);
			it++;
		}
	}
}