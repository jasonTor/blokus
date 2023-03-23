#ifndef PIECES_SET_H_INCLUDED
#define PIECES_SET_H_INCLUDED

#include "piece.h"
#include <set>

class PiecesSet
{
private:

    std::set<const Piece*> pieces_joueur; //Contient un ensemble de pointeur de Piece qui pointe vers une pièce de l'ensemble static set_piece


public:
    static const std::set<Piece> set_piece; // Contient les 21 différentes pièces possibles

    PiecesSet(); // Constructeur

    bool empt(); // Verifie si pieces_joueur est vide
    void remo(const Piece& p); // retire la piece p de pieces_joueur

    auto size() const { return pieces_joueur.size(); }

    /* ------------------- LES GETTER ----------------------- */
    static const std::set<Piece> static_getSetPiece(); // Getter methode static qui renvoie l'attribut static  set_piece
    const std::set<const Piece*>& get_pieces_joueur() const; // Getter qui renvoie pieces_joueur (ensemble de pointeur de piece)via une référence
    const std::set<const Piece*>& getCollection() const;
    /*--------------------------------------------------------*/
};


std::set<Piece> pieces_depart(); // Foncion qui permet l'initialisation des 21 piece dans la static attribut


#endif // PIECES_SET_H_INCLUDED
