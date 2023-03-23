#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <vector>

#include "piece.h"
#include "pieces_set.h"
#include "couleur.h"

class Player
{
private:
    std::string name;
    PiecesSet hand;
    std::vector<Piece> last_piece;
    Color couleur;

public:
    Player(std::string n, PiecesSet m, std::vector<Piece> lp, Color c);

    void play(const Piece& p); // Retire la piece jouée par le joueur de sa main, et retient la dernière pièce jouée


    /* ----------- GETTERS -----------*/
    std::string getName() const;
    const PiecesSet& getHand() const;
    const Piece& getLastPiece() const;
    const Color& getCouleur() const;
    /*--------------------------------*/


    /* ----------- SETTERS -----------*/
    void setLastPiece(const Piece& p);
    /*--------------------------------*/


};

#endif // PLAYER_H_INCLUDED
