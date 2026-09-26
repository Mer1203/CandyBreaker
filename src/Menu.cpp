#include "sl.h"
#include "Menu.h"
#include "Ball.h"
#include "Paddle.h"
#include "Button.h"
#include "Brick.h"

Screen currentScreen = Screen::Menu;

void MenuDraw()
{
	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		
		//DIBUJADO BOTONES
		ButtonMenuDraw();

		//COLISIONES BOTONES
		ChangeButtonColorOnCollision(positionButtonPlayY);
		ChangeButtonColorOnCollision(positionButtonRulesY);
		ChangeButtonColorOnCollision(positionButtonCreditsY);
		ChangeButtonColorOnCollision(positionButtonExitY);

		break;
	case Screen::Play:
		PaddleDraw();
		BallDraw();
		BrickDraw();
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

void MenuUpdate(double time)
{
	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		ChangeSceneWhenButtonPressed();
		PaddleInit();
		break;
	case Screen::Play:
		PaddleUpdate(time);
		BallUpdate(time);
		CheckPaddleBorders();

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

