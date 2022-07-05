#include "Ray.h"

Ray::Ray( Vector& Origin, Vector & Dir) :
    mOrigin(Origin),
    mDirection(Dir)
{
}

void Ray::SetOrigin( Vector& a_Origin ) 
{ 
    mOrigin = a_Origin; 
}

void Ray::SetDirection( Vector& a_Direction )
{
    mDirection = a_Direction; 
}

Vector& Ray::GetOrigin() 
{ 
    return mOrigin; 
}

Vector& Ray::GetDirection() 
{ 
    return mDirection; 
}

