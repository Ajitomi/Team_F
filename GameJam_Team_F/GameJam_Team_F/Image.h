#pragma once

#include "DxLib.h"
#include<iostream>

class Image {
private:

public:
	int image;
	float posx, posy;
	int width, hight;

	Image(std::string hundle);
	Image(std::string hundle, float x, float y);
	Image(std::string hundle, float x, float y,int w,int h);
	~Image();

	void SetSize(float x, float y);
	void SetSize(float x, float y, int w, int h);
};