#include "stdafx.h"
#include "RGBColor.h"


RGBColor::RGBColor(void)
	:r(0.0), g(0.0), b(0.0)
{}

RGBColor::RGBColor(float c)
	: r(c), g(), b(c){}

RGBColor::RGBColor(float _r, float _g, float _b)
	: r(_r), g(_b), b(_b){}

RGBColor::RGBColor(const RGBColor& c)
	: r(c.r), g(c.g), b(c.b){}

RGBColor::~RGBColor(void)
{
}
