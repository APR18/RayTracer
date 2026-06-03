#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"

class HitRecord 
{
public: 
	point3 p;
	vec3 normal;
	double t;
};

class Hittable
{
public: 
	virtual ~Hittable() = default;
	virtual bool hit(const Ray & r, double rayTmin, double rayTmax, HitRecord & rec) const = 0;

};
#endif
