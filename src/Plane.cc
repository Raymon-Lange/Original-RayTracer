#include "Plane.h"

Plane::Plane(std::string name, bool isLight,Vector a_Cord, double a_depth) :
            Object(name, isLight),
            mCord(a_Cord),
            mDepth(a_depth)
{

}

Plane::~Plane()
{

}

bool Plane::Intersect( Ray& aRay, double& distance)
{
    double Vd = mCord.Dot(aRay.GetDirection());

    if(Vd != 0)
    {
        double Vo = -(mCord.Dot(aRay.GetOrigin()) + mDepth);
        double t = Vo/Vd;
        
        if(t > 0)
        {
            distance = t;
            return true;
        }
    }
    return false;
}

Vector Plane::GetNormal( Vector& a_Pos )
{
    return mCord;
}

int Plane::GetType()
{
    return PLANE;
}
