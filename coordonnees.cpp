#include "coordonnees.h"
#include "transformation.h"

/*---------------------- OPERATEUR DE TRANSFORMATION ---------------------------------*/
Coordinate Coordinate::operator*(Transformation transformation) const
{
	Coordinate c{*this};
	switch (transformation) {
		case Transformation::None:
			break;
		case Transformation::OneQuarter:
			c.x = y;
			c.y = -x;
			break;
		case Transformation::Half:
			c.x = -x;
			c.y = -y;
			break;
		case Transformation::ThreeQuarters:
			c.x = -y;
			c.y = x;
			break;
		case Transformation::VMirrorNone:
			c.x = -x;
			c.y = y;
			break;
		case Transformation::VMirrorOneQuarter:
			c.x = -y;
			c.y = -x;
			break;
		case Transformation::VMirrorHalf:
			c.x = x;
			c.y = -y;
			break;
		case Transformation::VMirrorThreeQuarters:
			c.x = y;
			c.y = x;
			break;
	};
	return c;
}

Coordinate& Coordinate::operator*=(Transformation transformation)
{
	*this = operator*(transformation);
	return *this;
}
/*---------------------------------------------------------------------------*/



/* ---------------------- OPERATEUR DE TRANSLATION ---------------------------*/
Coordinate Coordinate::operator+(const Coordinate& translation) const
{
	return {x + translation.x, y + translation.y};
}

Coordinate& Coordinate::operator+=(const Coordinate& translation)
{
	*this = operator+(translation);
	return *this;
}
/*---------------------------------------------------------------------------*/



/*------------------- OPERATEUR D'ORDRE ------------------------------*/
bool operator<(const Coordinate& c1, const Coordinate& c2)
{
	return c1.y < c2.y || (c1.y == c2.y && c1.x < c2.x);
}

bool operator==(const Coordinate& c1, const Coordinate& c2)
{
	return c1.x == c2.x && c1.y == c2.y;
}

bool operator>(const Coordinate& c1, const Coordinate& c2)
{
	return !(c1 < c2) && !(c1 == c2);
}

bool operator<=(const Coordinate& c1, const Coordinate& c2)
{
	return (c1 < c2) || (c1 == c2);
}

bool operator>=(const Coordinate& c1, const Coordinate& c2)
{
	return (c1 > c2) || (c1 == c2);
}

bool operator!=(const Coordinate& c1, const Coordinate& c2)
{
	return !(c1 == c2);
}
/*-----------------------------------------------------------------*/

std::set<Coordinate> Coordinate::getCoin() const
{
    std::set<Coordinate> s;
    s.insert(Coordinate{x - 1, y - 1});
    s.insert(Coordinate{x - 1, y + 1});
    s.insert(Coordinate{x + 1, y + 1});
    s.insert(Coordinate{x + 1, y - 1});

    return s;

}

std::set<Coordinate> Coordinate::getCote() const
{
    std::set<Coordinate> s;
    s.insert(Coordinate{x - 1, y});
    s.insert(Coordinate{x, y + 1});
    s.insert(Coordinate{x + 1, y});
    s.insert(Coordinate{x, y - 1});

    return s;
}

