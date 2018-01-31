#include "Camera.h"


namespace SDL_Game
{
	Camera::Camera(SDL_Rect bounds)
	{
		this->bounds = bounds;
	}


	Camera::~Camera()
	{ }
	void Camera::AddTo(int x, int y)
	{
		bounds.x += x;
		bounds.y += y;
	}

	void Camera::SetPos(int x, int y)
	{
		bounds.x = x;
		bounds.y = y;
	}
}
