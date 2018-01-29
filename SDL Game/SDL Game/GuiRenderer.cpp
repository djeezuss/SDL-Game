#include "GuiRenderer.h"
#include "GuiFrame.h"
#include "GuiImageLabel.h"
#include "GuiScreen.h"
#include <SDL_image.h>


SDL_Game::GuiRenderer::GuiRenderer()
{
	
}


SDL_Game::GuiRenderer::~GuiRenderer()
{
	std::set<GuiObject*>::iterator it = GuiScreens.begin();
	GuiObject* GuiToDelete = nullptr;

	while(it != GuiScreens.end())
	{
		GuiToDelete = *it;
		delete GuiToDelete;
		it++;
	}
}

void SDL_Game::GuiRenderer::RenderGui(void* sdl_renderer)
{
	std::set<GuiObject*>::iterator it = GuiScreens.begin();

	while (it != GuiScreens.end())
	{
		(*it)->Draw(sdl_renderer);
		it++;
	}
}

SDL_Game::GuiObject* SDL_Game::GuiRenderer::AddScreenGui(std::string name)
{
	std::set<GuiObject*>::iterator it = GuiScreens.begin();

	while (it != GuiScreens.end())
	{
		if ((*it)->GetName() == name)
			return nullptr;
		it++;
	}
	GuiObject* gui = new GuiScreen(name);
	GuiScreens.insert(GuiScreens.end(), gui);

	return gui;
}

bool SDL_Game::GuiRenderer::RemoveScreenGui(std::string name)
{
	std::set<GuiObject*>::iterator it = GuiScreens.begin();

	while (it != GuiScreens.end())
	{
		if ((*it)->GetName() == name)
		{
			GuiScreens.erase(it);
			return true;
		}
		it++;
	}
	//GuiScreens.insert(GuiScreens.end(), new GuiScreen(name));

	return false;
}