#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <Windows.h>

typedef struct {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
} BMPHeader;

typedef struct {
	BMPHeader header;
	int height;
	int width;
	BYTE* image;
} BMPImage;

void gray_scale(BMPImage* bmpimg);
BMPImage load_bmp_image(const char* fName);
int save_bmp_image(const char* fName, BMPImage* savebmp);