#include "Snake.h"
#include <assert.h>
Snake::Snake(const Location& loc)
{
	constexpr int nBodyColors = 4;
	constexpr Color bodyColors[nBodyColors] = {
		{51, 102, 0},
		{77, 153, 0},
		{102, 204, 0},
		{77, 153, 0}
	};

	for (int i = 0; i < nMax; i++) {
		parts[i].Body(bodyColors[i % nBodyColors]);
	}

	parts[0].Head(loc);
}
// kazdy fragment ktory nie jest glowa porusza sie na miejsce swojego nastepnego fragmentu zaczynajac od ogona
void Snake::Move(const Location& loc_number)
{
	for (int i = nParts - 1; i > 0; i--) {
		parts[i].Follow(parts[i - 1]);
	}
	parts[0].Move(loc_number);
}

void Snake::Grow()
{
	if (nParts < nMax) {
		nParts++;
	}
}

void Snake::Draw(Board& b) const
{
	for (int i = 0; i < nParts; i++) {
		parts[i].Draw(b);
	}
}

Location Snake::getNextLocation(const Location& loc_number) const
{
	Location l(parts[0].getLocation());
	l.Add(loc_number);
	return l;
}

bool Snake::isColidedWithoutLastPart(const Location& l) const
{
	for (int i = 0; i < nParts - 1; i++) {
		if (parts[i].getLocation() == l) {
			return true;
		}
	}
	return false;
}

bool Snake::isColided(const Location& l) const
{
	for (int i = 0; i < nParts; i++) {
		if (parts[i].getLocation() == l) {
			return true;
		}
	}
	return false;
}

void Snake::Part::Head(const Location& loc_)
{
	loc = loc_;
	//mimo ze pobieramy headColor z prywatnej czesci klasy snake, klasa part sama w sobie jest w czesci prywatnej snake
	c = Snake::headColor;
}

void Snake::Part::Body(Color c_)
{
	c = c_;
}

void Snake::Part::Follow(const Part& n)
{
	loc = n.loc;
}

void Snake::Part::Move(const Location& loc_number)
{
	//assertujemy aby upewnic sie ze koordynaty ktore podajemy jak ma sie snake poruszyc sa poprawne, gdyz bedziemy tylko poruszac sie
	// tylko o 1 miejsce w osi OX lub OY
	assert(abs(loc_number.x) + abs(loc_number.y) == 1);
	loc.Add(loc_number);
}

void Snake::Part::Draw(Board& b) const
{
	b.drawCell(loc, c);
}

const Location& Snake::Part::getLocation() const
{
	return loc;
}