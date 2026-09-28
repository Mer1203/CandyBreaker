#pragma once

const double WIDTH_BUTTON = 210;
const double HEIGHT_BUTTON = 60;

const double POSITION_BUTTON_X = 400.0;

const double positionButtonPlayY = 340.0;
const double positionButtonRulesY = 260.0;
const double positionButtonCreditsY = 180.0;
const double positionButtonExitY = 100.0;

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

void ButtonMenuDraw(int playButton, int rulesButton, int creditsButton, int exitButton);

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth);
void ChangeButtonColorOnCollision(int buttonY, int img);
void ChangeSceneWhenButtonPressed();

void BackButtonDraw();
void ChangeBackButtonColorOnCollision(); 
void ChangeSceneWhenBackButtonPressed();