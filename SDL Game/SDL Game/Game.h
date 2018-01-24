#pragma once
#include <SDL.h>


namespace SDL_Game
{
	class Application;

	class Game
	{
	private:
		Application* app;
		SDL_Event sdl_event;

		bool running;

		void ProcessEvents();
		void ClearRenderer(SDL_Renderer* renderer);
		void Render(SDL_Renderer* renderer);
	public:
		Game(Application* app);
		~Game();

		void GameLoop();
	};
}

