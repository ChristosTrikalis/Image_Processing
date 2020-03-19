
#include "Image.h"
#include "Vec3.h"
#include"ppm.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace math;
using namespace imaging;

namespace imaging
{
	Image::Image() :Array(0, 0) {		}

	Image::Image(unsigned int width, unsigned int height) : Array(width, height) {	}

	Image::Image(unsigned int width, unsigned int height, const vector<Color>& data_ptr)	:	Array(width, height) {
		setData(data_ptr);
	}

	Image::~Image()
	{
	
	}
	Image::Image(const Image &src) :Array(src) {}

	//Image::Image
	bool Image::load(const std::string & filename, const std::string & format) {

		int lenght = filename.length();
		if (filename.substr(lenght - 3, lenght - 1) != format) {
			cout << "Only .ppm files accepted\n";
			return false;
		}
		// If the Image object is initialized, its contents are wiped out before initializing it to the width, height and data read from the file.
		// Not sure about this!

		int w, h;
		float * array = ReadPPM(filename.c_str(), &w, &h);
		if (array != nullptr)
		{
			width = w;
			height = h;
			buffer.resize(w*h);
			for (unsigned int i = 0; i < w*h; i++) {
				buffer[i] = Color(array[3 * i], array[3 * i + 1], array[3 * i + 2]);
			}
			delete[]array;
			return true;

		}
		return false;

	}

	bool Image::save(const std::string & filename, const std::string & format) 
	{

		int lenght = filename.length();
		if (filename.substr(lenght - 3, lenght - 1) != format) {
			cout << "Only .ppm files accepted\n";
			return false;
		}
		//If the *Image object is not initialized
		if (buffer.empty())
		{
			cout << "Image object not initialized";
			return false;
		}
		float * array = new float[width * height * 3];
		unsigned int c = 0;
		for (unsigned int i = 0; i < width * height; i++) 
		{
			c = 3 * i;
			array[c] = buffer[i].r;
			array[c + 1] = buffer[i].g;
			array[c + 2] = buffer[i].b;

		}
		bool written = WritePPM(array, width, height, filename.c_str());
		delete[]array;
		if (written) 
		{
			cout << "Image successfully saved \n";
			return true;
		}
		else {
			cout << "Image save was unsuccessfull \n";
			return false;
		}
	}
}