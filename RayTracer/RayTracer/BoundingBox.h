#pragma once
#include "Point3D.h"
#include <math.h> 
#include "Ray.h"
#include "stdafx.h"
#include<iostream>
#include"Point3D.h"
class BoundingBox
{
public:
	BoundingBox(const Point3D &min, const Point3D &max);
	Point3D min;
	Point3D max;
	float intersect(const Ray r);

	~BoundingBox();
};

