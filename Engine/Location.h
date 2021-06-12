#pragma once

class Location {
public:
	void Add(const Location& l) {
		x += l.x;
		y += l.y;
	}
	//przeładowanie operatora == aby mógł porównywać dwie klasy Location ze sobą
	bool operator ==(const Location& location) const
	{
		return x == location.x && y == location.y;
	}
	int x, y;
};