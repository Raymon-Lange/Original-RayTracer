#ifndef OBJECT_H
#define OBJECT_H

#include "Vector.h"
#include "Ray.h"
#include <string>
#include "Color.h"
using namespace std;

class Object
{
    public:
        enum
        {
            SPHERE = 1,
            PLANE,
            TRIANGLE,
            TORUS
        };
        explicit Object(std::string name, bool isLight);
        virtual ~Object();
 
        virtual int GetType() = 0;
        virtual bool Intersect( Ray& a_Ray, double &distance) = 0;
        virtual Vector GetNormal( Vector& a_Pos ) = 0;  
        virtual void Light( bool a_Light ){ mLight = a_Light;}

        virtual void Reflective( double a_Reflective ){mReflective = a_Reflective;}
        virtual double GetReflective(){return mReflective;}
        virtual void Diffuse( double a_Diffuse ){mDiffuse = a_Diffuse;}
        virtual double GetDiffuse(){return mDiffuse;}

        bool IsLight(){return mLight;}
        void SetName(char* a_Name);
        std::string GetName();
        void SetColor(Color aColor);
        Color GetColor();
    protected: 
    private:
        std::string mName;
        bool mLight;
        Color mColor;
        double mReflective;
        double mDiffuse;
};
#endif //OBJECT_H
