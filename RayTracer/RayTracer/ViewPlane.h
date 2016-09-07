#pragma once
class ViewPlane
{
private:
	
public:
	int hres;
	int vres;
	float s;
	float gamma;
	float inv_gamma;

	ViewPlane();
	ViewPlane(int h, int v, float s_, float gamma_) :hres(h), vres(v), s(s_), gamma(gamma_), inv_gamma(1 / gamma){}
	void set_hres(const int h_res);
	void set_vres(const int v_res);
	void set_pixel_size(const float s);
	void set_gamma(const float gamma);


	~ViewPlane();
};


