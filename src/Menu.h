#pragma once
#include "sl.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

enum class Screen
{
	None = 0,
	Menu,
	Play,
	Rules,
	Credits,
	Exit
};

extern Screen currentScreen;


void MenuDraw();
void MenuUpdate(double time);

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth);
void ChangeButtonColorOnCollision(int buttonY);
void ChangeSceneWhenButtonPressed();