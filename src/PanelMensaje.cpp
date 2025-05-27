#include "PanelMensaje.h"

void PanelMensaje::update()
{
	{
		if (state == hidden)
		{
			return;
		}
		else if (state == moving)
		{
			LOG("PanelMensaje: Moving to position: desired position "<<desiredPositionY << ", pos" << position.y );
			// interpolacion de movimiento
			if (position.y != desiredPositionY)
			{
				//lerp position
				position.y += (desiredPositionY - position.y) * speed * GetFrameTime();
			}
			if ( abs(desiredPositionY -position.y) < 0.1f)
			{
				position.y = desiredPositionY;
				timer = 0;
				if (desiredPositionY < 0) // If moving up off-screen
				{
					state = hidden; // Hide the panel
					//LOG("stop moving to hidden");
				}
				else
				{
					state = showing; // Show the panel
					//LOG("stop moving to showing");
				}
			}
		}
		else if (state == showing)
		{
			timer += GetFrameTime();
			if (timer > timeOnScreen)
			{
				// Start moving up
				desiredPositionY = -size.y - 10; // Move off-screen
				state = moving;
				//LOG("start hiding");
			}
		}
	}
}

void PanelMensaje::draw()
{
	DrawRectangle(position.x, position.y, size.x, size.y, BEIGE);
	DrawRectangleLines(position.x, position.y, size.x, size.y, DARKBLUE);
	DrawText(message.c_str(), position.x + 10, position.y + 10, 20, DARKGRAY);
}

void PanelMensaje::Show(std::string msg)
{
	//cada vez que se mande llamar show, guardar en un stack el mensaje deseado
	state = moving;
	timer = 0;
	message = msg;
	desiredPositionY = 10; // 10 pixels from the top of the screen
	position.y = -size.y - 10; // Start off-screen
}

