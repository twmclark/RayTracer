#pragma once
#include "RGBColor.h"
#include "Ray.h"
#include "World.h"
class Tracer
{
public:
	Tracer(void);
	World* world_ptr;

	RGBColor Tracer::trace_ray(const Ray& ray) const{
		return RGBColor(0, 0, 0);
	}
	Tracer::Tracer(World* w_ptr) :world_ptr(w_ptr){}

	~Tracer();
};

