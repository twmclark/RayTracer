#include "stdafx.h"
#include "Plane.h"


Plane::Plane()
{
}
Plane::Plane(const Point3D pos, const Vector3D norm, RGBColor col,float ref_, float spec_,double diffuse)
	:position(pos),normal(norm), color(col),ref(ref_),spec(spec_), diff(diffuse){}

double Plane::intersection(Ray ray){
	//dot product n.ray
	float denom = normal*ray.d;

	if (denom >= 0.0f){
		//ray.o*normal
		return -1;
	}

		//float t = -(normal.x*ray.o.x + normal.y*ray.o.y + normal.z*ray.o.z) + 1000000.0f / denom;

		float t = (position*ray.d - ray.o*normal) / denom;
		return t;

	
	
}


Plane::~Plane()
{
}
