#include <iostream>

#include "game.h"
#include "placement.h"
#include "coordonnees.h"

Game::Game(TextInterfaceAscii& interf, Board& pdj, Player& joueur1, Player& joueur2, Player& joueur3, Player& joueur4):
    ui(interf), plateau_de_jeu(pdj), turn(1), joueurs{joueur1,joueur2,joueur3,joueur4}
{

}

void Game::playTurn(Color c)
{
    auto j = joueurs.begin();
    while(j != joueurs.end()) // On parcourt les joueurs en considerant que chacun a une couleur differente
    {


        if(j->getCouleur() == c) // On selectionne le joueur j ayant la couleur c
        {

            if(plateau_de_jeu.canPlay(j->getHand(), c)) // Si le joueur n'est pas game over
            {
                while(1)
                {
                    std::cout << "Nombre de piece main du joueur " << j->getCouleur() << " : " << j->getHand().size() << std::endl;
                    const Piece* p(ui.getPiece(j->getHand())); // Creation dune piece, Le joueur selectionne la piece qu'il souhaite jouer, il s'agit ici d'un pointeur sur piece
                    Placement pl(*p, ui.getTransformation(p), ui.getPosition(), c); // Creation d'un placement, Le joueur selectionne la position et l'orientation de la piece qu'il souhaite placer
                    if(plateau_de_jeu.CanPlace(pl))
                    {
                        std::cout << plateau_de_jeu.place(*p, pl.getTranslation(), pl.getTransformation(), c) << std::endl; // Met à jour le plateau, et affiche un texte si succes ou echec de placement
                        j->play(*p);// Retire la piece jouee par le joueur // la piece a bien été retenu comme derniere piece
                        ui.displayBoard(plateau_de_jeu);
                        break;
                    }
                    //j.play(*p);
                    std::cout << plateau_de_jeu.place(*p, pl.getTranslation(), pl.getTransformation(), c) << std::endl; // Met à jour le plateau, et affiche un texte si succes ou echec de placement
                    ui.displayBoard(plateau_de_jeu);


                }
            }
            else{std::cout << "Le joueur " << j->getCouleur() << " " << "est game over";}


        }
        //else{std::cout << j.getCouleur() << " ";}
        j++;

    }
    //ui.displayBoard(plateau_de_jeu);
}



bool Game::isFinished()
{
    return !plateau_de_jeu.canPlay(joueurs[0].getHand(),joueurs[0].getCouleur()) && !plateau_de_jeu.canPlay(joueurs[1].getHand(),joueurs[1].getCouleur()) && !plateau_de_jeu.canPlay(joueurs[2].getHand(),joueurs[2].getCouleur()) && !plateau_de_jeu.canPlay(joueurs[3].getHand(),joueurs[3].getCouleur());
}


void Game::nextTurn()
{
    turn++;
}


int Game::computeScore(Color c)
{
    int score(0); // on initialise le score du joueur de couleur c à 0
    for (auto j : joueurs)
    {
        if(j.getCouleur() == c)
        {
            if(j.getHand().size() == 0)
            {
                if(j.getLastPiece() == Piece(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{0, 1}, Coordinate{1, 1}})){return 20;}
                else{return 15;}
            }
            for(auto pi : j.getHand().get_pieces_joueur()) // On parcourt les pointeurs pi (pointeur vers des pieces)
            {
                score -= pi->getSquares().size();
            }
            return score;
        }
    }
}


std::vector<Player> Game::getJoueur()
{
    return joueurs;
}

int Game::getTurn()
{
    return turn;
}

Board Game::getBoard() const
{
    return plateau_de_jeu;
}


