#include "Game.h"
#include "Application.h"

namespace SDL_Game
{
	void Game::ProcessEvents()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				StopGameLoop();
			}
			else
			{
				if (input->KeyPressed("Horizontal-", &e))
					logger->Debug("Horizontal-");
				else if (input->KeyPressed("Horizontal+", &e))
					logger->Debug("Horizontal+");
				else if (input->KeyPressed("Vertical-", &e))
					logger->Debug("Vertical-");
				else if (input->KeyPressed("Vertical+", &e))
					logger->Debug("Vertical+");
			}
		}
	}

	void Game::ClearRenderer(SDL_Renderer* renderer)
	{
		SDL_SetRenderDrawColor(app->GetRenderer(), 0, 0, 0, 255);
		SDL_RenderClear(app->GetRenderer());
	}

	void Game::Draw(SDL_Renderer * renderer)
	{
		SDL_SetRenderDrawColor(app->GetRenderer(), 0, 0, 0, 255);
		SDL_RenderDrawRect(app->GetRenderer(), NULL);
	}

	Game::Game(Application* app)
	{
		this->app = app;
		logger = app->GetLogger();
		input = app->GetInput();
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

			Draw(app->GetRenderer());

			// Render
			SDL_RenderPresent(app->GetRenderer());
		}
	}
	void Game::StopGameLoop()
	{
		running = false;
	}
}
