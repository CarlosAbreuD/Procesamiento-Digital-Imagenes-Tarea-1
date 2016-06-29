#include "image.h"

void makePallete(std::vector<RGB> &v, int nColors , std::ifstream &bmp)
{
	for (int i = 0; i < nColors; ++i)
	{
		unsigned char red, green, blue, a;

		bmp.read((char*)&blue, 1);
		bmp.read((char*)&green, 1);
		bmp.read((char*)&red, 1);
		bmp.read((char*)&a, 1);

		v.push_back(RGB((int)red , (int)green , (int)blue));
	}
}

void getRGB(System::Drawing::Bitmap^ %img, std::vector<RGB> pallete, int nBits , int padding, std::ifstream &bmp)
{
	int mask;

	if (nBits == 8)
		mask = 255;
	else if (nBits == 4)
		mask = 240;
	else if (nBits == 2)
		mask = 192;
	else
		mask = 128;

	if (img->Height < 0)
	{
		// TOP-BOT

		for (int i = 0; i < img->Height; ++i)
		{
			for (int j = 0; j < img->Width; )
			{
				unsigned char b;
				bmp.read((char*)&b, 1);

				for (int k = 0; k < 8; k += nBits)
				{
					int pos = ((int)b >> k) & mask;
					System::Drawing::Color color = System::Drawing::Color::FromArgb(pallete[pos].red, pallete[pos].green, pallete[pos].blue);
					img->SetPixel(j++, i, color);
				}
			}

			bmp.seekg(padding, bmp.cur);
		}
	}
	else
	{
		// BOT-TOP

		for (int i = img->Height - 1; i >= 0; --i)
		{
			for (int j = 0; j < img->Width; )
			{
				unsigned char b;
				bmp.read((char*)&b, 1);

				for (int k = 0; k < (8/nBits); ++k)
				{
					int pos = (int)b & (mask >> k*nBits);
					pos = pos >> (8 - nBits - k*nBits);
					System::Drawing::Color color = System::Drawing::Color::FromArgb(pallete[pos].red, pallete[pos].green, pallete[pos].blue);
					img->SetPixel(j++, i, color);
				}
			}

			bmp.seekg(padding, bmp.cur);
		}
	}

}

void getRGB(System::Drawing::Bitmap^ %img, int padding, std::ifstream &bmp)
{
	for (int i = img->Height - 1; i >= 0; --i)
	{
		for (int j = 0; j < img->Width; ++j)
		{
			unsigned char red, green, blue;
			bmp.read((char*)&blue, 1);
			bmp.read((char*)&green, 1);
			bmp.read((char*)&red, 1);

			System::Drawing::Color color = System::Drawing::Color::FromArgb((int)red, (int)green, (int)blue);

			img->SetPixel(j, i, color);
		}

		bmp.seekg(padding, bmp.cur);
	}
}


System::Drawing::Bitmap^ loadImage(const std::string &path)
{
	std::ifstream imageBMP (path, std::fstream::binary);
	System::Drawing::Bitmap^ img;

	if (imageBMP)
	{
		HEADER h;
		INFOHEADER ih;

		imageBMP.read((char*)&h, sizeof(HEADER));
		imageBMP.read((char*)&ih, sizeof(INFOHEADER));

		img = gcnew System::Drawing::Bitmap(ih.width, ih.height);
		std::vector<RGB> pallete;

		if (ih.ncolours == 0 && ih.bits <= 8)
			makePallete(pallete, std::pow(2, ih.bits), imageBMP);
		else if ( ih.ncolours != 0 )
			makePallete(pallete, ih.ncolours , imageBMP);

		imageBMP.seekg(h.offset, imageBMP.beg);
		int rowSize = ((ih.bits*ih.width + 31) / 32) * 4;
		int padding = rowSize - ((ih.bits*ih.width + 7)/8);

		if ( !pallete.empty() )
			getRGB(img, pallete, ih.bits, padding,imageBMP);
		else
			getRGB(img, padding,imageBMP);

	}

	return img;
}



System::Drawing::Bitmap^ negativeImage(System::Drawing::Bitmap^ img)
{
	System::Drawing::Bitmap^ negative = gcnew System::Drawing::Bitmap(img->Width , img->Height);

	for (int i = 0; i < negative->Height; ++i)
	{
		for (int j = 0; j < negative->Width; ++j)
		{
			System::Drawing::Color color = img->GetPixel(j, i);
			System::Drawing::Color nColor = System::Drawing::Color::FromArgb(255 - color.R, 255 - color.G, 255 - color.B);
			negative->SetPixel(j, i, nColor);

		}
	}

	return negative;
}

System::Drawing::Bitmap^ clockWise(System::Drawing::Bitmap^ img)
{
	System::Drawing::Bitmap^ cwImage = gcnew System::Drawing::Bitmap(img->Height, img->Width);

	for (int i = 0; i < img->Height; ++i)
	{
		for (int j = 0; j < img->Width; ++j)
		{
			System::Drawing::Color color = img->GetPixel(j, i);
			cwImage->SetPixel(cwImage->Width - 1 - i , j, color);

		}
	}

	return cwImage;
}

System::Drawing::Bitmap^ counterClockWise(System::Drawing::Bitmap^ img)
{
	System::Drawing::Bitmap^ ccwImage = gcnew System::Drawing::Bitmap(img->Height, img->Width);

	for (int i = 0; i < img->Height; ++i)
	{
		for (int j = 0; j < img->Width; ++j)
		{
			System::Drawing::Color color = img->GetPixel(j, i);
			ccwImage->SetPixel(i , ccwImage->Height - 1 - j, color);

		}
	}

	return ccwImage;
}


System::Drawing::Bitmap^ flipV(System::Drawing::Bitmap^ img)
{
	System::Drawing::Bitmap^ vImage = gcnew System::Drawing::Bitmap(img->Width, img->Height);

	for (int i = img->Height - 1; i >= 0; --i)
	{
		for (int j = 0; j < img->Width; ++j)
		{
			System::Drawing::Color color = img->GetPixel(j, i);
			vImage->SetPixel(j,(vImage->Height-1) - i, color);

		}
	}

	return vImage;
}


System::Drawing::Bitmap^ flipH(System::Drawing::Bitmap^ img)
{
	System::Drawing::Bitmap^ hImage = gcnew System::Drawing::Bitmap(img->Width, img->Height);

	for (int i = 0; i < img->Height; ++i)
	{
		for (int j = 0; j < img->Width; ++j)
		{
			System::Drawing::Color color = img->GetPixel(j, i);
			hImage->SetPixel((img->Width-1) - j, i, color);

		}
	}

	return hImage;
}