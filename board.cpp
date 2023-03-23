#include <iostream>

#include "board.h"
#include "couleur.h"
#include "coordonnees.h"
#include "placement.h"
#include "transformation.h"

/*------------ Constructeur par defaut ------------------------- */
Board::Board()
{
    for (int i(0) ; i<=20 ; i++)
    {
        for(int j(0) ; j<=20 ; j++)
        {
            plateau[i][j] = Color::Empty;   //On initialise chaque case du plateau à Empty
        }
    }
}
/*---------------------------------------------------*/



bool Board::validate(Coordinate c)
{
    if(c.x <= 19 && c.y <= 19) // Verifie si une coordonnée est valide et n'est pas en dehors du plateau
    {
        return true;
    }
    else{return false;}

}

bool Board::a_deja_joue(Color c)
{
    if(plateau[0][0] == c){return true;}
    else if(plateau[0][19] == c){return true;}
    else if(plateau[19][0] == c){return true;}
    else if(plateau[19][19] == c){return true;}
    return false;
}

bool Board::has_place(Placement p)
{
    if(p.isValid()) // Verifie si la piece entre entièrement sur le plateau (apres transformation et translation)
    {
        for(auto carre : p.getPiece_bis().getSquares())
        {
            if(plateau[carre.x][carre.y] != Color::Empty) {return false;} // Si le carre est occupé return false
        }
        return true;
    }
    return false; // Si la piece n'entre pas entièrement sur le plateau (apres transformation et translation)
}



/* ------------------------------ CANPLACE VERIFIE SI UN PLACEMENT EST VALIDE -------------------------------------- */
bool Board::CanPlace(Placement p)
{
    if(!this->a_deja_joue(p.getCouleur())) // Si le joueur joue pour la première fois
    {

        if(p.isValid()) // Si la piece entre entièrement sur le plateau (après transformation et translation)
        {
            for(auto carre : p.getPiece_bis().getSquares()) // On parcourt les carre de la piece (apres transfo et translation)
            {
                if(plateau[0][0] == Color::Empty && carre.x == 0 && carre.y == 0){return true;}
                else if(plateau[0][19] == Color::Empty && carre.x == 0 && carre.y == 19){return true;}
                else if(plateau[19][0] == Color::Empty && carre.x == 19 && carre.y == 0){return true;}
                else if(plateau[19][19] == Color::Empty && carre.x == 19 && carre.y == 19){return true;}
            }
            return false; // Aucun des carrés ne peut être dans un des coins

        }
        return false; // Si la piece ne rentre pas entièrement sur le plateau ( après transformation et translation )
    }


    else // Si le joueur a déja joué la première fois
    {
        if(this->has_place(p)) // Si la piece a la place de libre, sans chevauchement de piece (après transformation et translation)
        {
            for(auto carre : p.getPiece_bis().getSquares()) // On parcourt les carrés de la pièce (après transformation et translation)
            {
                for(auto cote : carre.getCote())
                {
                    if(Board::validate(cote)) // Si le coin existe dans le plateau
                    {
                        if(plateau[cote.x][cote.y] == p.getCouleur()){return false;}
                    }
                }
                for(auto coin : carre.getCoin()) // On parcourt les 4 coins du carré en question
                {
                    if(Board::validate(coin)) // Si le coin existe dans le plateau
                    {
                        if(plateau[coin.x][coin.y] == p.getCouleur()){return true;} // Si le coin est occupé par une pièce de la même couleur return true
                        //return false;
                    }
                }

            }
            return false; // Si aucun des carrés de la piece possède un coin occupé par une pièce de la même couleur
        }
        return false;
    }
}
/* ----------------------------------------------------------------------------------------------------------------- */


/*---------- verifie si pour un ensemble de piece d'une couleur, il est possible de jouer ou pas (GAME OVER OU NON)----------------------*/
const bool Board::canPlay(const PiecesSet& s, Color c)
{
    std::vector<Transformation> tabTransfo = vectorTransformation(); // On crée la liste des transformation possible sous forme de vecteur

    std::set<const Piece*>::iterator it = s.get_pieces_joueur().begin(); // Création d'un iterateur de std::set<const Piece*> ensemble de pointeur de piece
    while(it != s.get_pieces_joueur().end()) //on parcourt les pointeurs de l'ensemble de piece
    {
        Placement pl(**it, Transformation::Half, Coordinate{0,0}, Color::Blue); // On initialise un placement
        for (auto transf : tabTransfo)  // On parcourt les différentes orientation possible
        {
            pl.setTransformation(transf); // On applique la transformation trans au placement pl
            for(int i(0) ; i<20 ; i++)
            {
                for(int j(0) ; j<20 ; j++) // On realise une double boucle i et j pour parcourir les 20*20 du tableau
                {
                    pl.setTranslation(i,j);  // On applique la translation a la case i,j
                    if(this->CanPlace(pl)){return true;} // si le joueur peut placer sa piece à cet emplacement alors return true
                }
            }
        }

        it++;
    }
    return false; // Game over
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/


std::string Board::place(const Piece& p, Coordinate pos, Transformation t, Color c)
{
    Placement pl(p, t, pos, c);
    if(this->CanPlace(pl))
    {
        for(auto carre : pl.getPiece_bis().getSquares())
        {
            plateau[carre.x][carre.y] = c;
        }
        return "SUCCES : La piece a ete placee avec succes";
    }
    if(!pl.isValid())
    {
        return "ECHEC : La piece ne rentre pas dans le plateau";
    }
    if(!this->has_place(pl))
    {
        return "ECHEC : Il y a deja des pieces a cet emplacement";
    }
    return "ECHEC : Regle des coins non respectee";

}


const Color& Board::getColor(const Coordinate& c) const
{
    return plateau[c.x][c.y];
}

void Board::setPlateau(Color c, int xx, int yy)
{
    plateau[xx][yy] = c;
}

const int Board::SIZE = 20;







