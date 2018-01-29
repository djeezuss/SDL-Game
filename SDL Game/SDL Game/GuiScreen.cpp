#include "GuiScreen.h"

SDL_Game::GuiScreen::GuiScreen()
{
	GuiChanged = true;
}

SDL_Game::GuiScreen::GuiScreen(std::string name)
{
	Name = name;
	GuiChanged = true;
}

SDL_Game::GuiScreen::~GuiScreen()
{
}

void SDL_Game::GuiScreen::PrepareRenderer()
{
	std::set<GuiObject*> children = this->GetChildren();
	std::set<GuiObject*>::iterator it = children.begin();

	while (it != children.end()) {
		(*it)->PrepareRenderer(&ElementToRender);
		it++;
	}

	GuiChanged = false;
}

void SDL_Game::GuiScreen::ForceUpdate()
{
	PrepareRenderer();
}

void SDL_Game::GuiScreen::Draw(void* sdl_renderer)
{
	if (GuiChanged)
		PrepareRenderer();

	std::set<GuiObject*>::iterator it = ElementToRender.begin();


	while (it != ElementToRender.end()) {
		(*it)->Draw(sdl_renderer);
		it++;
	}
}

void SDL_Game::GuiScreen::Updated()
{
	GuiChanged = true;
}

void SDL_Game::GuiScreen::PrepareRenderer(std::set<GuiObject*>* list)
{

}