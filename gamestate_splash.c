//---------------------------------------------------------
// file:	gamestate_splash.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	splash file for holding gamestate functions
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_splash.h"
#include "gamestate_menu.h"
#include "gamestate_game.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

CP_BOOL cursor4 = TRUE;

float timer;
CP_Image logo;
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void custom_crusor3(float xPosition, float yPosition)
{
	CP_Settings_Fill(CP_Color_Create(235, 120, 175, 255));
	CP_System_ShowCursor(!cursor4);
	CP_Graphics_DrawEllipseAdvanced(xPosition + 3.0f, yPosition + 15.0f, 7.0f, 25.0f, -35.0f);
	CP_Graphics_DrawTriangleAdvanced(xPosition, yPosition, xPosition - 7.0f, yPosition + 18.0f, xPosition + 7.0f, yPosition + 18.0f, -30.0f);
}

void gamestate_splash_init(void)

{
	CP_System_SetWindowSize(800, 600);
	timer = 0.0f;
	logo = CP_Image_Load("./Assets/DigiPen_BLACK.png");
	CP_System_SetWindowTitle("Hot Feet");
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_splash_update(void)
{

	CP_Graphics_ClearBackground(CP_Color_Create(150, 100, 150, 255));
	float one = CP_System_GetSeconds() * 150.0f;
	if (one > 400.0f)
		one = 400;

	timer += CP_System_GetDt();
	if (timer < 3.0f)
	{
		CP_Image_Draw(logo, one, 300.0f, 1026.0f * 0.7f, 248.0f * 0.7f, 255);
		
	}
	if (timer > 3.0f && timer < 7.0f)
	{
		CP_Image_Draw(logo, 400.0f, 300.0f, CP_System_GetSeconds() * 40.0f + (1026.0f * 0.7f), CP_System_GetSeconds() * 40.0f + (240.0f * 0.7f), (int)(255 - CP_System_GetSeconds() * 40));
	}
	if (timer > 7.0f)
	{
		
		CP_Engine_SetNextGameState(gamestate_menu_init, gamestate_menu_update, gamestate_menu_exit);
	}
	custom_crusor3(CP_Input_GetMouseX(), CP_Input_GetMouseY());
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_splash_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
