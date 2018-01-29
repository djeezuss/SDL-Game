#include "GuiObject.h"

//----------------------------------------------------------------------------------------
//------------------------------------| Constructors |------------------------------------
//----------------------------------------------------------------------------------------

SDL_Game::Vector2Int::Vector2Int()
{
	X = 0;
	Y = 0;
}

SDL_Game::Vector2Int::Vector2Int(int x, int y)
{
	X = x;
	Y = y;
}

SDL_Game::Color3::Color3()
{
	R = 0;
	G = 0;
	B = 0;
}

SDL_Game::Color3::Color3(int r, int g, int b)
{
	R = r;
	G = g;
	B = b;
}

SDL_Game::UDim::UDim()
{
	Offset = 0;
	Scale = 0.0f;
}

SDL_Game::UDim::UDim(int offset, float scale)
{
	Offset = offset;
	Scale = scale;
}

SDL_Game::UDim2::UDim2()
{
	X.Offset = 0;
	X.Scale = 0.0f;
	Y.Offset = 0;
	Y.Scale = 0.0f;
}

SDL_Game::UDim2::UDim2(int xOffset, float xScale, int yOffset, float yScale)
{
	X.Offset = xOffset;
	X.Scale = xScale;
	Y.Offset = yOffset;
	Y.Scale = yScale;
}

SDL_Game::UDim2::UDim2(UDim x, UDim y)
{
	X = x;
	Y = y;
}

SDL_Game::GuiObject::GuiObject()
{
}

//----------------------------------------------------------------------------------------
//-------------------------------------| Destructors |------------------------------------
//----------------------------------------------------------------------------------------

SDL_Game::GuiObject::~GuiObject()
{
}

//----------------------------------------------------------------------------------------
//-----------------------------------| Public Methods |-----------------------------------
//----------------------------------------------------------------------------------------

std::set<SDL_Game::GuiObject*> SDL_Game::GuiObject::GetChildren()
{
	return Children;
}

std::string SDL_Game::GuiObject::GetName()
{
	return Name;
}

void SDL_Game::GuiObject::SetName(std::string name)
{
	Name = name;
}

int SDL_Game::GuiObject::GetZIndex()
{
	return ZIndex;
}

void SDL_Game::GuiObject::SetZIndex(int zIndex)
{
	ZIndex = zIndex;
}

SDL_Game::GuiObject* SDL_Game::GuiObject::GetParent()
{
	return this->Parent;
}

void SDL_Game::GuiObject::SetParent(GuiObject* parent)
{
	if (this->Parent != nullptr)
	{
		this->Parent->RemoveChild(this);
	}

	this->Parent = parent;
	parent->AddChild(this);
}

void SDL_Game::GuiObject::AddChild(GuiObject* newChild)
{
	Children.insert(Children.end(), newChild);
}

void SDL_Game::GuiObject::RemoveChild(GuiObject * oldChild)
{
	//remove old child
}
