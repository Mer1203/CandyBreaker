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

void MenuDraw(int backgroundOne, int backgroundTwo, int tittle, int playButton, int rulesButton, int creditsButton, int exitButton, int paddleImg, int ballImg, int brickImg)
{
	switch (currentScreen)
	{
	case Screen::None:
		break;
	case Screen::Menu:
		//DIBUJADO BOTONES
		ButtonMenuDraw(playButton, rulesButton, creditsButton, exitButton);

		//FONDO
		slSprite(backgroundTwo, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);

		//TITULO
		slSprite(tittle, TITTLE_X, TITTLE_Y, TITTLE_WIDTH, TITTLE_HEIGHT);
		//COLISIONES BOTONES
		ChangeButtonColorOnCollision(positionButtonPlayY, playButton);
		ChangeButtonColorOnCollision(positionButtonRulesY, rulesButton);
		ChangeButtonColorOnCollision(positionButtonCreditsY, creditsButton);
		ChangeButtonColorOnCollision(positionButtonExitY, exitButton);
		break;
	case Screen::Play:
		//Fondo:
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

		CheckRectangleCollision(player.x, PADDLE_WIDTH, ball.x, BALL_SIZE,
			                    player.y, PADDLE_HEIGHT, ball.y, BALL_SIZE);

		//Colision Bloques con Pelota: Doble FOR para que recorra todos los bloques.

		for (int i = 0; i < BRICK_ROW_Y; i++)
		{
			for (int j = 0; j < BRICK_COLUMN_X; j++)
			{
				if (CheckRectangleCollision(bricks[i][j].x, BRICK_WIDHT, ball.x, BALL_SIZE,
					                        bricks[i][j].y, BRICK_HEIGHT, ball.y, BALL_SIZE))
				{
					bricks[i][j].active = false;
					cout << "COLISION! (PELOTA/BLOQUE)" << endl;
				}
			}
		}

		PaddleUpdate(time);
		BallUpdate(time);
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

