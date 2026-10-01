#pragma once

const int PADDLE_WIDTH = 100;
const int PADDLE_HEIGHT = 20;

struct Paddle
{
	const double y = 100.0;
	double x = 400.0;
	double dirX = 0.0;
	double dirY = 0.0;
	int points = 0;
	int lives = 3;
	bool isAlive = true;
};

extern Paddle player;

const int SPEED_PADDLE = 300;

void PaddleResetPosition();
void PaddleInit();
void PaddleUpdate(double time);
void PaddleDraw(int paddleImg);
void CheckPaddleBorders();
void CheckPaddleCollision();