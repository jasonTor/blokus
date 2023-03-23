#ifndef TRANSFORMATION_H_INCLUDED
#define TRANSFORMATION_H_INCLUDED

#include <array>
#include <vector>

/*
 * Liste des orientations possibles des pi�ces comme d�finies dans la figure 4
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
 * Avoir cette collection d�clar�e de mani�re statique permet d'it�rer sur les
 * transformations existantes existantes sans avoir � red�clarer des variables
 * de l'�num�ration Transformation � chaque fois qu'on en a besoin.
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
