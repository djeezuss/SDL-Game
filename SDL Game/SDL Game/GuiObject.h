#pragma once
#include <string>
#include <set>

struct Vector2Int
{
	int X, Y;

	Vector2Int();
	Vector2Int(int x, int y);
};

struct Color3 {
	int R, G, B;

	Color3();
	Color3(int r, int g, int b);
};

struct UDim
{
	int Offset;
	float Scale;

	UDim();
	UDim(int offset, float scale);
};

struct UDim2
{
	UDim X;
	UDim Y;

	UDim2();
	UDim2(int xOffset, float xScale, int yOffset, float yScale);
	UDim2(UDim x, UDim y);
};

class GuiObject
{
private:
	std::string Name;
	GuiObject* Parent;
	std::set<GuiObject*> Children;

	Vector2Int AbsolutePosition;
	Vector2Int AbsoluteSize;

	UDim2 Position;
	UDim2 Size;
	int ZIndex;

	bool Active;
	bool Visible;

	Color3 BackgroundColor3;
	float BackgroundTransparency;
	//Color3 BorderColor3; later
	//int BorderSizePixel; later
	//float BorderTransparency; later

public:
	GuiObject();
	~GuiObject();

	virtual void Draw(void* renderer) = 0;
};