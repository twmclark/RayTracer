#include "stdafx.h"
#include "Triangle.h"
#include "Vector3D.h"
#include "Point3D.h"
#include<iostream>

Triangle::Triangle(RGBColor col, Point3D a_, Point3D b_, Point3D c_)
	:color(col), a(a_),b(b_), c(c_)
{
}


Triangle::~Triangle()
{
}


double Triangle::intersection(Ray ray){
	
	double t;
	float EPS = 0.000001;
	Vector3D e1 = b - a;//edge1
	Vector3D e2 = c - a;
	Vector3D a2(a.x, a.y, a.z);
	Vector3D o2(ray.o.x, ray.o.y, ray.o.z);
	Vector3D b2(b.x, b.y, b.z);
	Vector3D c2(c.x, c.y, c.z);

	
	Vector3D N = (e1 ^ e2); 
	N.norm();
	float denom = N*N;

	float NdotRayd = N*ray.d;
	//check if ray plane is parallel
	if (NdotRayd < 1e-8){
		return -1;
	}
	float d = N*a2;

	t = (-(N*o2) + d)/NdotRayd;
	Vector3D s = ray.o - a;
	Vector3D q = s^e1;
	Vector3D p = ray.d ^ e2;
	float A = e1 * p;

	float f = 1.0f / A;
	
	//triangle is behind ray
	if (t < 0){
		return -1;
	}

	Vector3D P = o2 + (ray.d*t);

	Vector3D C;

	Vector3D edge0 = b - a;
	Vector3D vp0 = P - a2;
	C = edge0^vp0;

	if (N*C < 0){
		return -1;
	}

	Vector3D edge1 = c - b;
	Vector3D vp1 = P - b2;
	C = edge1^vp1;
	float u;
	if ((u = N*C) < 0){
		return -1;
	}
	float v;
	Vector3D edge2 = a - c;
	Vector3D vp2 = P - c2;
	C = edge2^vp2;
	if ((v = N*C) < 0){
		return -1;
	}

	return t;

}