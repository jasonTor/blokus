#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "coordonnees.h"
#include <vector>

class Piece
{
private:
    std::vector<Coordinate> squares;


public:
    Piece(std::vector<Coordinate> list_squares); //constructeur

    /* --------- GETTERS ----------*/
    const std::vector<Coordinate>& getSquares() const;
    /* -----------------------------*/

    bool estEgale(const Piece& a) const;
    bool estInferieur(const Piece&a) const;

    auto begin() const { return squares.begin(); }
    auto end() const { return squares.end(); }

};


bool operator==(const Piece &a, const Piece &b);
bool operator<(const Piece &a, const Piece &b);

bool operator!=(const Piece& p1, const Piece& p2);
bool operator>(const Piece& p1, const Piece& p2);
bool operator>=(const Piece& p1, const Piece& p2);
bool operator<=(const Piece& p1, const Piece& p2);



#endif // PIECE_H_INCLUDED
