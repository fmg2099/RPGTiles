#pragma once
#include "raylibExt.h"

enum PanelState
{
	hidden, moving, showing
};

class PanelMensaje
{

private:
	float timer;
	float desiredPositionY;
	PanelState state = hidden;

public:
	Vector2 position;
	Vector2 size;
	int timeOnScreen;
	float speed = 10.0f;
	std::string message;

	PanelMensaje( float posX, float width, float height, int _timeOnScreen)
	{
		position = { posX,   -height }; // Start off-screen
		size = { width, height };
		timeOnScreen = _timeOnScreen;
		timer = 0;
		desiredPositionY = -height; // Start off-screen
		state = hidden;
	}

	void update();
	void draw();
	void Show(std::string msg);
};
