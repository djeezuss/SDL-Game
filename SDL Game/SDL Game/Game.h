#pragma once
#include <SDL.h>
#include "Logger.h"
#include "Input.h"
#include "GuiRenderer.h"

namespace SDL_Game
{
	class Application;

	class Game
	{
	private:
		Application* app;
		Logger* logger;
		Input* input;

		GuiRenderer* guiRenderer; //Added from GuiTest branch

		bool running;

		void ProcessEvents();
		void ClearRenderer(SDL_Renderer* renderer);
		void Render(SDL_Renderer* renderer);
	public:
		Game(Application* app);
		~Game();

		void GameLoop();
		void StopGameLoop();
	};
}

