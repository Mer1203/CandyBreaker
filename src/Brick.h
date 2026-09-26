#pragma once

const int BRICK_ROW_Y = 7;
const int BRICK_COLUMN_X = 8;

const int BRICK_WIDHT = 80;
const int BRICK_HEIGHT = 30;

struct Brick
{
	double x = 90.0;
	double y = 520.0;
};

extern Brick bricks[BRICK_ROW_Y][BRICK_COLUMN_X];

void BrickDraw();
void BrickInit();
//void BrickUpdate();