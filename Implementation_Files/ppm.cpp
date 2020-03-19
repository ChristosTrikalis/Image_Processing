#include "ppm.h"
#include "stdafx.h"
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>  


using namespace std;

namespace imaging
{
	float * ReadPPM(const char * filename, int * w, int * h) {

		ifstream input;
		string header;
		unsigned int height, width, rgb;
		float * data_buffer;

		input = ifstream(filename, ios_base::in | ios_base::binary);
		if (input.good() == true) 
		{

			input >> header;
			input >> width;
			input >> height;
			input >> rgb;
			input.get();

			// Check if ppm form is P6
			if (strcmp(header.c_str(), "P6") != 0) {
				cout<< "This program only allows the use of P6 format.";
				return nullptr;
			}

			cout << filename << endl;
			cout << "Image dimensions are: " << width << " X " << height << endl;

			if (rgb > 255) {
				cout<<"This program only supports 24 bit images.";
				return nullptr;
			}

			data_buffer = new float[3 * width*height];
			unsigned char temp;
			for (unsigned int i = 0; i < width*height; i++)
			{
				input.read((char*)&temp, sizeof(unsigned char));
				data_buffer[3 * i] = temp / 255.0f;
				input.read((char*)&temp, sizeof(unsigned char));
				data_buffer[3 * i + 1] = temp / 255.0f;
				input.read((char*)&temp, sizeof(unsigned char));
				data_buffer[3 * i + 2] = temp / 255.0f;
			}
			*w = width;
			*h = height;
			input.close();
			return data_buffer;
		}
		else
		{
			cout << "Unable to open given file";
			return nullptr;
		}
	}

	/*! Writes an image buffer as a PPM file.
	*
	*  \param data contains the image buffer. The data are RGB float tripplets with values in the range [0,1].
	*  \param w is the width of the image in pixels.
	*  \param h is the height of the image in pixels.
	*  \param filename is the null-terminated string of the name of the file to create.
	*
	*  \return true if the image save operation was successful, false otherwise. If the data parameter is nulltr, the
	*  function returns immediately with a false return value.
	*/

	bool WritePPM(const float * data, int w, int h, const char * filename) {

		// Check bounds
		if (w == 0 || h == 0 || data == nullptr) {
			cout<<"Can't save an empty image\n";
			return false;
		}

		// Open filestream
		ofstream file = ofstream(filename, ios_base::out | ios_base::binary);
		if (file.good() == true)
		{
			//Assign ppm header
			file << "P6" << endl;
			file << w << endl;
			file << h << endl;
			file << 225 << endl;

			//Assign values
			unsigned char temp;
			for (int i = 0; i < w*h; i++)
			{
				temp = data[3 * i] * 255.0f;
				file.write((char*)&temp, sizeof(unsigned char));
				temp = data[3 * i + 1] * 255.0f;
				file.write((char*)&temp, sizeof(unsigned char));
				temp = data[3 * i + 2] * 255.0f;
				file.write((char*)&temp, sizeof(unsigned char));
			}
			file.close();
			return true;
		}
		else
		{
			cout<<"Unable to open given file";
			return false;
		}
	}
} //namespace imaging


