#include "problem3.h"
void gray_scale(BMPImage* bmp) {
	//******************Problem******************//
	int i, j;
	int height = bmp->header.infoHeader.biHeight;
	int width = bmp->header.infoHeader.biWidth;
	BYTE	R, G, B, GRAY;
	BMPImage *grayBMP = (BMPImage*)malloc (sizeof(BMPImage)*1);
	memcpy(grayBMP, bmp,sizeof(BMPImage)*1);

	//24 bit 트루컬러를 grayscale 로 변환
	if (grayBMP->header.infoHeader.biBitCount == 24)
	{
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				B = bmp->image[i * width * 3 + 3 * j];
				G = bmp->image[i * width * 3 + 3 * j + 1];
				R = bmp->image[i * width * 3 + 3 * j + 2];
				GRAY = (BYTE)(0.2126 * R + 0.7152 * G + 0.0722 * B);
				grayBMP->image[i * width +  j] = GRAY;
			}
		}
	}

	grayBMP->header.infoHeader.biBitCount = 8;
	grayBMP->header.infoHeader.biSizeImage =height*width+54;
	memcpy(bmp, grayBMP, sizeof(BMPImage) * 1);
	return;
	//******************Problem******************//
}


BMPImage load_bmp_image(const char* fName) {
	BMPImage tempbmp;
	BYTE* image = NULL;
	RGBQUAD pallete[256];
	FILE* infile;
	infile = fopen(fName, "rb");
	if (infile == NULL) {
		printf("Cannot Open File\n");
		exit(0);
	}
	fread(&(tempbmp.header.fileHeader), sizeof(BITMAPFILEHEADER), 1, infile);
	if (tempbmp.header.fileHeader.bfType != 0x4D42)
		exit(0);
	fread(&(tempbmp.header.infoHeader), sizeof(BITMAPINFOHEADER), 1, infile);
	if (tempbmp.header.infoHeader.biBitCount == 8) {
		fread(pallete, sizeof(RGBQUAD), 256, infile);
	}
	tempbmp.image = (BYTE*)malloc(sizeof(BYTE) * tempbmp.header.infoHeader.biSizeImage);
	fread(tempbmp.image, sizeof(BYTE), tempbmp.header.infoHeader.biSizeImage, infile);
	tempbmp.height = tempbmp.header.infoHeader.biHeight;
	tempbmp.width = tempbmp.header.infoHeader.biWidth;
	fclose(infile);

	printf("Load BMP file success\n");
	return tempbmp;
}

int save_bmp_image(const char* fName, BMPImage* savebmp) {
	FILE* outfile;
	outfile = fopen(fName, "wb");
	if (outfile == NULL) {
		return -1;
	}
	fwrite(&(savebmp->header.fileHeader), sizeof(BYTE), sizeof(BITMAPFILEHEADER), outfile);
	fwrite(&(savebmp->header.infoHeader), sizeof(BYTE), sizeof(BITMAPINFOHEADER), outfile);
	RGBQUAD pallete[256];
	// default 8bit pallete for grey bitmap
	for (int i = 0; i < 256; i++)
	{
		pallete[i].rgbBlue = i;
		pallete[i].rgbGreen = i;
		pallete[i].rgbRed = i;
		pallete[i].rgbReserved = 0;
	}

	// case of 8-bit bitmap (gray)
	if (savebmp->header.infoHeader.biBitCount == 8) {
		printf("File Format of 8 bit count\n");
		fwrite(pallete, sizeof(RGBQUAD), 256, outfile);
	}

	// case of 24-bit bitmap (color)
	if (savebmp->header.infoHeader.biBitCount == 24)
		printf("File Format of 24 bit count\n");
	fwrite(savebmp->image, sizeof(BYTE), savebmp->header.infoHeader.biSizeImage, outfile);
	fclose(outfile);
	printf("Writing BMP File success\n");
	return 0;
}
int main() {
	BMPImage BMP;
	BMP = load_bmp_image("test.bmp");
	gray_scale(&BMP);
	if (save_bmp_image("gray.bmp", &BMP) != 0) {
		printf("Fail Writing BMP File\n");
	}
	free(BMP.image);
	return 0;
}


