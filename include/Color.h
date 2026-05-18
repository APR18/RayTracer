#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"
using color = Vec3;
void write_color(std::ostream& stream, const color& pixel_color)
{
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	/*we are multiplying it with 255 which represents them in  0-255 color space*/
	int rbyte = int(255.999 * r);
	int gbyte = int(255.999 * g);
	int bbyte = int(255.999 * b);

	stream << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif