#include <iostream>
#include "Menu.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"

using namespace std;

int main()
{
	double deltaTime = 0.0;

	slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Candy Breker", false);

	BrickInit();

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		deltaTime = slGetDeltaTime();
		slSetBackColor(1.0, 1.0, 1.0);
		cout << ball.y << endl;
		MenuDraw();
		MenuUpdate(deltaTime);

		slRender();
	}

	slClose();

	return 0;
}

