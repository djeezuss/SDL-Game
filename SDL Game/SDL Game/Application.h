#pragma once
#include <SDL.h>
#include "Logger.h"
#include "Input.h"
#include "Game.h"
#include "GuiRenderer.h"

namespace SDL_Game
{
	class Application
	{
	private:
		int SCREEN_HEIGHT;
		int SCREEN_WIDTH;
		
		Logger* logger;
		Input* input;
		Game* game;

		GuiRenderer* guiRenderer; //Added from GuiTest branch

		SDL_Window* window;
		SDL_Renderer* renderer;
	public:
		Application(std::string title, int width, int heigth);
		~Application();

		void StartGame();
		void Close(int exitId);

		SDL_Renderer* GetRenderer();
		Logger* GetLogger();
		Input* GetInput();
		GuiRenderer* GetGuiRenderer(); //Added from GuiTest branch
	};
}

