#include "Object.h"

Object::Object(std::string name, bool isLight) : 
              mName( name ), mLight( isLight ), mColor(Color(0,0,0)), mReflective(0.0), mDiffuse(0.0)
{

}

Object::~Object()
{

}

void Object::SetName( char* a_Name )
{
    mName = a_Name;
}

std::string Object::GetName()
{
    return mName; 
}

void Object::SetColor(Color aColor)
{
    mColor = aColor;
}

Color Object::GetColor()
{
    return mColor;
}
