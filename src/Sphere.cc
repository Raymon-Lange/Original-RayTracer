#include "Sphere.h"

Sphere::Sphere(std::string name, bool isLight,
               Vector a_Centre, double a_Radius ) : 
               Object(name, isLight),
               mCenter(a_Centre), mRadius(a_Radius)
{

}

Vector& Sphere::GetCenter()
{ 
    return mCenter;
}

double Sphere::GetRadius()
{ 
    return mRadius;
}
/*
bool Sphere::Intersect(Ray& aRay, double& distance)
{
    double  B, C, det;

    Vector d  = aRay.GetOrigin() - mCenter;
    B = d.Dot(aRay.GetDirection()) * 2.0;
    C = d.Dot(d) - (mRadius * mRadius);
    det = (B * B) - (4.0 * C);

    if(det > 0)
    {
        distance = ( -B - sqrt(det) ) * 0.5;
        if(det > 0)
            return true;
        else
            return false; 
    } 
     
    distance = 999999;
    return false;
    
}
*/

bool Sphere::Intersect(Ray& aRay, double& distance)
{
    //STEP: create a vector
    Vector v = mCenter - aRay.GetOrigin();

    double b = v.Dot(aRay.GetDirection());
    double disc = b*b - v.Dot(v) + mRadius * mRadius;

    //STEP: the ray did not hit the object
    if (disc < 0)
    {
        distance = 999999.0;
        return false;
    }

    double d = sqrt(disc);
    double t2 = b + d;
    double t1 = b - d;

    //STEP: we hit the other side of the object
    if (t2 < 0)
    {
        distance = 999999.0;
        return false;
    }

    //STEP: return the distance from the object
    if (t1 > 0)
    {
        distance = t1;
        return true;
    }
    else
    {
        distance = t2;
        return true;
    }
}

Vector Sphere::GetNormal( Vector& a_Pos )
{ 
    return (a_Pos - mCenter) * (1.0f / mRadius);
}

int Sphere::GetType()
{
    return SPHERE; 
}

