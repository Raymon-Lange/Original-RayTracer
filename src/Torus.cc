#include "Torus.h"

Torus::Torus(std::string name, bool isLight,double radius,double tubeRadius) :
                   Object(name, isLight),
                   mRadius(radius), mTubeRadius(tubeRadius)
{

}

bool Torus::Intersect( Ray& aRay, double &distance)
{
    double x1 = aRay.GetOrigin().X(); 
    double y1 = aRay.GetOrigin().Y(); 
    double z1 = aRay.GetOrigin().Z();
	double d1 = aRay.GetDirection().X(); 
    double d2 = aRay.GetDirection().Y(); 
    double d3 = aRay.GetDirection().Z();	
	
	double coeffs[5];	// coefficient array for the quartic equation
	double roots[4];	// solution array for the quartic equation
	
	// define the coefficients of the quartic equation
	
	double sum_d_sqrd 	= d1 * d1 + d2 * d2 + d3 * d3;
	double e			= x1 * x1 + y1 * y1 + z1 * z1 - mRadius * mRadius - mTubeRadius *  mTubeRadius;
	double f			= x1 * d1 + y1 * d2 + z1 * d3;
	double four_a_sqrd	= 4.0 * mRadius * mRadius;
	
	coeffs[0] = e * e - four_a_sqrd * (mTubeRadius * mTubeRadius - y1 * y1); 	// constant term
	coeffs[1] = 4.0 * f * e + 2.0 * four_a_sqrd * y1 * d2;
	coeffs[2] = 2.0 * sum_d_sqrd * e + 4.0 * f * f + four_a_sqrd * d2 * d2;
	coeffs[3] = 4.0 * sum_d_sqrd * f;
	coeffs[4] = sum_d_sqrd * sum_d_sqrd;  					// coefficient of t^4
	
	// find roots of the quartic equation
	
	int num_real_roots = SolveQuartic(coeffs, roots);
	
	bool	intersected = false;
	double 	t 		 	= 1.0E10;
	
	if (num_real_roots == 0)  // ray misses the torus
		return false;
	
	// find the smallest root greater than kEpsilon, if any
	// the roots array is not sorted
			
	for (int j = 0; j < num_real_roots; j++)  
		if (roots[j] > .000001) {
			intersected = true;
			if (roots[j] < t)
				t = roots[j];
		}
		
	if(!intersected)
		return false;
		
	distance= t;
	return true;
}

Vector Torus::GetNormal( Vector& aPos )
{
    double param_squared = mRadius * mRadius + mTubeRadius * mTubeRadius;

	double x = aPos.X();
	double y = aPos.Y();
	double z = aPos.Z();
	double sum_squared = x * x + y * y + z * z;
	
	x = 4.0 * x * (sum_squared - param_squared);
	y = 4.0 * y * (sum_squared - param_squared + 2.0 * mRadius * mRadius);
	z = 4.0 * z * (sum_squared - param_squared);
 
    Vector normal(x,y,z);
	normal.Normalize();
	
	return (normal);	
}

int Torus::GetType()
{
    return TORUS;
}

