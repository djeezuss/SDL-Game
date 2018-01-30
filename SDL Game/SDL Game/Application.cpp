#include "Application.h"


namespace SDL_Game
{
	Application::Application(std::string title, int width, int heigth)
	{
		logger = new Logger();
		input = new	Input();

		window = NULL;
		renderer = NULL;

		SCREEN_WIDTH = width;
		SCREEN_HEIGHT = heigth;

		logger->Info("Initialising SDL ...");
		if (SDL_Init(SDL_INIT_EVERYTHING))
		{
			logger->Error("SDL could not initialise : " + std::string(SDL_GetError()));
			Close(-1);
		}
		logger->Info("SDL initialised.");
		
		logger->Info("Creating the Window ...");
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			logger->Error("SDL Window could not initialise : " + std::string(SDL_GetError()));
			Close(-1);
		}
		logger->Info("Window created.");

		logger->Info("Creating the Renderer ...");
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL)
		{
			logger->Error("SDL Renderer could not initialise : " + std::string(SDL_GetError()));
			Close(-1);
		}
		logger->Info("Renderer created.");

		game = new Game(this);
	}


	Application::~Application()
	{
		delete logger;
		delete input;
		delete game;

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
	}

	void Application::StartGame()
	{
		logger->Info("Starting main Game Loop.");
		game->GameLoop();
	}

	void Application::Close(int exitId)
	{
		game->StopGameLoop();
	}

	SDL_Renderer* Application::GetRenderer()
	{
		return renderer;
	}
	Logger * Application::GetLogger()
	{
		return logger;
	}
	Input * Application::GetInput()
	{
		return input;
	}
}
