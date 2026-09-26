#include "Paddle.h"
#include "Menu.h"
#include "sl.h"

Paddle player;

void PaddleDraw()
{
	slSetForeColor(1, 0, 0.5, 1);
	slRectangleFill(player.x, player.y, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void PaddleInit()
{
	player.x = 400.0;

	player.points = 0;
	player.points = 3;
}

void PaddleUpdate(double time)
{
	if (slGetKey('D') || slGetKey('d'))
	{
		player.x += SPEED * time;
	}
	else if (slGetKey('A') || slGetKey('a'))
	{
		player.x -= SPEED * time;
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