//---------------------------------------------------------
// file:	gamestate_menu.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	menu file for holding gamestate functions
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_menu.h"
#include "gamestate_game.h"
#include "gamestate_credits.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


CP_BOOL cursor5 = TRUE;
float buttonWidth = 200.0f;
float buttonHeight = 100.0f;

void custom_crusor4(float xPosition, float yPosition)
{
	CP_Settings_Fill(CP_Color_Create(235, 120, 175, 255));
	CP_System_ShowCursor(!cursor5);
	CP_Graphics_DrawEllipseAdvanced(xPosition + 3.0f, yPosition + 15.0f, 7.0f, 25.0f, -35.0f);
	CP_Graphics_DrawTriangleAdvanced(xPosition, yPosition, xPosition - 7.0f, yPosition + 18.0f, xPosition + 7.0f, yPosition + 18.0f, -30.0f);
}

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_menu_init(void)
{
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_System_SetWindowSize(800, 600);
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_menu_update(void)
{
	
	CP_Graphics_ClearBackground(CP_Color_Create(200, 205, 210, 255));
	CP_Color buttonColor = CP_Color_Create(230, 230, 210, 255);
	CP_Color buttonColor2 = CP_Color_Create(230, 230, 210, 255);
	float buttonX = 400.0f;
	float buttonY = 300.0f;

	

	if (CP_Input_GetMouseX() > buttonX - buttonWidth / 2.0f &&
		CP_Input_GetMouseX() < buttonX + buttonWidth / 2.0f &&
		CP_Input_GetMouseY() > 450.0f - buttonHeight / 2.0f &&
		CP_Input_GetMouseY() < 450.0f + buttonHeight / 2.0f)
	{
		buttonColor2 = CP_Color_Create(239, 45, 45, 255);
		if (CP_Input_MouseClicked())
		{
			CP_Engine_Terminate();
		}
	}

	CP_Settings_Fill(buttonColor2);
	CP_Graphics_DrawRect(buttonX, 450.0f, buttonWidth, buttonHeight);

	CP_Settings_TextSize(50.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("QUIT", 350.0f, 470.0f);

	if (CP_Input_GetMouseX() > buttonX - buttonWidth / 2.0f &&
		CP_Input_GetMouseX() < buttonX + buttonWidth / 2.0f &&
		CP_Input_GetMouseY() > buttonY - buttonHeight / 2.0f &&
		CP_Input_GetMouseY() < buttonY + buttonHeight / 2.0f)
	{
		buttonColor = CP_Color_Create(239, 45, 45, 255);
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameState(gamestate_game_init, gamestate_game_update, gamestate_game_exit);
		}
	}
	CP_Settings_Fill(buttonColor);
	CP_Graphics_DrawRect(buttonX, buttonY, buttonWidth, buttonHeight);

	CP_Settings_TextSize(50.0f);
	CP_Settings_Fill(CP_Color_Create(0,0,0, 255));
	CP_Font_DrawText("START", 340.0f, 315.0f);
	CP_Settings_TextSize(75.0f);
	CP_Font_DrawText("HOT FEET", 270.0f, 150.0f);

	CP_Settings_Fill(CP_Color_Create(230, 230, 210, 255));
	CP_Graphics_DrawRect(700.0f, 75.0f, 100.0f, 100.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(35.0f);
	CP_Font_DrawText("Credits", 656.0f, 79.0f);
	if (CP_Input_GetMouseX() > 700.0f - 100.0f / 2.0f &&
		CP_Input_GetMouseX() < 700.0f + 100.0f / 2.0f &&
		CP_Input_GetMouseY() > 75.0f - 100.0f / 2.0f &&
		CP_Input_GetMouseY() < 75.0f + 100.0f / 2.0f)
	{
		if (CP_Input_MouseClicked())
		{
			CP_Engine_SetNextGameStateForced(gamestate_credits_init, gamestate_credits_update, gamestate_credits_exit);
		}

	}
	custom_crusor4(CP_Input_GetMouseX(), CP_Input_GetMouseY());
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_menu_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
