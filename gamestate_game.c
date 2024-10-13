//---------------------------------------------------------
// file:	gamestate_game.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	game file for holding gamestate functions
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_game.h"
#include "gamestate_menu.h"
#include "gamestate_over.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int mouseClicks = 0;
float yVelocity;
float gravity;
float yplayerPos;
float xplayerPos;
bool canJump = false;
float boxX;
CP_BOOL cursor3 = TRUE;


void gamestate_game_init(void);
void gamestate_game_update(void);
void gamestate_game_exit(void);

void custom_crusor2(float xPosition, float yPosition)
{
	CP_Settings_Fill(CP_Color_Create(235, 120, 175, 255));
	CP_System_ShowCursor(!cursor3);
	CP_Graphics_DrawEllipseAdvanced(xPosition + 3.0f, yPosition + 15.0f, 7.0f, 25.0f, -35.0f);
	CP_Graphics_DrawTriangleAdvanced(xPosition, yPosition , xPosition - 7.0f, yPosition + 18.0f, xPosition + 7.0f, yPosition + 18.0f, -30.0f);
}

void draw_player(float xPosition, float yPosition)
{
	CP_Settings_Fill(CP_Color_Create(255, 175, 255, 255));
	//CP_Graphics_DrawCircle(xPosition,yPosition, 100.0f);
	CP_Graphics_DrawEllipseAdvanced(xPosition - 10.0f, yPosition, 10.0f, 60.0f, 10.0f);
	CP_Graphics_DrawEllipseAdvanced(xPosition + 10.0f, yPosition, 10.0f, 60.0f, -10.0f);
	CP_Graphics_DrawRect(xPosition, yPosition - 59.0f, 30.0f, 55.0f);
	CP_Graphics_DrawCircle(xPosition, yPosition - 109.0f, 30.0f);
}

void draw_platform(float xPos)
{
	CP_Graphics_DrawRect(xPos, 500.0f, 100.0f, 50.0f);
}

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_game_init(void)
{
	CP_System_SetWindowSize(800, 600);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	mouseClicks = 0;
	yplayerPos = 445.0f;
	xplayerPos = CP_System_GetWindowWidth() / 2.0f;
	CP_System_SetFrameRate(60.0f);
	gravity = 400;



}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(80, 100, 150, 255));

	float xCenter = CP_System_GetWindowWidth() / 2.0f;
	//float yCenter = CP_System_GetWindowHeight() / 2.0f;
	float bottomBox = 500.0f;
	float realGround = 445.0f;
	
	
	

	if (CP_Input_KeyTriggered(KEY_SPACE) && canJump)
	{
		++mouseClicks;
	}
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));

	CP_Settings_TextSize(50.0f);

	char buffer[50] = { 0 };
	sprintf_s(buffer, _countof(buffer), "Times Jumped: %i", mouseClicks);

	CP_Font_DrawText(buffer, 25.0f, 50.0f);




	if (CP_Input_KeyTriggered(KEY_SPACE) && canJump)
	{
		boxX = CP_Random_RangeFloat(100.0f, 700.0f);

		
	}
		CP_Settings_Fill(CP_Color_Create(220, 20, 64, 255));
		CP_Graphics_DrawRect(xCenter, 800.0f, 810.0f, 600.0f);
		CP_Settings_Fill(CP_Color_Create(70, 30, 100, 255));
		draw_platform(boxX);


	if ((mouseClicks == 0))
	{
		CP_Settings_Fill(CP_Color_Create(220, 20, 64, 255));
		CP_Graphics_DrawRect(xCenter, 800.0f, 810.0f, 600.0f);

		CP_Settings_Fill(CP_Color_Create(70, 30, 100, 255));
		CP_Graphics_DrawRect(xCenter, bottomBox, 810.0f, 50.0f);

	}
	else
	{
		
	}

	if (CP_Input_KeyDown(KEY_SPACE) && canJump)
	{
		
		yVelocity += -400 * CP_System_GetDt();
		yplayerPos += CP_System_GetDt() * yVelocity;
		if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
		{
			xplayerPos -= -250 * CP_System_GetDt();
		}
		if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
		{
			xplayerPos -= 250 * CP_System_GetDt();
		}
	}

	else
	{
		if (yplayerPos < realGround)
		{
			canJump = false;
			yVelocity += gravity * CP_System_GetDt();
			yplayerPos += CP_System_GetDt() * yVelocity;
			if (CP_Input_KeyDown(KEY_D) || CP_Input_KeyDown(KEY_RIGHT))
			{
				xplayerPos -= -250 * CP_System_GetDt();
			}
			if (CP_Input_KeyDown(KEY_A) || CP_Input_KeyDown(KEY_LEFT))
			{
				xplayerPos -= 250 * CP_System_GetDt();
			}
			
		}
		else
		{
			if (mouseClicks > 0)
			{
				if (xplayerPos > boxX - 50.0f &&
					xplayerPos < boxX + 50.0f)
				{
					canJump = true;
					yVelocity = 0;

					yplayerPos = realGround;
	
				}
				else
				{
					yVelocity += gravity * CP_System_GetDt();
					yplayerPos += CP_System_GetDt() * yVelocity;
					if (yplayerPos > 800.0f)
					{
						CP_Engine_SetNextGameStateForced(gamestate_over_init, gamestate_over_update, gamestate_over_exit);;
					}
				}

			}
			else
			{
				canJump = true;
				yVelocity = 0;

				yplayerPos = realGround;
			}
			
			
		}

	}

	draw_player(xplayerPos, yplayerPos);

	/*yplayerPos = realGround;
	draw_player(xCenter, yplayerPos);*/



	CP_Settings_Fill(CP_Color_Create(250, 250, 250, 255));
	CP_Graphics_DrawRect(700.0f, 75.0f, 100.0f, 100.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(35.0f);
	CP_Font_DrawText("Reset", 668.0f, 79.0f);
		if (CP_Input_GetMouseX() > 700.0f - 100.0f / 2.0f &&
			CP_Input_GetMouseX() < 700.0f + 100.0f / 2.0f &&
			CP_Input_GetMouseY() > 75.0f - 100.0f / 2.0f &&
			CP_Input_GetMouseY() <  75.0f + 100.0f / 2.0f)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_SetNextGameStateForced(gamestate_game_init, gamestate_game_update, gamestate_game_exit);
			}
			
		}
		
		if (CP_Input_KeyTriggered(KEY_Q))
		{
			CP_Engine_Terminate();
	    }


		custom_crusor2(CP_Input_GetMouseX(), CP_Input_GetMouseY());

		// check input, update simulation, render etc.




	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
