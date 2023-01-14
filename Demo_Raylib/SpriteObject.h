#include "GameObject.h"

#include <string_view>

class SpriteObject : public GameObject
{
public:
	raylib::Texture sprite;
	Color tint = raylib::Color::White();
	raylib::Vector2 origin = { 0.5f, 0.5f };

	SpriteObject() = default;
	SpriteObject(std::string_view str)
	{
		sprite = raylib::Texture(str.data());
	}

protected:
	void OnDraw() override
	{
		sprite.Draw(Rectangle{ 0,0, (float)sprite.GetWidth(), (float)sprite.GetWidth() },
			Rectangle{ localPosition.x, localPosition.y, (float)sprite.GetWidth() * localScale.GetX(), (float)sprite.GetWidth() * localScale.GetY() },
			{ sprite.GetWidth() * localScale.x, sprite.GetHeight() * localScale.y },
			localRotation,
			tint);
	}
};