#pragma once

#include "Board.h"
#include"Colors.h"

class Snake {
private:
	class Part {
		Location loc;
		Color c;
	public:
		void Head(const Location& loc_);
		void Body(Color c);
		void Follow(const Part& n);
		void Move(const Location& loc_number);
		void Draw(Board& b) const;
		const Location& getLocation() const;
	};
private:
	static constexpr Color headColor = Colors::Gray;
	static const int nMax = 100;
	Part parts[nMax];
	int nParts = 1;
public:
	Snake(const Location& loc);
	void Move(const Location& loc_number);
	void Grow();
	void Draw(Board& b) const;
	Location getNextLocation(const Location& loc_number) const;
	bool isColidedWithoutLastPart(const Location& l) const;
	bool isColided(const Location& l) const;
};