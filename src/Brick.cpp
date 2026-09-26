#include "Brick.h"
#include "sl.h"

Brick bricks[BRICK_ROW_Y][BRICK_COLUMN_X] = { 0 };

void BrickInit()
{
	double auxY = 520.0;
	double auxX = 0.0;

	for (int i = 0; i < BRICK_ROW_Y; i++)
	{
		auxX = 110;

		for (int j = 0; j < BRICK_COLUMN_X; j++) 
		{
			bricks[i][j].x = auxX;
			bricks[i][j].y = auxY;

			auxX += BRICK_WIDHT + 2;
		}

		auxY -= (BRICK_HEIGHT + 2);
	}
}

void BrickDraw()
{
	for (int i = 0; i < BRICK_ROW_Y; i++)
	{
		for (int j = 0; j < BRICK_COLUMN_X; j++)
		{
			slRectangleFill(bricks[i][j].x, bricks[i][j].y, BRICK_WIDHT, BRICK_HEIGHT);
		}
	}
}

//void BrickUpdate()
//{
//}