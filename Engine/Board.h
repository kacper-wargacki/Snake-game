#pragma once
#include "Graphics.h"
#include "Location.h"

class Board {
	//constexprt dziala tak samo jak const tylko w przypadku kompilowania jej wartosc musi byc od razu znana
	static constexpr int width = 32, height = 24, size = 20, x = 70, y = 50, borderWidth = 10, borderPad = 3, cellPad = 1;
	static constexpr Color borderColor = Colors::Cyan;
	Graphics& gfx;

public:
	Board(Graphics& gfx_);
	void drawCell(const Location& loc, Color col);
	int getBoardWidth() const;
	int getBoardHeight() const;
	bool isInside(const Location& loc) const;
	void drawBorder();
};