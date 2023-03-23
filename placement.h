#ifndef PLACEMENT_H_INCLUDED
#define PLACEMENT_H_INCLUDED

#include "transformation.h"
#include "couleur.h"
#include "coordonnees.h"
#include "piece.h"

class Placement
{
private:
    Piece piece;
    Transformation transformation;
    Coordinate translation;
    Color couleur;

public:
    //Placement(Piece p, Transformation transf, Coordinate transl, Color c);
    Placement(const Piece& p, Transformation transf, Coordinate transl, Color c); // On met une r�f�rence � la piece pour eviter de copier les pieces d�ja existantes dans les possessions du joueur
    bool isValid(); // Verifie si la piece entre enti�rement sur le plateau (apres transformation et translation)

    /* ------------- LES GETTER ------------------ */
    const Piece& getPiece() const;
    Piece getPiece_bis() const;  // Renvoie la piece munie de ses carr�s apr�s transformation et translation
    const Transformation& getTransformation() const;
    const Coordinate& getTranslation() const;
    const Color& getCouleur() const;
    /*---------------------------------------------*/


    /*-------------- LES SETTERS ------------------*/
    void setTranslation(int xx, int yy);
    void setTransformation(Transformation t);
    /*---------------------------------------------*/


};

#endif // PLACEMENT_H_INCLUDED
