#include "Image.h"


Image::Image(std::string hundle) {
	image = LoadGraph(hundle.c_str());
	posx = 0;
	posy = 0;
	width = -1;
	hight = -1;
}

Image::Image(std::string hundle, float x, float y) {
	image = LoadGraph(hundle.c_str());
	posx = x;
	posy = y;
	width = -1;
	hight = -1;
}

Image::Image(std::string hundle, float x, float y, int w, int h) {
	image = LoadGraph(hundle.c_str());
	posx = x;
	posy = y;
	width = w;
	hight = h;
}

Image::~Image() {
	delete this;
}

void Image::SetSize(float x, float y) {
	posx = x;
	posy = y;
}

void Image::SetSize(float x, float y, int w, int h) {
	posx = x;
	posy = y;

	if (w > 0) {
		width = w;
	}
	
	if (h > 0) {
		hight = h;
	}
}