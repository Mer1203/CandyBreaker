#pragma once

const double WIDTH_BUTTON = 210;
const double HEIGHT_BUTTON = 60;

const double POSITION_BUTTON_X = 400.0;

const double positionButtonPlayY = 320.0;
const double positionButtonRulesY = 240.0;
const double positionButtonCreditsY = 160.0;
const double positionButtonExitY = 80.0;
const double positionButtonBackY = 400.0;

const double BACK_BUTTON_X = 30;
const double BACK_BUTTON_Y = 30;
const double WIDTH_BACK_BUTTON = 60;
const double HEIGHT_BACK_BUTTON = 60;

struct Vector2
{
	double x = 0.0;
	double y = 0.0;
};

extern Vector2 mousePosition;

void ButtonMenuDraw(int playButton, int rulesButton, int creditsButton, int exitButton);

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth);
void ChangeButtonColorOnCollision(int img, double buttonX, double buttonY, double width, double height);
void ChangeSceneWhenButtonPressed();

void BackButtonDraw(int backButton);
void ChangeSceneWhenBackButtonPressed();

bool Win(int font, int backButtonGame);
bool Lose(int font, int backButtonGame);