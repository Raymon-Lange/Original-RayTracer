#ifndef COLOR_H
#define COLOR_H

class Color
{
    private:
        double mRed;
        double mGreen;
        double mBlue;
        
    public:
        explicit Color(double a_red, double a_green, double a_blue);
        ~Color();
        
        void operator += ( Color& a_V ) { mRed += a_V.mRed; mGreen += a_V.mGreen; mBlue += a_V.mBlue; }
        void operator += ( Color* a_V ) { mRed += a_V->mRed; mGreen += a_V->mGreen; mBlue += a_V->mBlue; }
        void operator -= ( Color& a_V ) { mRed -= a_V.mRed; mGreen -= a_V.mGreen; mBlue -= a_V.mBlue; }
        void operator -= ( Color* a_V ) { mRed -= a_V->mRed; mGreen -= a_V->mGreen; mBlue -= a_V->mBlue; }
        void operator *= ( double f ) { mRed *= f; mGreen *= f; mBlue *= f; }
        void operator *= ( Color& a_V ) { mRed *= a_V.mRed; mGreen *= a_V.mGreen; mBlue *= a_V.mBlue; }
        void operator *= ( Color* a_V ) { mRed *= a_V->mRed; mGreen *= a_V->mGreen; mBlue *= a_V->mBlue; }
        Color operator- () const { return Color( -mRed, -mGreen, -mBlue ); }
        friend Color operator + ( const Color& v1, const Color& v2 ) { return Color( v1.mRed + v2.mRed, v1.mGreen + v2.mGreen, v1.mBlue + v2.mBlue ); }
        friend Color operator - ( const Color& v1, const Color& v2 ) { return Color( v1.mRed - v2.mRed, v1.mGreen - v2.mGreen, v1.mBlue - v2.mBlue ); }
        friend Color operator + ( const Color& v1, Color* v2 ) { return Color( v1.mRed + v2->mRed, v1.mGreen + v2->mGreen, v1.mBlue + v2->mBlue ); }
        friend Color operator - ( const Color& v1, Color* v2 ) { return Color( v1.mRed - v2->mRed, v1.mGreen - v2->mGreen, v1.mBlue - v2->mBlue ); }
        friend Color operator * ( const Color& v, double f ) { return Color( v.mRed * f, v.mGreen * f, v.mBlue * f ); }
        friend Color operator * ( const Color& v1, Color& v2 ) { return Color( v1.mRed * v2.mRed, v1.mGreen * v2.mGreen, v1.mBlue * v2.mBlue ); }
        friend Color operator * ( double f, const Color& v ) { return Color( v.mRed * f, v.mGreen * f, v.mBlue * f ); }

 
        void SetRed(double a_red);
        void SetGreen(double a_green);
        void SetBlue(double a_blue);

        void SetColor(double a_red, double a_green, double a_blue);

        double Red();
        double Green();
        double Blue();        
};
#endif
