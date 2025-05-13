/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <cstdio>
#include <fstream>

#include "maptinytown.h"
#include "Funny.h"
#include "LinkedList.h"
#include "Inventory.h"
#include "PlayerCharacter.h"
#include "Stack.h"
#include "Queue.h"
#include "PanelMensaje.h"

extern "C"
{
	#include "md5.h"
}


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

	//PRUEBA DE stack o pila
	Stack<float> pila(10);
	std::cout << "Pila vacia: " <<std::boolalpha  << pila.isEmpty() << std::endl;
	pila.push(1.0f);
	pila.push(3.1416);
	pila.push(2.71828);
	std::cout << "num de elementos de la pila: " << pila.size() << std::endl;
	float temp = pila.pop();
	std::cout << "num de elementos de la pila: " << pila.size() << std::endl;

	//prueba de Queue
	Queue<int> q = Queue<int>(3);
	std::cout << "Cola vacia: " << std::boolalpha << q.isEmpty() << std::endl;
	q.enqueue(10);
	q.enqueue(24);
	q.enqueue(42);
	q.enqueue(99);
	q.debugPrintContents();
	int temp2 = q.dequeue();
	temp2 = q.dequeue();
	temp2 = q.dequeue();
	q.debugPrintContents();
	q.enqueue(24);
	q.debugPrintContents();
	std::cout << "num de elementos de la cola: " << q.size() << std::endl;
	std::cout << "peek : " << *q.peek() << std::endl;
	int temp3 = q.dequeue();
	q.debugPrintContents();

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

	PlayerCharacter* player = new PlayerCharacter("player1");
	player->Start();
	player->inventory = inventario;
	player->printUID();

	//hacer unos dos o tres enemigos que se muevan hacia el jugador

	//todos los gameobjects deberemos guardar su uid en esta tabla
	//tablahash(nombre, uid)


	//panelmensaje
	PanelMensaje* panel = new PanelMensaje(  GetScreenWidth() - 210 , 200, 50, 2);

	//para la prueba, simularemos que  obtiene de golpe un pu;ado de logros
	panel->Show("thief");
	panel->Show("gossip");
	panel->Show("fisher");
	panel->Show("hoarder");


	//prueba de calculo de hash md5 usando la biblioteca de zunawe
	uint8_t result[16]; 
	char* mensaje = "hola mundo";
	md5String(mensaje, result);
	//imprimir el hash en hexadecimal
	// printHash
	std::cout << "hash computado: ";
	for (int i = 0; i < 16; i++)
	{
		//std::cout << std::hex << result[i];
		printf("%02X", result[i]);
	}
	std::cout << std::endl;



		
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		//update al jugador
		player->Update();
		panel->update();

		if (IsKeyPressed(KEY_SPACE))
		{
			panel->Show("Hola Mundo");
		}


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


		//UI se dibuja al ultimo
		panel->draw();
		
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
