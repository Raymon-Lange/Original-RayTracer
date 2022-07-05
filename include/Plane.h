#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

class Plane : public Object
{
    private:
        Vector mCord;
        double mDepth;
    public:
        Plane(std::string name, bool isLight,Vector a_Cord, double a_depth);
        ~Plane();

        bool Intersect( Ray& a_Ray, double &distance);
        Vector GetNormal( Vector& a_Pos );
        int GetType();
    
};
#endif //PLANE_H
