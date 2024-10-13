//---------------------------------------------------------
// file:	gamestate_over.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	over file for holding gamestate functions
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_over.h"
#include "gamestate_menu.h"
#include "gamestate_game.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

CP_BOOL cursor2 = TRUE;
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void custom_crusor(float xPosition, float yPosition)
{
	CP_Settings_Fill(CP_Color_Create(235, 120, 175, 255));
	CP_System_ShowCursor(!cursor2);
	CP_Graphics_DrawEllipseAdvanced(xPosition + 3.0f, yPosition + 15.0f, 7.0f, 25.0f, -35.0f);
	CP_Graphics_DrawTriangleAdvanced(xPosition, yPosition, xPosition - 7.0f, yPosition + 18.0f, xPosition + 7.0f, yPosition + 18.0f, -30.0f);
}

void gamestate_over_init(void)
{
	CP_System_SetWindowSize(800, 600);
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_over_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(75.0f);
	CP_Font_DrawText("GAME OVER", 230.0f, 150.0f);
	
	
	CP_Settings_Fill(CP_Color_Create(250, 250, 250, 255));
	CP_Graphics_DrawRect(400.0f, 300.0f, 300.0f, 100.0f);
	if (CP_Input_GetMouseX() > 400.0f - 300.0f / 2.0f &&
		CP_Input_GetMouseX() < 400.0f + 300.0f / 2.0f &&
		CP_Input_GetMouseY() > 300.0f - 100.0f / 2.0f &&
		CP_Input_GetMouseY() < 300.0f + 100.0f / 2.0f)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameStateForced(gamestate_game_init, gamestate_game_update, gamestate_game_exit);
		}

	}
	CP_Settings_TextSize(50.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("TRY AGAIN?", 280.0f, 315.0f);


	CP_Settings_Fill(CP_Color_Create(250, 250, 250, 255));
	CP_Graphics_DrawRect(400.0f, 500.0f, 200.0f, 100.0f);
	if (CP_Input_GetMouseX() > 400.0f - 200.0f / 2.0f &&
		CP_Input_GetMouseX() < 400.0f + 200.0f / 2.0f &&
		CP_Input_GetMouseY() > 500.0f - 100.0f / 2.0f &&
		CP_Input_GetMouseY() < 500.0f + 100.0f / 2.0f)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameStateForced(gamestate_menu_init, gamestate_menu_update, gamestate_menu_exit);
		}

	}
	CP_Settings_TextSize(50.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("MENU", 350.0f, 515.0f);
	custom_crusor(CP_Input_GetMouseX(), CP_Input_GetMouseY());
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_over_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
