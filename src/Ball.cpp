#include "Ball.h"
#include "sl.h"

Ball ball;

void BallDraw()
{
	slCircleFill(ball.x, ball.y, BALL_SIZE, BALL_VERTICES);
}