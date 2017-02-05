// Mandelbrot.cpp : Defines the entry point for the console application.
//

/* while (x*x + y*y < 2*2  AND  iteration < max_iteration) {
    xtemp = x*x - y*y + x0
    y = 2*x*y + y0
    x = xtemp
    iteration = iteration + 1 
*/

#include "stdafx.h"
#include <math.h>

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// TODO: Map the y coordinate into the range minY to maxY
		double y0 = (pixelY / 800.0) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			double x0 = (pixelX / 800.0) * (maxX - minX) + minX;
			double xStore = 0;
			int iteration = 0;
			int maxIteration = 200;
			double yStore = 0;

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels


			while (iteration < maxIteration && xStore * xStore + yStore * yStore < 6)
			{
				double xTemp = xStore * xStore - yStore * yStore + x0;
				yStore = 2 * xStore * yStore + y0;
				xStore = xTemp;
				iteration++;
			}

			// Write the pixel
			// TODO: change the right-hand side of these three lines to write the desired pixel colour value
			int Red = 0;
			int Green = 0;
			int Blue = 0;

			if (iteration <= 0)
			{
				Red = 255;
			}

			else if (iteration <= 60)
			{
				Red = 255;
				Blue = 255 * (iteration / 16);
			}

			else if (iteration <= 120)
			{
				Red = 255;
				Green = 255;
			}

			else if (iteration <= 180)
			{
				Green = 255;
				Blue = 255;
			}

			else if (iteration <= 199)
			{
				Red = 125;
				Blue = 124;
				Green = 124;
			}
			else
			{
				Red = 0;
				Blue = 0;
				Green = 0;
			}

			image(pixelX, pixelY, 0, 0) = Red; // red component
			image(pixelX, pixelY, 0, 1) = Green; // green component
			image(pixelX, pixelY, 0, 2) = Blue; // blue component

		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		display.display(image);
	}

	// Display the complete image
	display.display(image);

	// Uncomment this line to save the image to disk
	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}