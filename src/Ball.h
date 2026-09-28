#pragma once

const int BALL_VERTICES = 100;
const int BALL_SIZE = 8;
const int BALL_SIZE_IMG = 20;

struct Ball
{
	double x = 400.0;
	double y = 120.0;
	double dirX = 0.0;
	double dirY = 0.0;
};

extern Ball ball;

void BallUpdate(int time);
void BallInit();
void BallDraw(int ballImg);