#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <iostream>
#include <ostream>

enum class Color{Empty, Blue, Yellow, Red, Green};

std::ostream &operator <<(std::ostream& strm, Color c);


#endif // COULEUR_H_INCLUDED
