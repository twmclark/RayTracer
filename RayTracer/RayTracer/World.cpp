#include "stdafx.h"
#include "World.h"
#include "Vector3D.h"
#include "Point3D.h"

World::World() : 
backgroundColor(0),
camera(NULL) {}

void World::render_scene(){
	if (camera){
		//camera->render_scene(*this);
	}

	RGBColor pixelColor;
	Ray ray;
	ray.d = Vector3D(0, 0, -1);
	double x, y;
	float pixelSize = plane.pixelSize;

	for (int r = 0; r < plane.vres; r++){
		for (int c = 0; c <= plane.hres; c++){
			
		}
	}

}

World::~World()
{
}
