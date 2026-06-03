#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
class Sphere : public Hittable
{
public:
	Sphere(const Point3& center,double radius) : center(center),radius(std::fmax(0,radius)){}
	bool hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const override
	{
		/*a = d?d
		b = ?2d?(C?Q)
		c = (C?Q)?(C?Q)?r2*/
		Vec3 oc = center - r.origin();					// this is (C ? Q)
		auto a = r.direction().length_squared();		// d·d  = |d|²
		auto h = dot(r.direction(), oc);				// d·(C ? Q)   (was b/?2)
		auto c = oc.length_squared() - radius * radius; // (C?Q)·(C?Q) ? r²
		//Discriminant: b² ? 4ac	
		auto discriminant = h * h - (a * c);				 // h² ? ac   (was b²?4ac, /4)


		if (discriminant < 0)
		{
			return false;								// missed ? sentinel value
		}
		auto sqrtd = std::sqrt(discriminant);
	}

private:
	Point3 center;
	double radius;
};
#endif