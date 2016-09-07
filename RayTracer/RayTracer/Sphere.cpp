#include "stdafx.h"
#include "Sphere.h"
#include<iostream>
using namespace std;

Sphere::Sphere()
{
}

Sphere::Sphere(Point3D center_, double r_,RGBColor col, float ref_,float spec_, double diffuse,bool tex)
	:center(center_), radius(r_), color(col), ref(ref_), spec(spec_), textured(tex), diff(diffuse)
{
	img.assign("pattern2.bmp");
}

Sphere::Sphere(const Sphere& sphere)
	: center(sphere.center), radius(sphere.radius), color(sphere.color)
{}

//Sphere intersection test
 double Sphere::intersection(Ray ray){
	Vector3D q = ray.o - center;
	double t;
	//calculate coefficients of quadratic equation
	double a = ray.d*ray.d;
	double b = 2 * (ray.d*q);
	double c = (q*q) - (radius*radius);
	//discriminant
	double disc = b*b - 4 * a*c;

	if (disc < 0.0){//if negative no intersection
		return -1;}
	
	double distSqrt = sqrt(disc);
	double e;

	if (b < 0.0){
		e = (-b - distSqrt) / 2;
	} else{
		e = (-b + distSqrt) / 2;
	}
	double t0 = e / a;
	double t1 = c / e;

	if (t0 > t1){
		double temp = t0;
		t0 = t1;
		t1 = temp;
	}

	if (t1 < 0.0){
		return -1;
	}
	if (t0 < 0.0){
		t = t1;
	} else{
		t = t0;
	}
	return t;

}


Sphere::~Sphere()
{
}
