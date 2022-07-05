#include "Triangle.h"

Triangle::Triangle(std::string name, bool isLight, 
                   Vector p0, Vector p1, Vector p2) :
                   Object(name, isLight),
                   mP0(p0), mP1(p1), mP2(p2)
{

}

bool Triangle::Intersect(Ray& aRay, double& distance)
{
    double u, v;
    Vector edge1(0,0,0), edge2(0,0,0), tvec(0,0,0), pvec(0,0,0), qvec(0,0,0);
    double det, invDet;
    
    edge1 = mP1 - mP0;
    edge2 = mP2 - mP0;
    pvec = aRay.GetDirection().Cross(edge2);
    
    det = edge1.Dot(pvec);

   if(det > -.000001 && det < .000001)
   {
        return false;
   }
   invDet = 1/det;

   tvec = aRay.GetOrigin() - mP0;

   u = tvec.Dot(pvec) * invDet;
   if(u < 0 || u > 1)
   {
        return false;
   }

   qvec = tvec.Cross(edge1);

   v = aRay.GetDirection().Dot(qvec) * invDet;
   if(v < 0 || (u + v) > 1)
   {
        return false;
   }
      
   double dis = edge2.Dot(qvec) * invDet;
   if(dis < 0)
   {
        return false;
   }
   
    distance = dis;
    return true;
}

Vector Triangle::GetNormal( Vector& a_Pos )
{
    Vector A = mP1 - mP0;
    Vector B = mP2 - mP0;

    Vector v = A.Cross(B);

    v = v.Normalize();

    return v;
}

int Triangle::GetType()
{
    return TRIANGLE;
}

