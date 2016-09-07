#pragma once
#include "GeometricObject.h"
#include <math.h> 
#include "Point3D.h"
#include "RGBColor.h"
#include <math.h> 
#include "Ray.h"
#include "stdafx.h"
#include "ShadeRec.h"
#include "CImg.h"
#include<iostream>
#include "stdafx.h"
#include <assert.h>
using namespace cimg_library;
class Sphere :public GeometricObject
{
public:
	Sphere();

	Sphere(Point3D center_, double r_,RGBColor col,float ref,float spec,double diffuse,bool tex);
	virtual double intersection(Ray ray);
	RGBColor color;
	float spec;
	Point3D center;
	double radius;
	float ref;//reflection value
	double diff = 0.6;
	static const double kEpsilon;
	CImg<int> img;
	bool textured ; 

	inline void
		Sphere::set_center(const double x, const double y, const double z) {
		center.x = x;
		center.y = y;
		center.z = z;
	}
	virtual float getR(){
		return color.r;
	}
	virtual float getG(){
		return color.g;
	}
	virtual float getB(){
		return color.b;
	}
	virtual double getDiff(){
		return diff;
	}

	inline void
		Sphere::set_radius(const double r) {
		radius = r;
	}
	inline void
		Sphere::set_color(const RGBColor c){
		color = c;
	}

	virtual Vector3D getNormal(Point3D& pos){
		return(pos - center) * radius;
	}
	virtual int getType(){
		return 1;
	}

	virtual bool hasTexture(){
		return textured;
	}

	Sphere(const Sphere& sphere);

	
	//Calculate texture
	virtual RGBColor getTexture(Point3D& pos,CImg<int> &image){
		
		//normal of intersection point and sphere
		Vector3D N = this->getNormal(pos);
		N.normalize();
	
		double u = 0.5 + atan2(N.y, N.x) / (2 * 3.141592653589793);
		double v = 0.5 - asin(N.y) / 3.141592653589793;
		
		float width = u * img.width();//105 is image width
		float height = v * img.height();

		
		float r;
		float g;
		float b;

		r = img(width, height, 0, 0);
		g = img(width, height, 0, 1);
		b = img(width, height, 0, 2);

		return(RGBColor(r, g, b));
	}
	virtual float getRef(){
		return ref;
	}
	virtual float getSpec(){
		return spec;
	}
	
	virtual ~Sphere();
};

