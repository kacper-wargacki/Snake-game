#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <random>

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
private:
	MainWindow& wnd;
	Graphics gfx;
	Board b;
	Snake snake;
	//ponownie uzywamy {} aby zainicjowac klase location ktora ma tylko dwa parametry
	Location loc_move{ 1,0 };
	std::mt19937 rnd;
	Goal g;
	static constexpr int snakeSpeed = 10;
	int moveCounter = 0;
	bool gameOver = false;
	bool gameStart = false;
};