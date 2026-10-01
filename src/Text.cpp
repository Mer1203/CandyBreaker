#include "Text.h"
#include "sl.h"
#include "Paddle.h"

void GameplayText(std::string textOne, std::string textTwo, int font)
{
	slSetForeColor(1.0, 1.0, 1.0, 1);
	textOne = "Lives: " + std::to_string(player.lives);
	slSetFont(font, GAMEPLAY_FONT_SIZE);
	slText(LIFE_TEXT_X, LIFE_TEXT_Y, (textOne).c_str());

	textTwo = "Points: " + std::to_string(player.points);
	slText(LIFE_TEXT_X + (LIFE_TEXT_X * 6), LIFE_TEXT_Y, (textTwo).c_str());
}

void RulesText(int font)
{

}

void CreditsText(int font)
{
	slSetFont(font, GAMEPLAY_FONT_SIZE);
	slSetForeColor(0.7, 0.0, 0.4, 1);
	slText(TITTLE_TEXT_X, TITTLE_TEXT_Y, "MADE BY");
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(MER_TEXT_X, MER_TEXT_Y, "Mercedes Ramirez Diaz");
	slSetForeColor(0.7, 0.0, 0.4, 1);
	slText(TITTLE_TEXT_X, 490, "ART BY");
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(260, 460, "Maria Sol Oliverio");
	slText(MER_TEXT_X, 430, "Mercedes Ramirez Diaz"); 
	slSetForeColor(0.7, 0.0, 0.4, 1);
	slText(TITTLE_TEXT_X, 400, "ASSETS");
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(110, 370, "Font: https://www.dafont.com/es/motley-forces.font");
	slText(MER_TEXT_X, 430, "Mercedes Ramirez Diaz");


}