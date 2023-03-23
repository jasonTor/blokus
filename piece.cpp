#include "piece.h"

/* ------------------ CONSTRUCTEUR ---------------------------*/
Piece::Piece(std::vector<Coordinate> list_squares)
{
    int n(list_squares.size());
    for (int i(0); i<n ; i++)
    {
        squares.push_back(list_squares[i]);
    }
}
/* -----------------------------------------------------------*/



/* ------------------ GETTERS ---------------------------*/
const std::vector<Coordinate>& Piece::getSquares() const
{
    return squares;
}
/* ------------------------------------------------------*/


bool Piece::estEgale(const Piece& a) const
{

    if (squares.size() != a.getSquares().size()) {return false;}

    bool b(true);

    int n(a.getSquares().size());
    for (int i(0) ; i<n ; i++) // boucle qui verifie si chaque coordonnee sont egales
    {
        if (squares[i] != a.getSquares()[i]){return false;} //utilise l'operateur d'inégalité sur les coordonnées
    }

    return b;

}


bool Piece::estInferieur(const Piece&a) const
{
    if (squares.size() < a.getSquares().size()) {return true;}
    else if(squares.size() > a.getSquares().size()) {return false;}
    else if(squares.size() == a.getSquares().size())
    {
        int n(a.getSquares().size());
        for (int i(0) ; i<n ; i++)
        {
            if (squares[i] < a.getSquares()[i]){return true;} //utilise l'operateur de comparaison des coordonnées
        }

    }
    return false;
}




/* ------------ LES OPERATEURS D'ORDRE ------------------------ */

bool operator==(const Piece &a, const Piece &b)
{
    return a.estEgale(b);
}

bool operator<(const Piece &a, const Piece &b)
{
    return a.estInferieur(b);
}

bool operator!=(const Piece& p1, const Piece& p2)
{
    return !(p1 == p2);
}

bool operator<=(const Piece& p1, const Piece& p2)
{
    return (p1 < p2) || (p1 == p2);
}

bool operator>(const Piece& p1, const Piece& p2)
{
    return !(p1 < p2) && !(p1 == p2);
}


bool operator>=(const Piece& p1, const Piece& p2)
{
    return !(p1 < p2) || (p1 == p2);
}

//-----------------------------------------------------------------------



