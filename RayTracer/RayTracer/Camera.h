#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"
class Camera
{
public:
	Point3D camPos;
	Point3D lookAt;
	 float width;
	 float height;
	
	float tanFov;

	Camera(Point3D camP, Point3D look, float w,float h);

	Camera();

	void setEye(const Point3D& p); //set position using point3d

	void setEye(const float x_, const float y_, const float z_); //set position using xyz

	void setLookat(Point3D p);

	void setLookat(const float x_, const float y_, const float z_); //set position using xyz

	Ray makeCamRay(int i, int j);

	Vector3D x, y, z;
	~Camera();
};

