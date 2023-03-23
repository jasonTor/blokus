#include "couleur.h"

std::ostream &operator <<(std::ostream& strm, Color c)
{

    if(c == Color::Blue){return strm << "Blue";}
    else if(c == Color::Yellow){return strm << "Yellow";}
    else if(c == Color::Red){return strm << "Red";}
    else if(c == Color::Green){return strm << "Green";}

}
