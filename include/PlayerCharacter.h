#pragma once
#include "raylib.h"
#include "Inventory.h"

class PlayerCharacter
{

public:
	Vector2 position;
	float speed = 100.0f;
	Texture2D texture;

	//variables para la camara
	float scrollBorder = 100;
	Vector2 cameraOffset = { 0, 0 };

	Inventory* inventory;

	void Start();
	void Update();
	void Draw();

};

