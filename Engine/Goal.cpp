#include "Goal.h"

Goal::Goal(std::mt19937& rnd, const Board& b, const Snake& snake)
{
	Spawn(rnd, b, snake);
}

void Goal::Spawn(std::mt19937& rnd, const Board& b, const Snake& snake)
{
	//std::uid dystrybutuje inty z podanego mu zakresu
	std::uniform_int_distribution<int> xDis(0, b.getBoardWidth() - 1);
	std::uniform_int_distribution<int> yDis(0, b.getBoardHeight() - 1);
	Location newL;
	do {
		newL.x = xDis(rnd);
		newL.y = yDis(rnd);
	} while (snake.isColided(newL));

	loc = newL;
}

void Goal::Draw(Board& b) const
{
	b.drawCell(loc, c);
}

const Location& Goal::getLocation() const
{
	return loc;
}