#include "sl.h"
#include "Menu.h"

Screen currentScreen = Screen::Menu;
Vector2 mousePosition;

void Menu()
{

	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		
		//DIBUJADO BOTONES
		slSetForeColor(1, 0, 0.5, 1);
		slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonPlayY, WIDTH_BUTTON, HEIGHT_BUTTON);
		slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonRulesY, WIDTH_BUTTON, HEIGHT_BUTTON);
		slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonCreditsY, WIDTH_BUTTON, HEIGHT_BUTTON);
		slRectangleFill(POSITION_MENU_BUTTON_X, positionButtonExitY, WIDTH_BUTTON, HEIGHT_BUTTON);

		//COLISIONES BOTONES
		ChangeButtonColorOnCollision(positionButtonPlayY);
		ChangeButtonColorOnCollision(positionButtonRulesY);
		ChangeButtonColorOnCollision(positionButtonCreditsY);
		ChangeButtonColorOnCollision(positionButtonExitY);


		break;
	case Screen::Play:
		break;
	case Screen::Rules:
		break;
	case Screen::Credits:
		break;
	case Screen::Exit:
		break;
	default:
		break;
	}
}

bool CheckCollisionMouseButton(int buttonX, int buttonY, int buttonHeight, int buttonWidth)
{
	mousePosition.x = slGetMouseX();
	mousePosition.y = slGetMouseY();

	return buttonX - 100 <= mousePosition.x && buttonX - 100 + WIDTH_BUTTON  >= mousePosition.x
		&& mousePosition.y >= buttonY - HEIGHT_BUTTON / 2 && mousePosition.y <= buttonY - HEIGHT_BUTTON / 2 + HEIGHT_BUTTON;
}

void ChangeButtonColorOnCollision(int buttonY)
{
	if (CheckCollisionMouseButton(POSITION_MENU_BUTTON_X, buttonY, HEIGHT_BUTTON, WIDTH_BUTTON))
	{
		slSetForeColor(1.0, 0.5, 0.0, 1.0);
		slRectangleFill(POSITION_MENU_BUTTON_X, buttonY, WIDTH_BUTTON, HEIGHT_BUTTON);
	}
}
