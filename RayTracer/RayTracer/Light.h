#pragma once
#include "Point3D.h"
#include "RGBColor.h"

class Light
{
public:
	Light(Point3D location, RGBColor color);
	RGBColor color;
	Point3D location;
	Light();
	~Light();
};

