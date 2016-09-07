#pragma once
#include "viewplane.h"
#include "Ray.h"
#include "Camera.h"
#include "RGBColor.h"
#include "Tracer.h"

class World
{
private:
	
public:
	World();
	~World();
	RGBColor backgroundColor;
	Camera* camera;
	Tracer* tracer_ptr;
	World(void);
	void build(void);
	void set_camera(Camera* c_ptr);
	void render_scene();

	void open_window(const int hres, const int vres) const;

	void display_pixel(const int row, const int column, const RGBColor& pixel_color)const;
};

