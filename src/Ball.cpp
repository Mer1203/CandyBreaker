#include "Ball.h"
#include "sl.h"

void BallDraw()
{
	slCircleFill(ball.x, ball.y, BALL_SIZE, BALL_VERTICES);
}