#include "Ball.h"
#include "Paddle.h"
#include "Menu.h"
#include "sl.h"
#include "Collision.h"
#include "Brick.h"
#include <cmath>
#include <iostream>

using namespace std;

Ball ball;

void BallDraw(int ballImg)
{
	slSprite(ballImg, ball.x, ball.y, BALL_SIZE_IMG, BALL_SIZE_IMG);
}

void BallInit()
{
	ball.x = 400.0;
	ball.y = 120.0;
	ball.dirX = 0.0;
	ball.dirY = 1.0;
}

void BallUpdate(double time)
{
	cout << ball.dirX << endl;
	cout << ball.dirY << endl;
	cout << ball.x << endl;
	cout << ball.y << endl;
	cout << ball.angle << endl;
	ball.x += (SPEED_BALL * ball.dirX) * time;
	ball.y += (SPEED_BALL * ball.dirY) * time;
}

void CheckBallCollision()
{
	double brickLeftX = 0;
	double ballRightX = 0;

	double brickRightX = 0;
	double ballLeftX = 0;

	double diffX = 0;

	double brickLeftY = 0;
	double ballRightY = 0;

	double brickRightY = 0;
	double ballLeftY = 0;

	double diffY = 0;

	bool inCollision = false;

	//Colision Bloques con Pelota: Doble FOR para que recorra todos los bloques.
	for (int i = 0; i < BRICK_ROW_Y; i++)
	{
		for (int j = 0; j < BRICK_COLUMN_X; j++)
		{
			if (bricks[i][j].active)
			{
				inCollision = CheckRectangleCollision(bricks[i][j].x, BRICK_WIDHT, ball.x, BALL_SIZE,
					bricks[i][j].y, BRICK_HEIGHT, ball.y, BALL_SIZE);

				if (inCollision)
				{
					player.points += 100;

					//Correr la pelota del bloque hacia afuera en direccion X:
					if (ball.x < bricks[i][j].x)
					{
						brickLeftX = bricks[i][j].x - BRICK_WIDHT / 2;
						ballRightX = ball.x + BALL_SIZE / 2;

						diffX = brickLeftX - ballRightX; //Esta cuenta da un valor negativo (-)

					}
					else if (ball.x > bricks[i][j].x)
					{
						brickRightX = bricks[i][j].x + BRICK_WIDHT / 2;
						ballLeftX = ball.x - BALL_SIZE / 2;

						diffX = brickRightX - ballLeftX; //Esta cuenta da un valor positivo (+)
					}

					//Correr la pelota del bloque hacia afuera en direccion Y:
					if (ball.y < bricks[i][j].y)
					{
						brickLeftY = bricks[i][j].y - BRICK_HEIGHT / 2;
						ballRightY = ball.y + BALL_SIZE / 2;

						diffY = brickLeftY - ballRightY;
					}
					else if (ball.y > bricks[i][j].y)
					{
						brickRightY = bricks[i][j].y + BRICK_HEIGHT / 2;
						ballLeftY = ball.y - BALL_SIZE / 2;

						diffY = brickRightY - ballLeftY;
					}

					// -1 izq abajo
					// 1 derecha o arriba

					if (abs(diffX) < abs(diffY))
					{
						ball.x += diffX;
						ball.dirX *= -1;
					}
					else if (abs(diffY) < abs(diffX))
					{
						ball.y += diffY;
						ball.dirY *= -1;
					}

					bricks[i][j].active = false;

		/*			ball.dirY *= -1.0;
					ball.dirX *= -1.0;*/

					break;
				}
			}
		}

		if (inCollision)
		{
			break;
		}
	}

	inCollision = CheckRectangleCollision(player.x, BRICK_WIDHT, ball.x, BALL_SIZE,
		player.y, BRICK_HEIGHT, ball.y, BALL_SIZE);
}

void CheckBallBorders()
{
	if (ball.x < 0 + BALL_SIZE / 2)
	{
		ball.x = 0 + BALL_SIZE / 2;
		ball.dirX *= -1.0;
	}

	if (ball.x > SCREEN_WIDTH - BALL_SIZE / 2)
	{
		ball.x = SCREEN_WIDTH - BALL_SIZE / 2;
		ball.dirX *= -1.0;
	}

	if (ball.y < 0 + BALL_SIZE / 2)
	{
		BallInit();
		PaddleResetPosition();
		player.lives--;
	}

	if (ball.y > SCREEN_HEIGHT - BALL_SIZE / 2)
	{
		ball.y = SCREEN_HEIGHT - BALL_SIZE / 2;
		ball.dirY *= -1.0;
	}
}