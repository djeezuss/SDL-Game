#pragma once
#include <SDL.h>

namespace SDL_Game
{
	class Camera
	{
	private:
		SDL_Rect bounds;
	public:
		Camera(SDL_Rect bounds);
		~Camera();

		void AddTo(int x, int y);
		void SetPos(int x, int y);
	};
}

