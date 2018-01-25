#pragma once
#include <SDL.h>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>

namespace SDL_Game
{
	class Input
	{
	private:
		typedef std::multimap<std::string, SDL_Keycode>::iterator MMAPIterator;

		std::multimap<std::string, SDL_Keycode> mmapOfControls;

		bool CommonKeyInput(std::string key, SDL_Event* e);
	public:
		Input();
		~Input();

		bool KeyPressed(std::string key, SDL_Event* e);
		bool KeyDown(std::string key, SDL_Event* e);
		bool KeyUp(std::string key, SDL_Event* e);
	};
}

