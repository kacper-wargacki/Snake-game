#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class Goal {
	static constexpr Color c = Colors::Red;
	Location loc;
public:
	Goal(std::mt19937& rnd, const Board& b, const Snake& snake);
	void Spawn(std::mt19937& rnd, const Board& b, const Snake& snake);
	void Draw(Board& b) const;
	const Location& getLocation() const;
};