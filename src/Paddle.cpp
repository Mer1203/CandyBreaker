#include "Paddle.h"
#include "sl.h"

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

void PaddleUpdate()
{
	if (slGetKey('D') || slGetKey('d'))
	{
		player.x += SPEED * DELTA_TIME;
	}
	else if (slGetKey('A') || slGetKey('a'))
	{
		player.x -= SPEED * DELTA_TIME;
	}
}