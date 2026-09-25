#include "Button.h"
#include "Menu.h"
#include "sl.h"

Vector2 mousePosition;

void ButtonMenuDraw()
{
	slSetForeColor(1, 0, 0.5, 1);
	slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonPlayY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonRulesY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonCreditsY, WIDTH_BUTTON, HEIGHT_BUTTON);
	slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonExitY, WIDTH_BUTTON, HEIGHT_BUTTON);
}

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth)
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	return buttonX - 100 <= mousePosition.x && buttonX - 100 + WIDTH_BUTTON >= mousePosition.x
		&& mousePosition.y >= buttonY - HEIGHT_BUTTON / 2 && mousePosition.y <= buttonY - HEIGHT_BUTTON / 2 + HEIGHT_BUTTON;
}

void ChangeSceneWhenButtonPressed()
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionMouseButton(POSITION_MENU_BUTTON_X, positionButtonPlayY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Play;
		}
		else if (CheckCollisionMouseButton(POSITION_MENU_BUTTON_X, positionButtonRulesY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Rules;
		}
		else if (CheckCollisionMouseButton(POSITION_MENU_BUTTON_X, positionButtonCreditsY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Credits;
		}
		else if (CheckCollisionMouseButton(POSITION_MENU_BUTTON_X, positionButtonExitY, HEIGHT_BUTTON, WIDTH_BUTTON))
		{
			currentScreen = Screen::Exit;
		}
	}
}

void ChangeButtonColorOnCollision(int buttonY)
{
	if (CheckCollisionMouseButton(POSITION_MENU_BUTTON_X, buttonY, HEIGHT_BUTTON, WIDTH_BUTTON))
	{
		slSetForeColor(1.0, 0.5, 0.0, 1.0);
		slRectangleFill(POSITION_MENU_BUTTON_X, buttonY, WIDTH_BUTTON, HEIGHT_BUTTON);
	}
}
