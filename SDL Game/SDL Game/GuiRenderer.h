#pragma once
#include "GuiObject.h"

namespace SDL_Game
{
	class GuiRenderer
	{
	private:
		std::set<GuiObject*> GuiScreens;


	public:
		GuiRenderer();
		~GuiRenderer();

		void RenderGui(void* sdl_renderer);

		/*
		Add a brand new Screen Gui (@name must be unique for each Screen Gui)
		return true if @name is unique, false otherwise
		*/
		GuiObject* AddScreenGui(std::string name = "Gui Main");
		bool RemoveScreenGui(std::string name = "Gui Main");
	};
}