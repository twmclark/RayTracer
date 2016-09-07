#pragma once
#include "Point3D.h"
#include "RGBColor.h"
#include "Normal.h"
class ShadeRec
{
public:
	ShadeRec();

	bool hit_an_object;
	Point3D local_hit_point;
	RGBColor  color;
	Normal	normal;

	~ShadeRec();
};

