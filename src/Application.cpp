
#include <iostream>
#include <fstream>

static int screenWidth = 256;
static int screenHeight = 256;


int main()
{
	std::ofstream file("Output.ppm");

	file << "P3\n" << screenWidth << " " << screenHeight << "\n255\n";

	for (int v = screenHeight; v > 0; v--)
	{
		std::cerr << "\rScanlines remaining: " << v << ' ' << std::flush;
		for (int u = 0; u<screenWidth ; u++)
		{
			double r = double(u) / (screenWidth - 1);
			double g = double(v) / (screenHeight - 1);
			double b = 0.25;

			int nr = static_cast<int>(r * 255.99);
			int ng = static_cast<int>(g * 255.99);
			int nb = static_cast<int>(b * 255.99);

			file << nr << " " << ng << " " << nb << "\n";
		}
	}
	std::cerr << "\nDone.\n";
	file.close();
	system("Output.ppm");
}