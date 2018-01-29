#pragma once
#include <string>
#include <set>

namespace SDL_Game
{
	struct Vector2Int
	{
		int X, Y;

		Vector2Int();
		Vector2Int(int x, int y);
	};

	struct Color3
	{
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

	//Commented variables are yet to be implemented
	class GuiObject
	{
	protected:
		std::string Name;				//A name used to find this element during runtime
		GuiObject* Parent;				//A reference to the parent object
		std::set<GuiObject*> Children;	//References to all children objects

		Vector2Int AbsolutePosition;	//The position in pixel on the screen
		Vector2Int AbsoluteSize;		//The size in pixel on the screen

		UDim2 Position;					//
		UDim2 Size;						//
		int ZIndex;						//

		//bool Active;					//Should this Gui element allow mouse interaction
		bool Visible;					//Should this Gui element be displayed (with all of it children)

		//Color3 BackgroundColor3;		//The background color
		//float BackgroundTransparency;	//The background transparency
		//Color3 BorderColor3;			//The color of the border
		//int BorderSizePixel;			//The size in pixel of the border
		//float BorderTransparency;		//The border transparency
		

	public:
		GuiObject();
		~GuiObject();

		std::set<GuiObject*> GetChildren();
		virtual void Draw(void* sdl_renderer) = 0;
		virtual void PrepareRenderer(std::set<GuiObject*>* list) = 0;
		std::string GetName();
		void SetName(std::string name);

		int GetZIndex();
		void SetZIndex(int zIndex);

		GuiObject* GetParent();
		void SetParent(GuiObject* parent);

		void AddChild(GuiObject* newChild);
		void RemoveChild(GuiObject* oldChild);

	};
}