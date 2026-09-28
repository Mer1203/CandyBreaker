#include "Ball.h"
#include "Paddle.h"
#include "Menu.h"
#include "sl.h"
#include <cmath>

Ball ball;

void BallDraw(int ballImg)
{
	slSprite(ballImg, ball.x, ball.y, BALL_SIZE_IMG, BALL_SIZE_IMG);
}

void BallInit()
{
	ball.x = 400.0;
	ball.y = 120.0;
}

void BallUpdate(int time)
{
	if (player.isAlive)
	{
		ball.y ++;
	}

	if (player.isAlive)
	{
		ball.x++;

		if (ball.x >= SCREEN_WIDTH - BALL_SIZE)
		{
			ball.x = SCREEN_WIDTH - BALL_SIZE;
		}
		/*
		else if (ball.x = SCREEN_WIDTH)
		{
			ball.x--;
		}*/
	}

	if (ball.y >= SCREEN_HEIGHT - BALL_SIZE)
	{
		ball.y = SCREEN_HEIGHT - BALL_SIZE;
	}

}

//sin();
//cos();