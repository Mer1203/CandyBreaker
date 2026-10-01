#include "Text.h"
#include "sl.h"
#include "Paddle.h"

void GameplayText(std::string textOne, std::string textTwo, int font)
{
	slSetForeColor(1.0, 1.0, 1.0, 1);
	textOne = "Lives: " + std::to_string(player.lives);
	slSetFont(font, FONT_SIZE);
	slText(LIFE_TEXT_X, LIFE_TEXT_Y, (textOne).c_str());

	textTwo = "Points: " + std::to_string(player.points);
	slText(LIFE_TEXT_X + (LIFE_TEXT_X * 6), LIFE_TEXT_Y, (textTwo).c_str());
}

void LoseText(int font)
{
	slSetFont(font, FONT_SIZE + FONT_SIZE);
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(CONDITION_TEXT_X, CONDITION_TEXT_Y, "YOU LOSE :(");
}

void WinText(int font)
{
	slSetFont(font, FONT_SIZE + FONT_SIZE);
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(280, CONDITION_TEXT_Y, "YOU WIN!");
}

void RulesText(int font)
{
	slSetFont(font, FONT_SIZE);
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(20, 495, "With the Jaw-Breaker, you must break the blocks to");
	slText(20, 460, "reach the maximum score to win. If the Jaw-Breaker");
	slText(20, 425, "reachs the bottom, you lose a life. If you don´t have");
	slText(20, 390, "lives left, you lose!");
	slText(20, 350, "To avoid losing lives, you must control the ball using\n the candy bar.");
	slText(20, 270, "Keep in mind that the Jaw-Breaker shoots out as soon\n as the game starts and when it reappears.");

	slSetForeColor(0.7, 0.0, 1.0, 1);
	slText(20, 160, "KEYS:");

	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(20, 130, " -");
	slSetForeColor(0.3, 0.9, 1.0, 1); 
	slText(28, 130, "  A " );
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(58, 130, " -> Move candy to the left.");

	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(20, 100, " -");
	slSetForeColor(0.3, 0.9, 1.0, 1); 
	slText(28, 100, "  D " );
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(58, 100, " -> Move candy to the right.");



}

void CreditsText(int font)
{
	slSetFont(font, FONT_SIZE);
	slSetForeColor(1.0, 0.0, 0.5, 1);
	slText(260, TITTLE_TEXT_Y, "GAME DEVELPMENT BY");
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(MER_TEXT_X, MER_TEXT_Y, "Mercedes Ramirez Diaz");
	slSetForeColor(1.0, 0.0, 0.5, 1);

	slText(TITTLE_TEXT_X, 450, "ART BY");
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(270, 420, "Maria Sol Oliverio");
	slText(MER_TEXT_X, 390, "Mercedes Ramirez Diaz");

	slSetForeColor(0.7, 0.0, 1.0, 1);
	slText(290, 350, "SPECIAL THANKS!");
	slSetForeColor(1.0, 1.0, 1.0, 1); 
	slText(295, 320, "Nahuel Suarez"); 
	slText(305, 290, "Sofia Franze"); 
	slText(300, 260, "Lucio Piccioni");
	slText(295, 230, "Sergio Baretto");

	slSetForeColor(1.0, 0.0, 0.5, 1);
	slText(TITTLE_TEXT_X, 190, "ASSETS"); 
	slSetForeColor(1.0, 1.0, 1.0, 1);

	slSetFont(font, 20);
	slSetForeColor(0.3, 0.9, 1.0, 1);
	slText(300, 160, "Motley Forces - Font:");
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(170, 140, " https://www.dafont.com/es/motley-forces.font");

	slSetForeColor(0.3, 0.9, 1.0, 1);
	slText(160, 120, "Backdrops Beautiful - Candyland 9 - Background One:"); 
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(80, 100, "https://backdropsbeautiful.com/fantasy-backdrops/candyland--9.html"); 

	slSetForeColor(0.3, 0.9, 1.0, 1);
	slText(180, 80, "Gabriela Omann - Candy World - Background Two:");
	slSetForeColor(1.0, 1.0, 1.0, 1);
	slText(170, 60, "https://ar.pinterest.com/pin/803470389795722270/");
}