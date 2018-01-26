#include "GuiObject.h"

Vector2Int::Vector2Int() {
	X = 0;
	Y = 0;
}

Vector2Int::Vector2Int(int x, int y) {
	X = x;
	Y = y;
}

Color3::Color3() {
	R = 0;
	G = 0;
	B = 0;
}

Color3::Color3(int r, int g, int b) {
	R = r;
	G = g;
	B = b;
}

UDim::UDim() {
	Offset = 0;
	Scale = 0.0f;
}

UDim::UDim(int offset, float scale) {
	Offset = offset;
	Scale = scale;
}

UDim2::UDim2() {
	X.Offset = 0;
	X.Scale = 0.0f;
	Y.Offset = 0;
	Y.Scale = 0.0f;
}

UDim2::UDim2(int xOffset, float xScale, int yOffset, float yScale) {
	X.Offset = xOffset;
	X.Scale = xScale;
	Y.Offset = yOffset;
	Y.Scale = yScale;
}

UDim2::UDim2(UDim x, UDim y) {
	X = x;
	Y = y;
}

GuiObject::GuiObject()
{
}


GuiObject::~GuiObject()
{
}
