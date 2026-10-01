#include "Paddle.h"
#include "Menu.h"
#include "sl.h"
#include "Collision.h"
#include "Ball.h"
#include <cmath>
#include <iostream>

using namespace std;

Paddle player;

void CheckPaddleCollision()
{
	const double MIN_ANGLE = 40;
	const double MAX_ANGLE = 130;

	double ballImpactonPaddle = 0;
	double normalize = 0;

	double paddleLeftX = 0;
	double ballRightX = 0;

	double paddleRightX = 0;
	double ballLeftX = 0;

	double diffX = 0;

	double paddleLeftY = 0;
	double ballRightY = 0;

	double paddleRightY = 0;
	double ballLeftY = 0;

	double diffY = 0;

	bool inCollision = false;


	inCollision = CheckRectangleCollision(player.x, PADDLE_WIDTH, ball.x, BALL_SIZE,
		player.y, PADDLE_HEIGHT, ball.y, BALL_SIZE);

	if (inCollision)
	{
		//ANGULOS DE LA PELOTA, SENO Y COSENO:
		//Saco donde impacta la pelota en la paleta
		ballImpactonPaddle = ball.x - (player.x - PADDLE_WIDTH / 2);
		//Normalizo el numero entre 0 y 1
		normalize = ballImpactonPaddle / PADDLE_WIDTH;

		if (normalize < 0)
		{
			normalize = 0;
		}
		if (normalize > 1)
		{
			normalize = 1;
		}

		//Saco el angulo en donde cayo la pelota con mi numero normalizado
		ball.angle = MIN_ANGLE + ((MAX_ANGLE - MIN_ANGLE) * (1 - normalize));

		cout << ball.angle << endl;

		//Le agrego el angulo a las direcciones de la pelota con seno y coseno

		ball.angle *= 3.14 / 180;

		ball.dirY = abs(sin(ball.angle));
		ball.dirX = cos(ball.angle);

		//Correr la pelota de la paleta hacia afuera en direccion X:
		if (ball.x < player.x)
		{
			paddleLeftX = player.x - PADDLE_WIDTH / 2;
			ballRightX = ball.x + BALL_SIZE / 2;

			diffX = paddleLeftX - ballRightX; //Esta cuenta da un valor negativo (Izquierda (-))
		}
		else if (ball.x > player.x)
		{
			paddleRightX = player.x + PADDLE_WIDTH / 2;
			ballLeftX = ball.x - BALL_SIZE / 2;

			diffX = paddleRightX - ballLeftX; //Esta cuenta da un valor positivo (Derecha (+))
		}

		//Correr la pelota de la paleta hacia afuera en direccion Y:
		if (ball.y > player.y)
		{
			paddleRightY = player.y + PADDLE_HEIGHT / 2;
			ballLeftY = ball.y - BALL_SIZE / 2;

			diffY = paddleRightY - ballLeftY; //Esta cuenta da un valor positivo (Arriba (+))
		}

		if (abs(diffX) < abs(diffY))
		{
			ball.x += diffX;
		}
		else if (abs(diffY) < abs(diffX))
		{
			ball.y += diffY;
		}
	}
}

void PaddleDraw(int paddleImg)
{
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slSprite(paddleImg, player.x, player.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void PaddleResetPosition()
{
	player.x = 400.0;
}

void PaddleInit()
{
	player.x = 400.0;
	player.isAlive = true;
	player.won = false;
	player.points = 0;
	player.lives = 3;
}

void PlayerLose()
{
	if (player.lives == 0)
	{
		player.isAlive = false;
	}
}

void PlayerWin()
{
	if (player.points == 6400)
	{
		player.won = true;
	}
}

void PaddleUpdate(double time)
{
	if (slGetKey('D') || slGetKey('d'))
	{
		player.x += SPEED_PADDLE * time;
	}
	else if (slGetKey('A') || slGetKey('a'))
	{
		player.x -= SPEED_PADDLE * time;
	}
}

void CheckPaddleBorders()
{
	if (player.x < 0 + PADDLE_WIDTH / 2)
	{
		player.x = 0 + PADDLE_WIDTH / 2;
	}

	if (player.x > SCREEN_WIDTH - PADDLE_WIDTH / 2)
	{
		player.x = SCREEN_WIDTH - PADDLE_WIDTH / 2;
	}
}
