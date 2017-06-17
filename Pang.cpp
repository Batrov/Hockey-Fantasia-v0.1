// Pang.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
int main()
{
	Game::Start();

	return 0;
}

