#pragma once
#include <string>
#include "raylib.h"
#include "stdio.h"

extern "C"
{
	#include "md5.h"
}

class GameObject
{
protected:
	std::string name;
	//unique id en MD5
	uint8_t uid[16];

public:

	Vector2 position;
	Texture2D texture;

	//constructor recibe un nombre y computa el md5
	GameObject(char* _name) 
	{
		name = _name;
		md5String(_name, uid);
		position = { 0,0 };
		texture = { 0 };
	}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void printUID();
};

