#include "Game.h"
#include "Application.h"

namespace SDL_Game
{
	void Game::ProcessEvents()
	{
		while (SDL_PollEvent(&sdl_event))
		{
			// User requests quit
			if (sdl_event.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}

	void Game::ClearRenderer(SDL_Renderer* renderer)
	{
		SDL_SetRenderDrawColor(app->GetRenderer(), 0, 0, 0, 255);
		SDL_RenderClear(app->GetRenderer());
	}

	void Game::Render(SDL_Renderer * renderer)
	{
		SDL_SetRenderDrawColor(app->GetRenderer(), 0, 0, 0, 255);
		SDL_RenderDrawRect(app->GetRenderer(), NULL);
	}

	Game::Game(Application* app)
	{
		this->app = app;
		running = false;
	}


	Game::~Game()
	{
	}

	void Game::GameLoop()
	{
		running = true;

		while (running)
		{
			ProcessEvents();

			ClearRenderer(app->GetRenderer());

			Render(app->GetRenderer());

			// Update
			SDL_RenderPresent(app->GetRenderer());
		}
	}
}
