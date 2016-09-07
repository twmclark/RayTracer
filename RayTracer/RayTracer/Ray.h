#pragma once
#ifndef _RAY_
#define _RAY_

#include "Point3D.h"
#include "Vector3D.h"


class Ray
{
public:
	Point3D o; //origin
	Vector3D d; //destination

	Ray(void);
	Ray(const Point3D& origin, const Vector3D& dir); //constructor
	Ray(const Ray& ray); //copy operator

	Ray& operator=(const Ray& rhs);

	~Ray(void);
};
#endif
