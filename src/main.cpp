#include <iostream>
#include "Menu.h"
#include "Paddle.h"
#include "Ball.h"

using namespace std;

int main()
{
	double deltaTime = slGetDeltaTime();

	slWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple SIGIL Example", false);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		slSetBackColor(1.0, 1.0, 1.0);

		cout << mousePosition.x << endl;


		Menu();

		PaddleDraw();
		PaddleUpdate(deltaTime);
		CheckPaddleBorders();

		slRender();
	}

	slClose();

	return 0;
}

