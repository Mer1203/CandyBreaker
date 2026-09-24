#pragma once

const int PADDLE_WIDTH = 100;
const int PADDLE_HEIGHT = 20;

struct Paddle
{
	const double y = 100.0;
	double x = 400.0;
	int points = 0;
	int lives = 3;
};

Paddle player;

const int SPEED = 300;

const float DELTA_TIME = slGetDeltaTime();