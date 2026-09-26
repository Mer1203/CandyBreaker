#include "Button.h"
#include "Menu.h"
#include "sl.h"

Vector2 mousePosition;

void BackButtonDraw()
{
	slSetForeColor(1, 0, 0.5, 1);
	slRectangleFill(BACK_BUTTON_X, BACK_BUTTON_Y, WIDTH_BACK_BUTTON, HEIGHT_BACK_BUTTON);
}

void ChangeBackButtonColorOnCollision()
{
	if (CheckCollisionMouseBackButton(BACK_BUTTON_X, BACK_BUTTON_Y))
	{
		slSetForeColor(1.0, 0.5, 0.0, 1.0);
		slRectangleFill(BACK_BUTTON_X, BACK_BUTTON_Y, WIDTH_BACK_BUTTON, HEIGHT_BACK_BUTTON);
	}
}

bool CheckCollisionMouseBackButton(int buttonX, int buttonY)
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	return buttonX - WIDTH_BACK_BUTTON / 2 <= mousePosition.x && buttonX + WIDTH_BACK_BUTTON / 2 >= mousePosition.x
		&& mousePosition.y >= buttonY - HEIGHT_BACK_BUTTON / 2 && mousePosition.y <= buttonY + HEIGHT_BACK_BUTTON / 2;
}

void ChangeSceneWhenBackButtonPressed()
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(BACK_BUTTON_X, BACK_BUTTON_Y, HEIGHT_BACK_BUTTON, WIDTH_BACK_BUTTON))
		{
			currentScreen = Screen::Menu;
		}
	}
}

void ButtonMenuDraw()
{
	slSetForeColor(1, 0, 0.5, 1);
	slRectangleFill(POSITION_BUTTON_X, positionButtonPlayY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slRectangleFill(POSITION_BUTTON_X, positionButtonRulesY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slRectangleFill(POSITION_BUTTON_X, positionButtonCreditsY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slRectangleFill(POSITION_BUTTON_X, positionButtonExitY, WIDTH_BUTTON, HEIGHT_BUTTON);
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

void ChangeButtonColorOnCollision(int buttonY)
{
	if (CheckCollisionMouseButton(POSITION_BUTTON_X, buttonY, HEIGHT_BUTTON, WIDTH_BUTTON))
	{
		slSetForeColor(1.0, 0.5, 0.0, 1.0);
		slRectangleFill(POSITION_BUTTON_X, buttonY, WIDTH_BUTTON, HEIGHT_BUTTON);
	}
}
