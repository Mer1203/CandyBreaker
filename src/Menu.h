#pragma once
#include "sl.h"

const double WIDTH_BUTTON = 210;
const double HEIGHT_BUTTON = 60;

const double POSITION_MENU_BUTTON_X = 400.0;

const double positionButtonPlayY = 360.0;
const double positionButtonRulesY = 280.0;
const double positionButtonCreditsY = 200.0;
const double positionButtonExitY = 120.0;

const double positionGameNameX = 170;
const double positionGameNameY = 90;
const double fontSizeGameName = 80;

const double positionTextX = 300;
const double positionTextY = 80;

const double fontSizeButtonName = 40;

const double positionButtonNamePlayX = 344;
const double positionButtonNamePlayY = 200;

const double positionButtonNameRulesX = 330;
const double positionButtonNameRulesY = 300;

const double positionButtonNameCreditsX = 304;
const double positionButtonNameCreditsY = 400;

const double positionButtonNameExitX = 100.0;
const double positionButtonNameExitY = 500;

const double positionBackButtonX = 0;
const double positionBackButtonY = 0;
const double backButtonWidth = 90;
const double backButtonHeight = 30;

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

struct Vector2
{
	double x = 0.0;
	double y = 0.0;
};

extern Vector2 mousePosition;

void Menu();

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth);
void ChangeButtonColorOnCollision(int buttonY);