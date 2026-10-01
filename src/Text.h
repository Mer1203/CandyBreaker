#pragma once
#include <string>

const int LIFE_TEXT_X = 82;
const int LIFE_TEXT_Y = 10;

const int TITTLE_TEXT_X = 350;
const int TITTLE_TEXT_Y = 550;

const int MER_TEXT_X = 240;
const int MER_TEXT_Y = 520;

const int GAMEPLAY_FONT_SIZE = 30;

void GameplayText(std::string text, std::string textTwo, int font);
void RulesText(int font);
void CreditsText(int font);