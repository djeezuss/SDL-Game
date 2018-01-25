#include "Input.h"


namespace SDL_Game
{
	bool Input::CommonKeyInput(std::string key, SDL_Event* e)
	{
		// It returns a pair representing the range of elements
		std::pair<MMAPIterator, MMAPIterator> range = mmapOfControls.equal_range(key);

		SDL_Keycode kc;
		// Iterate over the range
		for (MMAPIterator it = range.first; it != range.second; it++)
		{
			kc = it->second;

			// Checks if the Keycodes matche
			if (e->key.keysym.sym == kc)
			{
				return true;
			}
		}

		return false;
	}

	Input::Input()
	{
		mmapOfControls = {
			{ "Horizontal-", SDLK_a },
			{ "Horizontal-", SDLK_LEFT },
			{ "Horizontal+", SDLK_d },
			{ "Horizontal+", SDLK_RIGHT },
			{ "Vertical-", SDLK_w },
			{ "Vertical-", SDLK_DOWN },
			{ "Vertical+", SDLK_s },
			{ "Vertical+", SDLK_UP },
			{ "Jump", SDLK_SPACE }
		};
	}


	Input::~Input()
	{}

	bool Input::KeyPressed(std::string key, SDL_Event* e)
	{
		if (e->key.type == SDL_KEYDOWN && e->key.repeat > 0)
			return false;
		return CommonKeyInput(key, e);
	}

	bool Input::KeyDown(std::string key, SDL_Event* e)
	{
		if (e->key.type != SDL_KEYDOWN)
			return false;
		return CommonKeyInput(key, e);
	}

	bool Input::KeyUp(std::string key, SDL_Event* e)
	{
		if (e->key.type != SDL_KEYUP)
			return false;
		return CommonKeyInput(key, e);
	}
}
