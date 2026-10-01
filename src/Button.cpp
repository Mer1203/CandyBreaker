#include "Button.h"
#include "Menu.h"
#include "Text.h"
#include "sl.h"

Vector2 mousePosition;

void BackButtonDraw(int backButton)
{
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slSprite(backButton, BACK_BUTTON_X, BACK_BUTTON_Y, WIDTH_BACK_BUTTON, HEIGHT_BACK_BUTTON);
}

void ChangeSceneWhenBackButtonPressed()
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(BACK_BUTTON_X, BACK_BUTTON_Y, HEIGHT_BACK_BUTTON, WIDTH_BACK_BUTTON) ||
			CheckCollisionMouseButton(POSITION_BUTTON_X, positionButtonBackY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Menu;
		}
	}
}

void ButtonMenuDraw(int playButton, int rulesButton, int creditsButton, int exitButton)
{
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSprite(playButton, POSITION_BUTTON_X, positionButtonPlayY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slSprite(rulesButton, POSITION_BUTTON_X, positionButtonRulesY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slSprite(creditsButton, POSITION_BUTTON_X, positionButtonCreditsY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slSprite(exitButton, POSITION_BUTTON_X, positionButtonExitY, WIDTH_BUTTON, HEIGHT_BUTTON);
}

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth)
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	return buttonX - buttonWidth / 2 <= mousePosition.x && buttonX + buttonWidth / 2 >= mousePosition.x
		&& mousePosition.y >= buttonY - buttonHeight / 2 && mousePosition.y <= buttonY + buttonHeight / 2;
}

void ChangeSceneWhenButtonPressed()
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(POSITION_BUTTON_X, positionButtonPlayY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Play;
		}
		else if (CheckCollisionMouseButton(POSITION_BUTTON_X, positionButtonRulesY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Rules;
		}
		else if (CheckCollisionMouseButton(POSITION_BUTTON_X, positionButtonCreditsY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Credits;
		}
		else if (CheckCollisionMouseButton(POSITION_BUTTON_X, positionButtonExitY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Exit;
		}
	}
}

void ChangeButtonColorOnCollision(int img, double buttonX, double buttonY, double width, double height)
{
	if (CheckCollisionMouseButton(buttonX, buttonY, height, width))
	{
		slSetForeColor(0.9, 0.9, 0.9, 1);

		slSprite(img, buttonX, buttonY, width, height);
	}
}

bool Lose(int font, int backButtonGame)
{
	LoseText(font);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSprite(backButtonGame, POSITION_BUTTON_X, positionButtonBackY, WIDTH_BUTTON, HEIGHT_BUTTON);
	ChangeButtonColorOnCollision(backButtonGame, POSITION_BUTTON_X, positionButtonBackY, WIDTH_BUTTON, HEIGHT_BUTTON);
	ChangeSceneWhenBackButtonPressed();

	return false;
}

bool Win(int font, int backButtonGame)
{
	WinText(font);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSprite(backButtonGame, POSITION_BUTTON_X, positionButtonBackY, WIDTH_BUTTON, HEIGHT_BUTTON);
	ChangeButtonColorOnCollision(backButtonGame, POSITION_BUTTON_X, positionButtonBackY, WIDTH_BUTTON, HEIGHT_BUTTON);
	ChangeSceneWhenBackButtonPressed();

	return true;
}
