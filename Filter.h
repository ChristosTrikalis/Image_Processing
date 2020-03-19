#include <iostream>
#include <cmath>
#include "Image.h"
#include "Vec3.h"
using namespace imaging;
using namespace math;



class Filter
{

	public:
		virtual Image operator << (const Image& img)=0;

	//default constructor?
};

typedef Vec3<float> VecVal;
class filterLinear : public Filter
{
	protected:
		VecVal a, c;
	public:

		filterLinear(VecVal a, VecVal c);
		filterLinear();

		filterLinear(const VecVal& src);

		Image operator << (const Image& img);
		
};
class filterGamma : public Filter
{
	protected:
		float pw;
	public:
		filterGamma();

		filterGamma(float p);

		Image operator << (const Image& img);
		

};
