#pragma once

const int BALL_VERTICES = 100;
const int BALL_SIZE = 8;
const int BALL_SIZE_IMG = 20;

const int SPEED_BALL = 300;

struct Ball
{
	double x = 400.0;
	double y = 120.0;
	double dirX = 0.0;
	double dirY = 0.0;
	double angle = 0.0;
};

extern Ball ball;

void BallUpdate(double time);
void BallInit();
void BallDraw(int ballImg);
void CheckBallBorders();
void CheckBallCollision();