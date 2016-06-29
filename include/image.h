#ifndef __IMAGE_H__INCLUDED__
#define __IMAGE_H__INCLUDED__

#include <fstream>
#include <string>
#include <vector>


#pragma pack(push,1)
struct HEADER
{
	unsigned short int type;
	unsigned int size;
	unsigned short int reserved1, reserved2;
	unsigned int offset;
};

struct INFOHEADER
{
	unsigned int size;
	int width, height;
	unsigned short int planes;
	unsigned short int bits;
	unsigned int compression;
	unsigned int imagesize;
	int xresolution, yresolution;
	unsigned int ncolours;
	unsigned int importantcolours;

};

struct RGB
{
	RGB(){}

	RGB(int r, int g, int b)
		:red(r), green(g), blue(b) {}

	int red;
	int green;
	int blue;
};

#pragma pack(pop)


System::Drawing::Bitmap^ loadImage(const std::string &path);

System::Drawing::Bitmap^ negativeImage(System::Drawing::Bitmap^ img);

System::Drawing::Bitmap^ clockWise(System::Drawing::Bitmap^ img);

System::Drawing::Bitmap^ counterClockWise(System::Drawing::Bitmap^ img);

System::Drawing::Bitmap^ flipV(System::Drawing::Bitmap^ img);

System::Drawing::Bitmap^ flipH(System::Drawing::Bitmap^ img);


#endif
