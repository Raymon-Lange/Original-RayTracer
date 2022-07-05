#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>

class Vector{
    private:
       double x,y,z;

    public:

       Vector(const double a,const double b,const double c):x(a),y(b),z(c){};
     
       Vector operator+(const Vector& v)const{return Vector(x+v.x,y+v.y,z+v.z);}
       Vector operator-(const Vector& v)const{return Vector(x-v.x,y-v.y,z-v.z);}
       Vector operator-()const{return Vector(-x,-y,-z);}
       Vector operator*(const double d)const{return Vector(x*d,y*d,z*d);}
       Vector Cross(const Vector& v)const{return Vector(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);}

       double Dot(const Vector& v)const{return x * v.x + y * v.y + z * v.z;}
       double Lenght(const Vector& v)const{return sqrt(Dot(v));} 

       Vector Normalize()const{return *this * (1./sqrt(Dot(*this)));}

       double X(){return x;}
       double Y(){return y;}
       double Z(){return z;}

       void print(){std::cout << x << " " << y << " " << z <<std::endl;}
};
#endif
