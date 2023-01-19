#pragma once

#include "raylib-cpp.hpp"

class GameObject
{
protected:
	virtual void OnUpdate() { }
	virtual void OnDraw() { }

public:
	raylib::Vector2 localPosition = {};
	float localRotation = 0.0f;
	raylib::Vector2 localScale = {1,1};

	void Update() { OnUpdate(); }
	void Draw() { OnDraw(); }
};