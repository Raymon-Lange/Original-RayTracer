#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object.h"

class Triangle : public Object
{
    private:
        Vector mP0;
        Vector mP1;
        Vector mP2;
    public:
        Triangle(std::string name, bool isLight, Vector p1, Vector p2, Vector p3);
        ~Triangle(){};
  	    bool Intersect( Ray& a_Ray, double &distance);
        Vector GetNormal( Vector& a_Pos );
        int GetType();	
};
#endif // _TRIANGLE_H
