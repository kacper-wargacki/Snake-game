#include "Board.h"
#include <assert.h>

int Board::getBoardWidth() const
{
	return width;
}

int Board::getBoardHeight() const
{
	return height;
}
//funkcja sprawdza czy snake jest w obszarze okna
bool Board::isInside(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width&& loc.y >= 0 && loc.y < height;
}

void Board::drawBorder()
{
	const int top = y;
	const int left = x;
	//wyznaczamy koordynaty rogów dla obramówki - pozycja x + (szerokosc bordera + padding bordera)*ilość pojawienia sie go + wysokosc okna * skala w jakiej operujemy
	const int bottom = top + (borderWidth + borderPad) * 2 + height * size;
	const int right = left + (borderWidth + borderPad) * 2 + width * size;
	//top
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	//left
	gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	//right
	gfx.DrawRect(right - borderWidth, top + borderWidth, right, bottom - borderWidth, borderColor);
	//bottom
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);
}

Board::Board(Graphics& gfx_) : gfx(gfx_)
{
}

void Board::drawCell(const Location& loc, Color col)
{
	//assert sprawdza dany warunek oraz nie przepuszcza programu dalej jesli warunek nie zostanie spelniony
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int offsetX = x + borderWidth + borderPad, offsetY = y + borderWidth + borderPad;

	gfx.DrawRectDim(loc.x * size + offsetX + cellPad, loc.y * size + offsetY + cellPad, size - cellPad * 2, size - cellPad * 2, col);
}