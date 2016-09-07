#pragma once
#include "Ray.h"
#include "RGBColor.h"
#include "CImg.h"
/*
Superclass for objects
*/

using namespace cimg_library;
class GeometricObject
{
public:
	GeometricObject();
	virtual double intersection(Ray ray);
	RGBColor color;
	virtual float getRef() = 0; 
	bool textured;
	virtual Vector3D getNormal(Point3D& pos) = 0;
	virtual bool hasTexture() = 0;
	virtual float getSpec() = 0;
	virtual int getType() = 0;
	virtual float getR() = 0;
	virtual float getG() = 0;
	virtual float getB() = 0;
	double diff;
	virtual RGBColor getTexture(Point3D& pos, CImg<int> &image) = 0;
	virtual double getDiff() = 0;
	virtual ~GeometricObject();
	Ray m_ray;
};

