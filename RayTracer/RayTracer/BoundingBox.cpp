#include "stdafx.h"
#include "BoundingBox.h"
#include<iostream>


BoundingBox::BoundingBox(const Point3D &m, const Point3D &ma)
	:min(m), max(ma)
{}
//intersection test
float BoundingBox::intersect(const Ray r){

	float tmin = (min.x - r.o.x) / r.d.x;
	float tmax = (max.x - r.o.x) / r.d.x;

	if (tmin > tmax) {
		float mintemp = tmin;
		float maxtemp = tmax;
		tmin = maxtemp;
		tmax = mintemp;
	}

	float tymin = (min.y - r.o.y) / r.d.y;
	float tymax = (max.y - r.o.y) / r.d.y;

	if (tymin > tymax){
		float mintemp = tymin;
		float maxtemp = tymax;
		tymin = maxtemp;
		tymax = mintemp;
	}

	if ((tmin > tymax) || (tymin > tmax)){
		return -1;
	}
	if (tymin > tmin){
		tmin = tymin;
	}
	if (tymax < tmax){
		tmax = tymax;
	}
	float tzmin = (min.z - r.o.z) / r.d.z;
	float tzmax = (max.z - r.o.z) / r.d.z;

	if (tzmin > tzmax) {
		float mintemp = tzmin;
		float maxtemp = tzmax;
		tzmin = maxtemp;
		tzmax = mintemp;
	}

	if ((tmin > tzmax) || (tzmin > tmax)){
		return -1;
	}
	if (tzmin > tmin){
		tmin = tzmin;
	}
	if (tzmax < tmax){
		tmax = tzmax;
	}
	return tmin;
}

BoundingBox::~BoundingBox()
{
}
