#include <iostream>
#include "Image.h"
#include "Vec3.h"
#include "Filter.h"
using namespace imaging;
using namespace math;
typedef Vec3<float> VecVal;


filterLinear::filterLinear(VecVal aV, VecVal cV)
{
	
		a.r = aV.r;
		a.g = aV.g;
		a.b = aV.b;	
		c.r = cV.r;
		c.g = cV.g;
		c.b = cV.b;
	
}

filterLinear::filterLinear()
{
	a.r = 0.0f;
	a.g = 0.0f;
	a.b = 0.0f;

	c.r = 0.0f;
	c.g = 0.0f;
	c.b = 0.0f;
}

filterLinear::filterLinear(const VecVal& src)
{
	a.r = src.r; 
	a.g = src.g; 
	a.b = src.b;

	c.r = src.r;
	c.g = src.g;
	c.b = src.b;
}

Image filterLinear::operator<<(const Image& img)
{
	Image newimg = img;
	for (unsigned int j = 0; j < img.getHeight(); j++)
	{
		for (unsigned int i = 0; i < img.getWidth(); i++)
		{
			VecVal item = newimg.getColor(i, j);

			item = (a * item) + c;
			item.clampToLowerBound(0.0f);
			item.clampToUpperBound(1.0f);

			newimg.setColor(i, j, item);
		}
	}
	return newimg;
}
