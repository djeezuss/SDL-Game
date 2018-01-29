#pragma once
#include "GuiObject.h"

namespace SDL_Game
{
	class GuiScreen : public GuiObject
	{
	private:
		std::set<GuiObject*> ElementToRender;
		bool GuiChanged;

		void PrepareRenderer();

	public:
		GuiScreen();
		GuiScreen(std::string name);
		~GuiScreen();

		void Draw(void* renderer) override;
		void PrepareRenderer(std::set<GuiObject*>* list) override;
		void ForceUpdate();

		void Updated();
	};
}