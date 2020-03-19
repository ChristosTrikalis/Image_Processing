#include <iostream>
#include <vector>
using namespace std;

namespace math
{
	template<typename T>
	class Array
	{
		protected:
			unsigned int width;
			unsigned int height;
			vector<T> buffer;

		public:

			T * getRawDataPtr()
			{
				return &buffer[0];
			}

			T getItem(unsigned int x, unsigned int y) const
			{
				if (x <= width && y <= height)
				{
					return buffer[y* width + x];
				}
				else
				{
					return buffer[0]; //auto edw isws allaksei. pros to paron stelnei apla thn prwth 8esh tou pinaka, ekei pou h getPixel epestrefe to Color(0,0,0)
				}
			}


			void setItem(unsigned int x, unsigned int y, T & value) 
			{
				if (x < width && y < height) 
				{
					buffer[y*width + x] = value;
				}
			}

			
			void setData(const vector<T> & data_ptr)
			{
				if (buffer.size() == data_ptr.size()) {
					
					for (unsigned int i = 0; i < width*height; i++)
					{
						buffer[i] = data_ptr[i];
					}
				}
			}

		
			Array(unsigned int w, unsigned int h):buffer(width*height)
			{
				this->width = width;
				this->height = height;
			}

			
			Array(const Array<T> & src):buffer(src.width*src.height)
			{
				height = src.height;
				width = src.width;
				for (unsigned int i = 0; i < width*height; i++)
				{
					buffer[i] = src.buffer[i];
				}
			}

			
			~Array()
			{
				
			}

			Array<T>& operator = (const Array<T> & right) 
			{
				width = right.width;
				height = right.height;
				for (unsigned int i = 0; i < width*height; i++) {
					buffer[i] = right.buffer[i];
				}
				return *this;
			}

			T& operator() (unsigned int x, unsigned int y) const 
			{
				if (x < width && y < height) 
				{
					return buffer[y*width + x];
				}
				else {
					return buffer[0];
				}
			}



			const unsigned int getWidth() const { return width; }

			const unsigned int getHeight() const { return height; }

			
	};

}
