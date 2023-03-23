#ifndef COORDONNEES_H_INCLUDED
#define COORDONNEES_H_INCLUDED

#include <set>
#include "transformation.h"

struct Coordinate
{
	int x;
	int y;

	Coordinate operator*(Transformation transformation) const;
	Coordinate& operator*=(Transformation transformation);
	Coordinate operator+(const Coordinate& translation) const;
	Coordinate& operator+=(const Coordinate& translation);
	std::set<Coordinate> getCoin() const; // Renvoie l'ensemble des 4 carrés situés dans les 4 coins différents
	std::set<Coordinate> getCote() const;
};

bool operator<(const Coordinate& c1, const Coordinate& c2);
bool operator>(const Coordinate& c1, const Coordinate& c2);
bool operator<=(const Coordinate& c1, const Coordinate& c2);
bool operator>=(const Coordinate& c1, const Coordinate& c2);
bool operator==(const Coordinate& c1, const Coordinate& c2);
bool operator!=(const Coordinate& c1, const Coordinate& c2);
#endif // COORDONNEES_H_INCLUDED
