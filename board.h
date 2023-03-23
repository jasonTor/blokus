#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <string>

#include "couleur.h"
#include "coordonnees.h"
#include "placement.h"
#include "pieces_set.h"

const int TAILLE_PLATEAU(20);

class Board
{
private:
    Color plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];

public:
    static const int SIZE;

    Board(); // Constructeur

    bool a_deja_joue(Color c); // Verifie si le joueur de la couleur a deja joué pour la première fois
    bool has_place(Placement p); // Verifie si le placement est libre (qu'il n'y a pas de chevauchement de piece)

    // Verifie entre autre si le joueur peut jouer le placement p
    bool CanPlace(Placement p); // Verifie si le joueur peut placer sa piece au placement p(orientation + position) selon les règles des coins, de chevauchement et du premier tour de jeu,

    const bool canPlay(const PiecesSet& s, Color c); // Verifie si le joueur de couleur c est Game Over
    std::string place(const Piece& p, Coordinate pos, Transformation t, Color c); // Met à jour le plateau en mettant les couleurs joué sur le plateau(si valide)
                                                                                  // Et retourne une chaine de caractere si succes ou erreur
    static bool validate(Coordinate c); // Verifie si une coordonnée est valide et n'est pas en dehors du plateau

    /* ------- GETTERS ----------------------*/
    const Color& getColor(const Coordinate& c) const;
    /* --------------------------------------*/

    /* ----------- SETTER -------------------*/
    void setPlateau(Color c, int xx, int yy);
    /* ---------------------------------------*/
};

#endif // BOARD_H_INCLUDED
