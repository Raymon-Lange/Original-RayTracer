#ifndef TORUS_H
#define TORUS_H

#include "Object.h"
#include "Maths.h"
class Torus : public Object
{
    private:
        double mRadius; 
        double mTubeRadius;
    public:
        Torus(std::string name, bool isLight, double radius,double tubeRadius);
        ~Torus(){};
        bool Intersect( Ray& a_Ray, double &distance);
        Vector GetNormal( Vector& a_Pos );
        int GetType();
};
#endif // TORUS_H
