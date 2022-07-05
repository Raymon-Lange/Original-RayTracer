#ifndef RAY_H
#define RAY_H

#include "Vector.h"

class Ray
{
    private:
        Vector mOrigin;
        Vector mDirection;
    public:
        Ray(Vector& Origin, Vector&Dir);
        void SetOrigin( Vector& a_Origin );
        void SetDirection( Vector& a_Direction );
        Vector& GetOrigin();
        Vector& GetDirection();
};
#endif //RAY_H
