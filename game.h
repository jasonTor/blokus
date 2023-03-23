#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "board.h"
#include "player.h"
#include "text_interface.h"

class Game
{
private:

    TextInterfaceAscii ui;
    Board plateau_de_jeu;
    int turn;
    std::vector<Player> joueurs;



public:
    Game(TextInterfaceAscii& interf, Board& pdj, Player& joueur1, Player& joueur2, Player& joueur3, Player& joueur4);
    void playTurn(Color c);
    void playTurn(Color c, const Piece* p, Transformation t, Coordinate pos);

    std::vector<Player> getJoueur();
    int getTurn();
    bool isFinished();
    void nextTurn();
    int computeScore(Color c);

    Board getBoard() const;


};

#endif // GAME_H_INCLUDED
