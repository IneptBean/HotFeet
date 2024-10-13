//---------------------------------------------------------
// file:	gamestate_credits.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	credits file for holding gamestate functions
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_credits.h"
#include "gamestate_menu.h"
#include "gamestate_game.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

CP_BOOL cursor1 = TRUE;
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void custom_crusor1(float xPosition, float yPosition)
{
	CP_Settings_Fill(CP_Color_Create(235, 120, 175, 255));
	CP_System_ShowCursor(!cursor1);
	CP_Graphics_DrawEllipseAdvanced(xPosition + 3.0f, yPosition + 15.0f, 7.0f, 25.0f, -35.0f);
	CP_Graphics_DrawTriangleAdvanced(xPosition, yPosition, xPosition - 7.0f, yPosition + 18.0f, xPosition + 7.0f, yPosition + 18.0f, -30.0f);
}

void gamestate_credits_init(void)
{
	CP_System_SetWindowSize(800, 600);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_credits_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 205, 210, 255));

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));

	CP_Settings_TextSize(75.0f);
	CP_Font_DrawText("CREDITS", 270.0f, 90.0f);

	CP_Settings_TextSize(65.0f);
	CP_Font_DrawText("BY: SABINE ALIEV", 170.0f, 200.0f);

	CP_Settings_TextSize(65.0f);
	CP_Font_DrawText("INSTRUCTOR: ANDY ELLINGER", 50.0f, 300.0f);

	CP_Settings_TextSize(65.0f);
	CP_Font_DrawText("SPECIAL THANKS: CATS IDK", 100.0f, 400.0f);

	CP_Settings_TextSize(30.0f);
	CP_Font_DrawText("Copyright (c) 2020 DigiPen, All rights reserved.", 60.0f, 550.0f);

	CP_Settings_Fill(CP_Color_Create(230, 230, 210, 255));
	CP_Graphics_DrawRect(700.0f, 525.0f, 100.0f, 100.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(35.0f);
	CP_Font_DrawText("Menu", 656.0f, 555.0f);
	if (CP_Input_GetMouseX() > 700.0f - 100.0f / 2.0f &&
		CP_Input_GetMouseX() < 700.0f + 100.0f / 2.0f &&
		CP_Input_GetMouseY() > 525.0f - 100.0f / 2.0f &&
		CP_Input_GetMouseY() < 525.0f + 100.0f / 2.0f)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameStateForced(gamestate_menu_init, gamestate_menu_update, gamestate_menu_exit);
		}

	}
	custom_crusor1(CP_Input_GetMouseX(), CP_Input_GetMouseY());
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_credits_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
