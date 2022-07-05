#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

class Sphere : public Object
{
    public:
        Sphere(std::string name, bool isLight, Vector a_Centre, double a_Radius );
        Vector& GetCenter();
        double GetRadius();
        bool Intersect( Ray& a_Ray, double &distance);
        Vector GetNormal( Vector& a_Pos ); 
        int GetType();
    private:
        Vector mCenter;
        double mRadius;
};
#endif //SPHERE_H
