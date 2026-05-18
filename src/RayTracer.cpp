#include <iostream>

int main()
{
	int image_width = 255;
	int image_height = 255;

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int j = 0; j < image_height; j++)
	{
		std::clog << "\rScanlines remaining: " << image_height - j << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			/*This is normalising each value between 0.0 and 1.0. */
			auto r = double(i) / (image_width - 1);
			auto g = double(j) / (image_height - 1);
			auto b = 0.0;

			/*Then we are multiplying it with 255 which represents them in  0-255 color space*/
			int ir = int(255.999 * r);
			int ig = int(255.999 * g);
			int ib = int(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	std::clog << "\rDone.               \n";
}