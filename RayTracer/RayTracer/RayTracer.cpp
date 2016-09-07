// RayTracer.cpp : Defines the entry point for the console application.
//
#include "Sphere.h"
#include "stdafx.h"
#include "Vector3D.h"
#include<iostream>
#include "RGBColor.h"
#include "Camera.h"
#include "CImg.h"
#include <cstdio>
#include<vector>
#include"Plane.h"
#include "Triangle.h"
#include <string>
#include <fstream>
#include "Light.h"
#include <array>
#include "BoundingBox.h"
#include <time.h>
using namespace cimg_library;
using namespace std;


CImg<int> img("pattern2.bmp");
	BoundingBox box(Point3D(-3, 0, 11), Point3D(4, 6, 17));

	RGBColor rayTrace(Ray &ray, int recursion, vector<GeometricObject *> &objectVec, Point3D &min, Point3D &max){
	//Vector of light sources
	vector<Light *> lights;
	lights.push_back(new Light(Point3D(0, 10, -1), RGBColor(255, 255, 255)));
	
	//set to true if using bounding box
	bool usingboundingBox = false;
	//recursion limit
	double recursionlimit = 5;
	float gAmbient = 0.1;
	RGBColor col(0, 0, 0);
	double rR = 0;
	double rG = 0;
	double rB = 0;
	double rR2 = 0;
	double rG2 = 0;
	double rB2 = 0;
	double rR3 = 0;
	double rG3 = 0;
	double rB3 = 0;

	if (recursion > recursionlimit){
		return col;
	}
	//check if ray has hit bounding box
	BoundingBox box(min, max);
	float t = box.intersect(ray);
	if (box.intersect(ray) != -1|| !usingboundingBox){
		int closest;
		double sphereDist = 100;
		bool intersected = false;
		double intersectionDist;

		//find closest intersection if any
		for (int i = 0; i < objectVec.size(); i++){
			intersectionDist = objectVec[i]->intersection(ray);
			if ((sphereDist > intersectionDist) && (intersectionDist != -1)){
				intersected = true;
				sphereDist = intersectionDist;

				closest = i;
			}

		}




		if (intersected == true){


			Point3D pi = ray.o + ray.d* sphereDist;
			//get object texture colour
			RGBColor textureCol = objectVec[closest]->getTexture(pi, img);

			//ambient = coefficient, object color * light
			if (objectVec[closest]->hasTexture()){
				 rR = +gAmbient*(textureCol.r / 255) * 1;
				 rG = +gAmbient*(textureCol.g / 255) * 1;
				 rB = +gAmbient*(textureCol.b / 255) * 1;

			}
			else{
				rR = +gAmbient*(objectVec[closest]->getR() / 255) * 1;
				rG = +gAmbient*(objectVec[closest]->getG() / 255) * 1;
				rB = +gAmbient*(objectVec[closest]->getB() / 255) * 1;
			}


			//calculate normal
			Vector3D N = objectVec[closest]->getNormal(pi);
			N.norm();
			const double ERR = 0.0001;
			Vector3D N2 = N*ERR;

			//repeat for each light source
			for (int i = 0; i < lights.size(); i++){

				Vector3D L = lights[i]->location - pi;
				L.normalize();
				double dot = objectVec[closest]->getNormal(pi)*L;
				Vector3D R = ray.d - N * (2 * (ray.d*N));

				//calculate shadows
				float shade = 1.0f;
				Ray shadeRay(pi + L*ERR, L);
				double intersectionDist2 = 0;
				
				for (int i = 0; i < objectVec.size(); i++){
					intersectionDist2 = objectVec[i]->intersection(shadeRay);
					if (intersectionDist2 > 0){
						shade = 0;
						break;
					}
				}
				//diffuse reflection
				if (dot > 0){

					double diff = dot * objectVec[closest]->getDiff();
					if (objectVec[closest]->hasTexture()){
						rR += ((diff*(textureCol.r / 255)) * 0.1)*shade;
						rG += ((diff*(textureCol.g / 255)) * 0.1)*shade;
						rB += ((diff*(textureCol.b / 255)) * 0.1)*shade;
					}
					else{
						rR += ((diff*(objectVec[closest]->getR() / 255))*0.1)*shade;
						rG += ((diff*(objectVec[closest]->getG() / 255))*0.1)*shade;
						rB += ((diff*(objectVec[closest]->getB() / 255))*0.1)*shade;
					}
				}
				//specular reflection
				if (dot > 0){
					Vector3D Lspec = lights[i]->location - pi;
					Lspec.norm();
					Vector3D specN = objectVec[closest]->getNormal(pi);
					specN.normalize();
					Vector3D specR = Lspec - specN * (2 * (Lspec*specN));
					Vector3D specV = ray.d;
					float specDot = specV*specR;
					if (specDot > 0){
						float spec = powf(specDot, 50.0);
						rR += spec * objectVec[closest]->getSpec() * shade;
						rG += spec * objectVec[closest]->getSpec() * shade;
						rB += spec * objectVec[closest]->getSpec() * shade;

					}
				}
			}



			//reflection
			if (recursion < recursionlimit&&objectVec[closest]->getRef()>0){

				Vector3D R = ray.d - N * (2 * (ray.d*N));
				RGBColor refCol(0, 0, 0);

				Ray refRay(pi + N2, R);
				refCol = rayTrace(refRay, recursion + 1, objectVec, min, max);

				if (objectVec[closest]->hasTexture()){
					rR2 += objectVec[closest]->getRef()*(refCol.r / 255)*(textureCol.r / 255);
					rG2 += objectVec[closest]->getRef()*(refCol.g / 255)*(textureCol.g / 255);
					rB2 += objectVec[closest]->getRef()*(refCol.b / 255)*(textureCol.b / 255);
				}
				else{
					rR2 += objectVec[closest]->getRef()*(refCol.r / 255)*(objectVec[closest]->getR() / 255);
					rG2 += objectVec[closest]->getRef()*(refCol.g / 255)*(objectVec[closest]->getG() / 255);
					rB2 += objectVec[closest]->getRef()*(refCol.b / 255)*(objectVec[closest]->getB() / 255);
				}

			}

			rR += rR2;
			rG += rG2;
			rB += rB2;


			//ensure color is in bounds
			if (rR > 1){ rR = 1; };
			if (rG > 1){ rG = 1; };
			if (rB > 1){ rB = 1; };
			//0-255 is expected
			col.r = (rR * 255);
			col.g = (rG * 255);
			col.b = (rB * 255);
			


		}else{//return background color
	return(RGBColor(200, 200, 200));
}
	}
	else{
	return(RGBColor(200, 200, 200));
}
	
		
		

	return col;

}


int _tmain(int argc, _TCHAR* argv[])
{
	//number of pixels in scene
	const int w = 800, h = 600;

	clock_t start;//clock
	double duration;
	start = clock();

	//Vector containing scene objects
	vector<GeometricObject *> objectVec;
		//location,radius,color,reflectivity, diffuse, texture true or false
	objectVec.push_back(new Sphere(Point3D(7, 3, 14), 3, RGBColor(150, 20, 20), 0.2, 1,0.6,false));
	objectVec.push_back(new Sphere(Point3D(0, 3, 14), 3, RGBColor(190, 190, 190), 0.2, 1,0.6, false));
	objectVec.push_back(new Sphere(Point3D(-7, 3, 14), 3, RGBColor(150, 20, 20), 0.2, 1,0.6, false));

	objectVec.push_back(new Plane(Point3D(0, 0, 0), Vector3D(0, 1, 0), RGBColor(0, 0, 0), 0.2, 0.6,1.7));

	//camera. First point is position, second is point to look at
	Camera cam(Point3D(0.0, 4.0, -10.0), Point3D(0.0, 1.0, 2.0), w, h);
	//bounds of scene used for bounding box
	double minx = 0;
	double maxx = 0;
	double miny = 0;
	double maxy = 0;
	double minz = 0;
	double maxz = 0;




	/* Code to read in triangles from text files

	vector<float> words;
	float tempString; 
	double x[1177]; 
	double y[1177];
	double z[1177];
	std::ifstream fin("teapotx.txt");
	for (int i = 0; (fin >> tempString) && (i < 1177); ++i){
		x[i] = tempString;
	} 
	fin.close();
	std::ifstream fin3("teapoty.txt");
	for (int i = 0; (fin3 >> tempString) && (i < 1177); ++i){
		y[i] = tempString;
	} 
	fin.close();
	std::ifstream fin4("teapotz.txt");
	for (int i = 0; (fin4 >> tempString) && (i < 1177); ++i){
		z[i] = tempString;
	} 
	fin.close();

	const int FACESIZE = 2256*3;
	vector<float> words2;
	double str2; 
	std::cout << "Read Vertices2" << std::endl;

	std::ifstream fin2("teapotfaces.txt");
	for (int i = 0; (fin2 >> str2) && (i < FACESIZE); ++i){                  
		words2.push_back(str2);
	}
	fin2.close();

	int count2 = 0;
	vector<int> p0;
	vector<int> p1;
	vector<int> p2;

	for (int i = 0; i < FACESIZE; i += 3){
		p0.push_back(words2[i]);
		p1.push_back(words2[i + 1]);
		p2.push_back(words2[i + 2]);
		count2++;
	}
	for (int i = 0; i < 2256; i++){
		objectVec.push_back(new Triangle(RGBColor(0, 200, 200), Point3D(x[p2[i]], y[p2[i]], z[p2[i]]), Point3D(x[p1[i]], y[p1[i]], z[p1[i]]), Point3D(x[p0[i]], y[p0[i]], z[p0[i]])));
	}
	std::cout << "generated triangles"<< std::endl;
	
	for (int i = 0; i < 1177; i++){
		if(x[i]<minx){
			minx = x[i];}
		if (x[i]>maxx){
			maxx = x[i];}

		if (y[i]<miny){
			miny = y[i];}
		if (y[i]>maxy){
			maxy = y[i];}
		if (z[i]<minz){
			minz = z[i];
		}
		if (z[i]>maxz){
			maxz = z[i];}
	}
	double xpos = (minx + maxx) / 2;
	double ypos = (miny + maxy) / 2;
	*/



	
	//delete old file 
	remove("file.bmp");
	CImg<float> image(w, h, 1, 3, 0); 
	



	



	//iterate through all pixels in scene
	for (int x = 0; x <= w; x++){
		for (int y = 0; y <= h; y++){
			RGBColor col(0, 0, 0);
			//create ray
			Ray ray = cam.makeCamRay(x,y);
			ray.d.normalize();
			//cast ray
			col = rayTrace(ray, 1, objectVec, Point3D(minx, miny, minz), Point3D(maxx, maxy, maxz));

			//draw pixel colour
			float color[] = {
				(col.r),
				(col.g),
				(col.b) };
			image.draw_point(x, y, color);

		}
		
	}	
	//get the total time elapsed and print stats
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Number of objects: " << objectVec.size() << endl;
	cout << "Time taken: "<<duration <<endl;
	std::cout << "Saving image";
	image.save("file.bmp");//save image
	CImgDisplay local(image, "Ray Tracer", 0);
	
	std::cin.get();

	

}