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
		break;
	default:
		break;
	}
}

