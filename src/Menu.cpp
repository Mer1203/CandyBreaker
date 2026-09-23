#include "sl.h"
#include "Menu.h"

Screen currentScreen = Screen::Menu;

void Menu()
{

	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		
		slSetForeColor(1, 0, 0.5, 1);
		slRectangleFill(positionButtonX, positionButtonPlayY, widthButton, heightButton);
		slRectangleFill(positionButtonX, positionButtonRulesY, widthButton, heightButton);
		slRectangleFill(positionButtonX, positionButtonCreditsY, widthButton, heightButton);
		slRectangleFill(positionButtonX, positionButtonExitY, widthButton, heightButton);
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