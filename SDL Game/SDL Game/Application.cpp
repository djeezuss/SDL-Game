#include "Application.h"


namespace SDL_Game
{
	Application::Application(std::string title, int width, int heigth)
	{
		logger = new Logger();

		window = NULL;
		renderer = NULL;

		SCREEN_WIDTH = width;
		SCREEN_HEIGHT = heigth;

		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			logger->Error("SDL could not initialise : " + std::string(SDL_GetError()) + "\n");
			Close(-1);
		}
		
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			logger->Error("SDL Window could not initialise : " + std::string(SDL_GetError()));
			Close(-1);
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL)
		{
			logger->Error("SDL Renderer could not initialise : " + std::string(SDL_GetError()));
			Close(-1);
		}

		game = new Game(this);
	}


	Application::~Application()
	{
		delete logger;
		delete game;

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
	}

	void Application::StartGame()
	{
		game->GameLoop();
	}

	void Application::Close(int exitId)
	{
		system("pause");
		exit(exitId);
	}

	SDL_Renderer* Application::GetRenderer()
	{
		return renderer;
	}
}
