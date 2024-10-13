//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_splash.h"
#include "gamestate_menu.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program

//void game_update(void);
//void game_exit(void);

void pre_update(void)
{
	if (CP_Input_KeyTriggered(KEY_ESCAPE))
		CP_Engine_Terminate();
}
void game_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
	CP_System_SetWindowSize(800, 600);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Graphics_ClearBackground(CP_Color_Create(50, 100, 150, 255));
	
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame


// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate


// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{ 
	CP_System_ShowCursor(false);
	CP_Engine_SetPreUpdateFunction(pre_update);
	CP_System_SetWindowSize(800, 600);
	CP_Engine_SetNextGameState(gamestate_splash_init, gamestate_splash_update,
		gamestate_splash_exit);
	CP_Engine_Run();
	return 0;

}
