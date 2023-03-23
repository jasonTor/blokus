#include "transformation.h"

std::vector<Transformation> vectorTransformation()
{
    std::vector<Transformation> s;
    s.push_back(Transformation::Half);
    s.push_back(Transformation::None);
    s.push_back(Transformation::OneQuarter);
    s.push_back(Transformation::ThreeQuarters);
    s.push_back(Transformation::VMirrorHalf);
    s.push_back(Transformation::VMirrorNone);
    s.push_back(Transformation::VMirrorOneQuarter);
    s.push_back(Transformation::VMirrorThreeQuarters);

    return s;
}
