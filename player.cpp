#include "player.h"

/* ---------------------------- CONSTRUCTEUR -----------------------------*/
Player::Player(std::string n, PiecesSet m, std::vector<Piece> lp, Color c) :
    name(n), hand(m), last_piece(lp), couleur(c)
{

}
/*------------------------------------------------------------------------*/


/* --------------- GETTERS ---------------*/
std::string Player::getName() const
{
    return name;
}

const PiecesSet& Player::getHand() const
{
    return hand;
}


const Piece& Player::getLastPiece() const
{
    return last_piece[0];
}

const Color& Player::getCouleur() const
{
    return couleur;
}
/*---------------------------------------*/



/* ---------- SETTERS --------------------*/

void Player::setLastPiece(const Piece& p)
{
    last_piece.clear();
    last_piece.push_back(p);
}
/*---------------------------------------*/





void Player::play(const Piece& p)
{
    hand.remo(p);
    last_piece.clear();
    last_piece.push_back(p);
}




