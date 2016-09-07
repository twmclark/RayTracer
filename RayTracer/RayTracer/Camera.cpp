#include "stdafx.h"
#include "Camera.h"
#include "Point3D.h"
#include<iostream>



Camera::Camera(Point3D camP, Point3D look,float w,float h)
	:camPos(camP), lookAt(look), width(w), height(h)
{
	
}

Ray Camera::makeCamRay(int i, int j){

	Vector3D camUp(0, 1, 0);
	Vector3D camDir(lookAt - camPos);
	camDir.normalize();
	Vector3D camRight = camUp^camDir;
	camRight.normalize();
	Vector3D up = camRight^camDir;
	up.normalize();
	 
	double normalised_i = (i / width) - 0.5f;
	double normalised_j = (j / height )- 0.5f;
	//convert from degrees to radians
	float tanFov = tan(45 * 3.141592653589793 / 180.0f);

	

	Vector3D rayDirection = camDir + camRight * ((normalised_i )*tanFov) +
		up*((normalised_j )*tanFov);
	return Ray(camPos, rayDirection);
}

Camera::~Camera()
{
}
