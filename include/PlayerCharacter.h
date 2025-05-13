#pragma once
#include "raylib.h"
#include "Inventory.h"
#include <string>
#include "GameObject.h"
class PlayerCharacter : public  GameObject
{

public:
	float speed = 100.0f;
	//variables para la camara
	float scrollBorder = 100;
	Vector2 cameraOffset = { 0, 0 };

	Inventory* inventory;

	PlayerCharacter(char* _name) : GameObject(_name)
	{}

	void Start() override;
	void Update() override;
	void Draw() override;

private:


};

