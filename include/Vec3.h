#ifndef VEC3_H
#define  VEC3_H

#include <iostream>
#include <cmath>
class Vec3 
{
public:
	double e[3];

	Vec3() : e{ 0,0,0 }
	{

	}

	Vec3(double e1, double e2, double e3) : e{ e1,e2,e3 }
	{

	}

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	Vec3 operator-()const { return Vec3(-e[0], -e[1], -e[2]); }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	Vec3& operator+=(Vec3& v)
	{
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		// *this means reference of this class
		return *this;
	}

	Vec3& operator*=(double t)
	{
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	Vec3& operator/=(double t)
	{
		return *this *= 1/t;
	}

	double length() const
	{
		return std::sqrt(length_squared());
	}
	double length_squared() const 
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	// point3 is just an alias for vec3
	// we are just using this for clarity of code
	using point3 = Vec3;

	inline std::ostream& operator<<(std::ostream& stream, const Vec3& v)
	{
		return stream << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
	}



};
#endif // !VEC3_H
