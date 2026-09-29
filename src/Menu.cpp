#include "sl.h"
#include "Menu.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Button.h"
#include "Collision.h"
#include <iostream>

using namespace std;

Screen currentScreen = Screen::Menu;


void MenuUpdate(double time, bool& programIsRunning)
{
	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		ChangeSceneWhenButtonPressed();
		PaddleInit();
		BallInit();
		BrickInit();

		break;
	case Screen::Play:
		//Colision Paleta con Pelota

		//CheckRectangleCollision(player.x, PADDLE_WIDTH, ball.x, BALL_SIZE,
		//                        player.y, PADDLE_HEIGHT, ball.y, BALL_SIZE);

		BallUpdate(time);
		PaddleUpdate(time);
		CheckBallCollision();

		CheckPaddleBorders();
		ChangeSceneWhenBackButtonPressed();
		break;
	case Screen::Rules:
		ChangeSceneWhenBackButtonPressed();
		break;
	case Screen::Credits:
		ChangeSceneWhenBackButtonPressed();
		break;
	case Screen::Exit:
		programIsRunning = false;
		break;
	default:
		break;
	}
}

void MenuDraw(int backgroundOne, int backgroundTwo, int tittle, int playButton, int rulesButton, int creditsButton, int exitButton, int paddleImg, int ballImg, int brickImg)
{
	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		//FONDO
		slSprite(backgroundTwo, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);
		//TITULO
		slSprite(tittle, TITTLE_X, TITTLE_Y, TITTLE_WIDTH, TITTLE_HEIGHT);
		//DIBUJADO BOTONES
		ButtonMenuDraw(playButton, rulesButton, creditsButton, exitButton);
		//COLISIONES BOTONES
		ChangeButtonColorOnCollision(positionButtonPlayY, playButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(positionButtonRulesY, rulesButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(positionButtonCreditsY, creditsButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		ChangeButtonColorOnCollision(positionButtonExitY, exitButton);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		break;
	case Screen::Play:
		//Fondo:
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slSprite(backgroundOne, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);

		PaddleDraw(paddleImg);
		BallDraw(ballImg);
		BrickDraw(brickImg);
		BackButtonDraw();
		ChangeBackButtonColorOnCollision();
		break;
	case Screen::Rules:
		BackButtonDraw();
		ChangeBackButtonColorOnCollision();
		break;
	case Screen::Credits:
		BackButtonDraw();
		ChangeBackButtonColorOnCollision();
		break;
	case Screen::Exit:
		break;
	default:
		break;
	}
}

