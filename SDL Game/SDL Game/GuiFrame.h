#pragma once
#include "GuiObject.h"

namespace SDL_Game
{
	class GuiFrame : public GuiObject
	{
	public:
		GuiFrame();
		~GuiFrame();

		void Draw(void* renderer) override;
	};
}