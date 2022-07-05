#include "Color.h"

Color::Color(double a_red, double a_green, double a_blue):
            mRed(a_red), mGreen(a_green), mBlue(a_blue)
{

}

Color::~Color()
{

}
 
void Color::SetRed(double a_red)
{
    mRed = a_red;
}
        
void Color::SetGreen(double a_green)
{
    mGreen = a_green;
}

void Color::SetBlue(double a_blue)
{
    mBlue = a_blue;
}

void Color::SetColor(double a_red, double a_green, double a_blue)
{
    mRed = a_red;
    mGreen = a_green;
    mBlue = a_blue;
}

double Color::Red()
{
    return mRed;
}

double Color::Green()
{
    return mGreen;
}

double Color::Blue()
{
    return mBlue;
}

