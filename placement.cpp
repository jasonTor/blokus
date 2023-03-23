#include <iostream>

#include "coordonnees.h"
#include "placement.h"
#include "board.h"
#include "piece.h"


Placement::Placement(const Piece& p, Transformation transf, Coordinate transl, Color c) :
    piece(p), transformation(transf), translation(transl), couleur(c)
{

}

/*
    std::vector<Coordinate> list_carre;
    for(auto carre : p.getSquares())
    {
        list_carre.push_back(carre);
    }
    piece_bis = Piece(list_carre);
*/



bool Placement::isValid()
{
    for(auto carre : piece.getSquares())
    {
        carre*=transformation;
        carre+=translation;
        if(!Board::validate(carre)){return false;}
    }
    return true;
}




/* --------------------- LES GETTER ------------------- */
const Piece& Placement::getPiece() const
{
    return piece;
}

Piece Placement::getPiece_bis() const
{
    std::vector<Coordinate> list_carre;
    for(auto carre : piece.getSquares())
    {
        carre*=transformation;
        carre+=translation;
        list_carre.push_back(carre);
    }
    return Piece(list_carre);
}

const Transformation& Placement::getTransformation() const
{
    return transformation;
}

const Coordinate& Placement::getTranslation() const
{
    return translation;
}

const Color& Placement::getCouleur() const
{
    return couleur;
}
/*-------------------------------------------------------*/


/*-------------- LES SETTERS ------------------*/
void Placement::setTranslation(int xx, int yy)
{
    translation.x = xx;
    translation.y = yy;

}

void Placement::setTransformation(Transformation t)
{
    transformation = t;

}
/*---------------------------------------------*/
