#pragma once
#include "GeometricObject.h"
#include "Point3D.h"
#include "RGBColor.h"
#include <math.h> 
#include "Ray.h"
#include "stdafx.h"
#include "CImg.h"
#include <stdio.h>
#include<iostream>

using namespace cimg_library;
class Plane : public GeometricObject
{
public:
	Plane();
	Plane(const Point3D pos,const Vector3D norm, RGBColor col,float ref, float spec,double diffuse);
	virtual double intersection(Ray ray);
	bool textured = true;
	RGBColor color;
	float spec;
	Vector3D normal;
	Point3D position;
	float ref;
	double diff ;
	virtual Vector3D getNormal(Point3D& pos){
		return normal;
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
	virtual int getType(){
		return 2;
	}
	//proceduraly generate checked texture
	virtual RGBColor getTexture(Point3D& pos, CImg<int> &image){
		
		int x = pos.x;
		int z = pos.z;
		if ((x+z) % 2 == 0){
			return(RGBColor(255, 255, 255));
		}
		else{
			return(RGBColor(0, 0, 0));
		}
		

	}
	virtual double getDiff(){
		return diff;
	}
	virtual float getRef(){
		return ref;
	}
	virtual float getSpec(){
		return spec;
	}
	virtual bool hasTexture(){
		return textured;
	}
	virtual ~Plane();
};

