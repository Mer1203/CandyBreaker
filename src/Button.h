#pragma once

const double WIDTH_BUTTON = 210;
const double HEIGHT_BUTTON = 60;

const double POSITION_BUTTON_X = 400.0;

const double positionButtonPlayY = 360.0;
const double positionButtonRulesY = 280.0;
const double positionButtonCreditsY = 200.0;
const double positionButtonExitY = 120.0;

const double BACK_BUTTON_X = 40;
const double BACK_BUTTON_Y = 10;
const double WIDTH_BACK_BUTTON = 80;
const double HEIGHT_BACK_BUTTON = 20;

struct Vector2
{
	double x = 0.0;
	double y = 0.0;
};

extern Vector2 mousePosition;

void ButtonMenuDraw();

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth);
void ChangeButtonColorOnCollision(int buttonY);
void ChangeSceneWhenButtonPressed();

void BackButtonDraw();
bool CheckCollisionMouseBackButton(int buttonX, int buttonY);
void ChangeBackButtonColorOnCollision(); 
void ChangeSceneWhenBackButtonPressed();