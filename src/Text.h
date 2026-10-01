#pragma once
#include <string>

const int LIFE_TEXT_X = 82;
const int LIFE_TEXT_Y = 10;

const int TITTLE_TEXT_X = 350;
const int TITTLE_TEXT_Y = 530;

const int MER_TEXT_X = 240;
const int MER_TEXT_Y = 500;

const int FONT_SIZE = 30;

const double CONDITION_TEXT_X = 250;
const double CONDITION_TEXT_Y = 300;

void LoseText(int font);
void WinText(int font);
void GameplayText(std::string text, std::string textTwo, int font);
void RulesText(int font);
void CreditsText(int font);
