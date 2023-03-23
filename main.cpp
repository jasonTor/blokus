#include <iostream>
#include <vector>
#include <set>
#include <initializer_list>
#include <map>

#include "couleur.h"
#include "piece.h"
#include "coordonnees.h"
#include "pieces_set.h"
#include "placement.h"
#include "board.h"
#include "transformation.h"
#include "text_interface.h"
#include "game.h"


#include "transformation.h"


//TODO : Ne pas oublier de mettre les attributs des classes en private.
//TODO : Mettre les const dans les methodes quand il le faut (surtout les getters)
//TODO : Optimiser board::canPlace en utilisant has_Place au lieu de isValid dans la premiere condition
//TODO : Corriger la regle des coins
//TODO : Faire en sorte que les pieces disparaissent des mains du joueur apres avoir joué


int main()
{

/* -------------------------------------------- LANCEMENT DU JEU ----------------------------------------------------- */

    // Création des set de pièce des joueurs
    PiecesSet ps1;
    PiecesSet ps2;
    PiecesSet ps3;
    PiecesSet ps4;

    // Création du vector qui contiendra la dernière pièce jouée par le joueur
    std::vector<Piece> lp1;
    std::vector<Piece> lp2;
    std::vector<Piece> lp3;
    std::vector<Piece> lp4;


    // Création du plateau de jeu
    Board plateau;

    // Creation de l'interface de jeu
    TextInterfaceAscii ui{std::cin, std::cout};

    // Création des 4 joueurs
    Player p1("Myrtille", ps1, lp1, Color::Blue);
    Player p2("Citron", ps2, lp2, Color::Yellow);
    Player p3("Cerise", ps3, lp3, Color::Red);
    Player p4("Kiwi", ps4, lp4, Color::Green);

    // Creation d'une instance Game
    Game g(ui, plateau, p1, p2, p3, p4);


    ui.getMessageOutput() << "      DEBUT DE LA PARTIE \n";
    std::cout << std::endl;

    ui.displayBoard(g.getBoard()); // Afficher le tableau
	while(!g.isFinished())
    {

        std::cout << "               Tour du joueur Blue" << std::endl;
        g.playTurn(Color::Blue);

        //std::cout << "               Tour du joueur Yellow" << std::endl;
        //g.playTurn(Color::Yellow);

        //std::cout << "               Tour du joueur Green" << std::endl;
        //g.playTurn(Color::Green);

        std::cout << "               Tour du joueur Red" << std::endl;
        g.playTurn(Color::Red);

        g.nextTurn();
	}




	std::cout << "score bleu : " << g.computeScore(Color::Blue) << std::endl;
	std::cout << "score jaune : " << g.computeScore(Color::Yellow) << std::endl;
	std::cout << "score rouge : " << g.computeScore(Color::Red) << std::endl;
	std::cout << "score vert : " << g.computeScore(Color::Green) << std::endl;


	ui.getMessageOutput() << "LA PARTIE est TERMINEE\n";

/* ---------------------------------------------------- FIN DE JEU ------------------------------------------------------------------- */




    // Q3a. Il s'agit d'une allocation statique





/* ------------------------------------------ QUELQUES ESSAIS ET MANIPULATION DE CODE ------------------------------------------------ */



    std::set<int>azer{12,21,31,43};
    std::set<const int*> aser;
    std::set<int>::iterator it = azer.begin();
    //const int* ptr = &*it;

    // AJOUT DES ADRESSE DE POINTEUR DANS ASSER
    while(it != azer.end())
    {
        aser.insert(&*it); // &*it récupère l'addresse de l'entier *it, tandis que *it désigne la variable pointée par it
        it++;
    }

    /*
    auto iter = aser.begin();
    while(iter != aser.end())
    {
        std::cout << **iter << " ";
        iter++;
    }
    */


    /*
    auto ite = azer.begin();
    while(ite != azer.end())
    {
        std::cout << &*ite << " ";
        ite++;
    }
    */


    Coordinate c {1,1};

    Transformation t{Transformation::Half};
    Coordinate cor{1,0};
    cor*=t;
    //std::cout << "{" << cor.x << "," << cor.y << "}" << std::endl;

    Piece p21(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}});
    Placement p(p21, Transformation{Transformation::Half}, Coordinate{12,16}, Color{Color::Blue});
    /*
    for(auto carre : p.getPiece_bis().getSquares())
    {
        std::cout << "{" << carre.x << "," << carre.y << "}" << " ";
    }
    */



    //p.isValid();

    //if(p.isValid()){std::cout << "ok";}
    //else{std::cout << "impossible a placer";}

    //std::cout << "{" << cor.x << "," << cor.y << "}" << std::endl;





    /* ------- ESSAIS POUR RETIRER UNE ADRESSE --------------------

    std::set<int>azer{12,21,31,43};
    std::set<const int*> aser;
    std::set<int>::iterator it = azer.begin();
    //const int* ptr = &*it;

    // AJOUT DES ADRESSE DE POINTEUR DANS ASSER
    while(it != azer.end())
    {
        aser.insert(&*it); // &*it récupère l'addresse de l'entier *it, tandis que *it désigne la variable pointée par it
        it++;
    }

    // RETIRER L ADRESSE DE 31 DANS ASER
    std::set<int>::iterator yt = azer.find(31);
    aser.erase(&*yt);

    /*
    for(auto l : aser)
    {
        std::cout << *l << std::endl;
    }

    ---------------------------------------------------------------*/


    /* ------------------------------------- LISTES DES 21 PIECES ---------------------------------------------------------------------

    PiecesSet psc; // Il ne faut pas mettre PiecesSet psc() car le compilateur va penser que c'est une fonction



    std::set<Piece> set_p;
    Piece p11(std::vector<Coordinate>{Coordinate{0,0}});
    Piece p21(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}});
    Piece p31(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}});
    Piece p32(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{0, 1}});
    Piece p41(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{3, 0}});
    Piece p42(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{0, 1}, Coordinate{1, 1}});
    Piece p43(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{0, 1}});
    Piece p44(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{1, 1}});
    Piece p45(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{1, 1}, Coordinate{2, 1}});
    Piece p51(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{3, 0}, Coordinate{4,0}});
    Piece p52(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{3, 0}, Coordinate{0,1}});
    Piece p53(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{3, 0}, Coordinate{1,1}});
    Piece p54(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{0, 1}, Coordinate{0,2}});
    Piece p55(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{1, 1}, Coordinate{1,2}});
    Piece p56(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 1}, Coordinate{2, 1}, Coordinate{0, 0}, Coordinate{2,2}});
    Piece p57(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 1}, Coordinate{2, 1}, Coordinate{0, 0}, Coordinate{1,2}});
    Piece p58(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 1}, Coordinate{2, 1}, Coordinate{1, 0}, Coordinate{1,2}});
    Piece p59(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{0, 1}, Coordinate{1,1}});
    Piece p510(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{2, 1}, Coordinate{3,1}});
    Piece p511(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{1, 1}, Coordinate{2, 1}, Coordinate{2,2}});
    Piece p512(std::vector<Coordinate>{Coordinate{0,0}, Coordinate{1, 0}, Coordinate{2, 0}, Coordinate{0, 1}, Coordinate{2,1}});


    std::set<Piece> s;


    s.insert(p11);
    s.insert(p21);
    s.insert(p31);
    s.insert(p32);
    s.insert(p41);
    s.insert(p42);
    s.insert(p43);
    s.insert(p44);
    s.insert(p45);
    s.insert(p51);
    s.insert(p52);
    s.insert(p53);
    s.insert(p54);
    s.insert(p55);
    s.insert(p56);
    s.insert(p57);
    s.insert(p58);
    s.insert(p59);
    s.insert(p510);
    s.insert(p511);
    s.insert(p512);






    Coordinate a{23,0};
    Coordinate b{0,1};

    std::initializer_list<Coordinate> liste_de_coordonnee{{0, 0}, {1, 0}, {2, 0}, {3, 0}};
    std::vector<Coordinate> liste_de_carre;
    for(auto i : liste_de_coordonnee)
    {
        liste_de_carre.push_back(i);
    }
    Piece p(liste_de_carre);

    // std::cout << p.getSquares()[3].x;







    /*
    std::vector<Coordinate> liste_de_carre1;
    liste_de_carre1.push_back(Coordinate{0,0});
    liste_de_carre1.push_back(Coordinate{0,1});

    std::vector<Coordinate> liste_de_carre2;
    liste_de_carre2.push_back(Coordinate{0,0});
    liste_de_carre2.push_back(Coordinate{0,1});
    */


    /*
    Piece p1(std::vector<Coordinate>{Coordinate{0,0},Coordinate{1,0},Coordinate{2,0},Coordinate{3,0}});
    Piece p2(std::vector<Coordinate>{Coordinate{0,0},Coordinate{1,0},Coordinate{0,1},Coordinate{1,1}});



    std::set<Piece> ens_de_piece = {p1,p2};
    auto iter = ens_de_piece.end();
    iter--;

    //std::cout << iter->getSquares()[0].x;


    //if (p1 == p2){std::cout << "ok" << std::endl;}
    //else{std::cout << "pas egale" << std::endl;}
    */

}







