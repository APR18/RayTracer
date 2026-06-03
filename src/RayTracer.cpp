#include <iostream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

double hit_sphere(const Point3& center, double radius, const Ray& r)
{
	/*a = d⋅d
	b = −2d⋅(C−Q)
	c = (C−Q)⋅(C−Q)−r2*/
	Vec3 oc = center - r.origin();					// this is (C − Q)
	auto a = r.direction().length_squared();		// d·d  = |d|²
	auto h = dot(r.direction(), oc);				// d·(C − Q)   (was b/−2)
	auto c = oc.length_squared() - radius * radius; // (C−Q)·(C−Q) − r²
	//Discriminant: b² − 4ac	
	auto discriminant = h*h - ( a * c);				 // h² − ac   (was b²−4ac, /4)


	if (discriminant < 0)
	{
		return -1.0;								// missed → sentinel value
	}
	else {
		(h - std::sqrt(discriminant)) / a;
	}

}
color ray_color(const Ray& r)
{
	Point3 center = Point3(0, 0, -1);
	auto t = hit_sphere(center, 0.5, r);
	if (t > 0.0)
	{
		Vec3 normal = unit_vector(r.at(t) - center);
		return 0.5 * color(normal.x()+1, normal.y() + 1, normal.z() + 1);
	}
	
	
	Vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5 * (unit_direction.y() + 1.0);
	return (1 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}
int main()
{

	//Image
	auto aspect_ratio = 16.0 / 9.0;
	int image_width = 400;

	// calculating image height using image width so that 
	// the aspect ration remains the same no matter the case
	int image_height = int(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (double(image_width)/image_height);
	auto camera_center = Point3(0, 0, 0);

	auto viewport_u = Vec3(viewport_width, 0, 0);
	auto viewport_v = Vec3(0, -viewport_height, 0);

	//  horizontal and vertical delta of vectors from pixel to pixel.
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	/*start from the camera we move  forward to view port center and from their we move 
	left ot reach viewport edge and then we move up from there to upper corner*/
	
	auto viewport_upper_left = camera_center - Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int j = 0; j < image_height; j++)
	{
		std::clog << "\rScanlines remaining: " << image_height - j << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			//now we find the center of each pixel in the image 
			auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			// getting the direction from camera to that pixel
			auto ray_direction = pixel_center - camera_center;
			// creating a ray that starts from camera to that direction 
			Ray r(camera_center, ray_direction);
			
			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}
	std::clog << "\rDone.               \n";
}