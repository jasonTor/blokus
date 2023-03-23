#ifndef TRANSFORMATION_H_INCLUDED
#define TRANSFORMATION_H_INCLUDED

#include <array>
#include <vector>

/*
 * Liste des orientations possibles des pièces comme définies dans la figure 4
 */
enum class Transformation {
	None,
	OneQuarter,
	Half,
	ThreeQuarters,
	VMirrorNone,
	VMirrorOneQuarter,
	VMirrorHalf,
	VMirrorThreeQuarters,

};

/*
 * Liste des transformations possibles.
 *
 * Avoir cette collection déclarée de manière statique permet d'itérer sur les
 * transformations existantes existantes sans avoir à redéclarer des variables
 * de l'énumération Transformation à chaque fois qu'on en a besoin.
 */
constexpr static std::array<Transformation, 8> TRANSFORMATIONS{
	Transformation::None,
	Transformation::OneQuarter,
	Transformation::Half,
	Transformation::ThreeQuarters,
	Transformation::VMirrorNone,
	Transformation::VMirrorOneQuarter,
	Transformation::VMirrorHalf,
	Transformation::VMirrorThreeQuarters
};

std::vector<Transformation> vectorTransformation();

//Transformation tablTransformation[1] = {Transformation::Half};

#endif // TRANSFORMATION_H_INCLUDED
