#include <iostream>
#include "Image.h"
#include "Vec3.h"
#include "Filter.h"
using namespace imaging;
using namespace math;

typedef Vec3<float> VecVal;

filterGamma::filterGamma() {
	pw = 0.5f;
}

filterGamma::filterGamma(float p) 
{
	if(p>=0.5 && p<=2.0)
		pw = p;
	else
	{
		if (pw < 0.5f)
			pw = 0.5f;
		else if (pw > 2.0f)
			pw = 2.0f;
	}

	
}

Image filterGamma::operator << (const Image& img)
{
	Image newimg = img;									
	for (unsigned int j = 0; j < img.getHeight(); j++)
	{
		for (unsigned int i = 0; i < img.getWidth(); i++)
		{
			VecVal item = newimg.getColor(i, j);
			item.r = pow(item.r, pw);
			item.g = pow(item.g, pw);
			item.b = pow(item.b, pw);

			item.clampToLowerBound(0.0f);
			item.clampToUpperBound(1.0f);

			newimg.setColor(i, j, item);
		}
	}

	return newimg;
}
