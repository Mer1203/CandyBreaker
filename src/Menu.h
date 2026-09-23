#pragma once
#include "sl.h"

const double positionButtonX = 400.0;

const double positionButtonPlayY = 360.0;
const double positionButtonRulesY = 280.0;
const double positionButtonCreditsY = 200.0;
const double positionButtonExitY = 120.0;

const double widthButton = 210;
const double heightButton = 60;

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
void Menu();

int slGetMouseX();
int slGetMouseY();