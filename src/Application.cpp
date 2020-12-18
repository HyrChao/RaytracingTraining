
#include <iostream>
#include <fstream>

#include "color.h"
#include "vector3.h"

static int screenWidth = 256;
static int screenHeight = 256;


int main()
{
	std::ofstream file("Output.ppm");

	file << "P3\n" << screenWidth << " " << screenHeight << "\n255\n";

	for (int v = screenHeight; v > 0; v--)
	{
		// Progress indicator
		std::cout << "\rScanlines remaining: " << v << ' ' << std::flush;
		for (int u = 0; u<screenWidth ; u++)
		{
			double r = double(u) / (screenWidth - 1);
			double g = double(v) / (screenHeight - 1);
			double b = 0.25;
			color pixelColor = color(r, g, b);
			
			write_color(file, pixelColor);
		}
	}
	std::cout << "\nDone.\n";
	file.close();
	std::cout << "Opening output file, please wait...";
	system("Output.ppm");
}