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
using namespace std;

class Triangle: public GeometricObject
{
public:
	Triangle(RGBColor col, Point3D a, Point3D b, Point3D c);
	~Triangle();
	Point3D a;
	Point3D b;
	Point3D c;
	float ref = 1;
	float spec = 0.3;
	float diff = 10;
	RGBColor color;
	virtual double intersection(Ray ray);
	bool textured = false;

	virtual float getRef(){
		return ref;
	}
	virtual float getSpec(){
		return spec;
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
	virtual Vector3D getNormal(Point3D& pos){	
		return(((b - a) ^ (c - a)));
	}
	
	virtual RGBColor getTexture(Point3D& pos, CImg<int> &image){
		return(RGBColor(255, 25, 25));
	}
	virtual double getDiff(){
		return diff;
	}
	virtual int getType(){
		return 2;
	}
	//triangles have no texture
	virtual bool hasTexture(){
		return textured;
	}
};

