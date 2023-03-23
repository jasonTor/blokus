#include <iostream>
#include "pieces_set.h"
#include "coordonnees.h"

// -----------------------------  Foncion qui permet l'initialisation des 21 piece dans la static attribut  --------------------------------
std::set<Piece> pieces_depart()
{
    std::set<Piece> set_piece; // On initialise un ensemble
    std::vector<Coordinate> vector_coordinate; // On initialise un vecteur contenant des coordonnées, elle servira a creer chaque pieces du jeu
    std::vector<Piece> vector_piece; // on cree un vecteur de piece

    // On crée un vecteur contenant 21 conteneurs de type liste d'initialisation de coordonnée, adaptés aux carrés des 21 pieces differentes du jeu
    std::vector<std::initializer_list<Coordinate>> liste_des_coordonnees = {
        std::initializer_list<Coordinate> {{0, 0}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {0, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {1, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {0, 2}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {1, 1}, {1, 2}},
        std::initializer_list<Coordinate> {{0, 1}, {1, 1}, {2, 1}, {0, 0}, {2, 2}},
        std::initializer_list<Coordinate> {{0, 1}, {1, 1}, {2, 1}, {0, 0}, {1, 2}},
        std::initializer_list<Coordinate> {{0, 1}, {1, 1}, {2, 1}, {1, 0}, {1, 2}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {3, 1}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}},
        std::initializer_list<Coordinate> {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {2, 1}}
    };


    for(auto i : liste_des_coordonnees)
    {

        for(auto k : i) //k est de type coordinate
        {
            vector_coordinate.push_back(k);

        }


        vector_piece.push_back(Piece(vector_coordinate));
        set_piece.insert(Piece(vector_coordinate));
        vector_coordinate.clear();
    }

    return set_piece;
}
//------------------------------------------------------------------------------------------------------



const std::set<Piece> PiecesSet::set_piece = pieces_depart(); //initialisation des 21 pièces de départ dans l'attribut static


// Renvoie l'ensemble static des 21 pièces set_piece
const std::set<Piece> PiecesSet::static_getSetPiece()
{
    return set_piece;
}


// Constructeur de PiecesSet qui ajoute l'adresse (donc un pointeur) de chacune des pièce contenues dans l'attribut
// dans l'attribut static set_piece dans l'attribut pieces_joueur, initialisé avec les 21 adresses des 21 pieces différentes
PiecesSet::PiecesSet()
{
    std::set<Piece>::iterator it;
    it = set_piece.begin();
    while(it != set_piece.end())
    {
        pieces_joueur.insert(&*it);
        it++;
    }
}




// Getter qui renvoie une référence sur l'attribut pieces_joueur
const std::set<const Piece*>& PiecesSet::get_pieces_joueur() const
{
    return pieces_joueur;
}

const std::set<const Piece*>& PiecesSet::getCollection() const
{
    return pieces_joueur;
}





bool PiecesSet::empt()
{
    return pieces_joueur.size() == 0;
}

void PiecesSet::remo(const Piece& p)
{
    if(!this->empt())  //Si l'ensemble n'est pas vide
    {
        std::set<Piece>::iterator it = PiecesSet::set_piece.find(p);
        pieces_joueur.erase(&*it);
    }
}

