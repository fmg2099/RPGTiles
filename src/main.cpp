/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <cstdio>
#include "maptinytown.h"
#include "Funny.h"
#include "LinkedList.h"
#include "Inventory.h"
#include "PlayerCharacter.h"

// #include "Functions.h"
int main ()
{
	//dll test
	//int a = Sumar(2, 3);
	//printf("Sumar(2,3) = %i\n", a);
	//Funny funny;
	//int a = funny.Sumar(2, 3);
	//printf("Sumar(2,3) = %i\n", a);

	//prueba de lista ligada
	int a = 16;
	LLNode<int>* nodo = new LLNode<int>(&a);
	
	LinkedList<int>* lista = new LinkedList<int>( nodo  );
	lista->AddNode(new int(28));
	lista->AddNode(new int(42));
	lista->RemoveLastNode();




	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(640, 480, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory

	Texture tiles[MAX_TILES];
	char buffer[32];
	for (size_t i = 0; i < MAX_TILES; i++)
	{
		sprintf(buffer, "tinytown/Tiles/tile_%04zu.png", i);
		tiles[i] = LoadTexture(buffer);
	}
	//calcular escala para mostrar
	float tileScale = TILE_SIZE / tiles[0].width;

	size_t n = sizeof(tilemap) / sizeof(tilemap[0]);
	if (n != (TILEMAPX * TILEMAPY))
	{
		puts("Error, el mapa no es x y");
		return 1;
	}
	
	//crear al jugador
	//prueba de inventario
	Inventory* inventario = new Inventory();
	inventario->AddItem(new Item("Espada", 1));
	inventario->AddItem(new Item("Pocion", 2));
	inventario->AddItem(new Item("Mondongo", 3));
	inventario->debugPrintContents();

	PlayerCharacter* player = new PlayerCharacter();
	player->Start();
	player->inventory = inventario;
		
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		//update al jugador
		player->Update();

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);

		for (int i = 0; i < TILEMAPY; i++)
		{
			for (int j = 0; j < TILEMAPX; j++)
			{
				int offset = TILEMAPX * i + j;
				DrawTextureEx(tiles[ tilemap[offset]], { j* TILE_SIZE - player->cameraOffset.x, i* TILE_SIZE - player->cameraOffset.y }, 0, tileScale, WHITE);
				//sprintf(buffer, "%i,%i: %i", j, i, offset);
				//DrawText(buffer, j * TILE_SIZE - cameraOffset.x, i * TILE_SIZE - cameraOffset.y,10, YELLOW);
			}
		}

		player->Draw();

		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup

	//y las demas texturas
	for (size_t i = 0; i < MAX_TILES; i++)
	{
		UnloadTexture(tiles[i]);
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
