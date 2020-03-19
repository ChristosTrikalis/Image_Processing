//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2017 - 2018
//
//

#ifndef _IMAGE
#define _IMAGE
#include "array.h"
#include "ppm.h"
#include "Vec3.h"
#include <string>
using namespace std;
using namespace math;


typedef Vec3<float> Color;

namespace imaging
{
	class Image : public Array<Color>
	{
	public:
		Image();

		Image(unsigned int width, unsigned int height);

		Image(const Image &src);

		Image(unsigned int width, unsigned int height, const vector<Color>& data_ptr);

		~Image();

		//Image& operator = (const Image& src);
		Color getColor(unsigned x, unsigned y) { return Array::getItem(x, y); }

		void setColor(unsigned x, unsigned y,Color val){  Array::setItem(x, y,val); }

		bool load(const std::string & filename, const std::string & format);

		bool save(const std::string & filename, const std::string & format);

	};

} 

#endif
