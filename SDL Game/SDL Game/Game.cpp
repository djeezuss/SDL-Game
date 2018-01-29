#include "Game.h"
#include "Application.h"
#include <SDL_image.h>

#include "GuiImageLabel.h"
#include "GuiScreen.h"

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

	void Game::Render(SDL_Renderer * renderer)
	{
		SDL_SetRenderDrawColor(app->GetRenderer(), 0, 0, 0, 255);
		SDL_RenderDrawRect(app->GetRenderer(), NULL);
	}

	Game::Game(Application* app)
	{
		this->app = app;
		logger = app->GetLogger();
		input = app->GetInput();
		guiRenderer = app->GetGuiRenderer(); //Added from GuiTest branch
		running = false;
	}


	Game::~Game()
	{
	}

	void Game::GameLoop()
	{
		running = true;
		

		//-----------------------------------------------GuiTest Begin

		GuiObject* gui = nullptr;
		if (gui = guiRenderer->AddScreenGui())
			logger->Info("New Gui Added!");
		else
			logger->Info("Failed to add Gui");

		SDL_Texture* texture = IMG_LoadTexture(app->GetRenderer(), "assets/images/SimpleBox.png");
		GuiImageLabel* image = new GuiImageLabel(texture);
		image->SetName("Image Label");
		image->SetParent(gui);

		GuiImageLabel* image2 = new GuiImageLabel(texture);
		image2->SetName("Image Label2");
		image2->SetParent(image);


		//-----------------------------------------------GuiTest End

		while (running)
		{
			ProcessEvents();

			ClearRenderer(app->GetRenderer());

			Render(app->GetRenderer());


			//-----------------------------------------------GuiTest Begin

			guiRenderer->RenderGui(app->GetRenderer());

			//-----------------------------------------------GuiTest End
			

			// Update
			SDL_RenderPresent(app->GetRenderer());
		}
	}
	void Game::StopGameLoop()
	{
		running = false;
	}
}
