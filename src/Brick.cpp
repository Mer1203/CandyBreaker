#include "Brick.h"
#include "Ball.h"
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
			bricks[i][j].active = true;

			auxX += BRICK_WIDHT + 2;
		}

		auxY -= (BRICK_HEIGHT + 2);
	}
}

void BrickDraw(int brickThreeImg, int brickImg, int brickTwoImg)
{
	for (int i = 0; i < BRICK_ROW_Y; i++)
	{
		for (int j = 0; j < BRICK_COLUMN_X; j++)
		{
			if (bricks[i][j].active)
			{
				if (i % 2 == 0 && j % 2 == 0)
				{
					slSetForeColor(1.0, 0.0, 0.5, 1);
					slSprite(brickImg, bricks[i][j].x, bricks[i][j].y, BRICK_WIDHT, BRICK_HEIGHT);
				}
				else if (i % 3 == 0)
				{
					slSetForeColor(0.3, 0.9, 1.0, 1);
					slSprite(brickImg, bricks[i][j].x, bricks[i][j].y, BRICK_WIDHT, BRICK_HEIGHT);
				}
				else
				{
					slSetForeColor(0.7, 0.0, 1.0, 1);
					slSprite(brickImg, bricks[i][j].x, bricks[i][j].y, BRICK_WIDHT, BRICK_HEIGHT);
				}
			}
		}
	}
}

//void BrickUpdate()
//{
//
//
//}

