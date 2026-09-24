#pragma once

const int BALL_VERTICES = 100;
const int BALL_SIZE = 8;

struct Ball
{
	double x = 400.0;
	double y = 120.0;
};

extern Ball ball;