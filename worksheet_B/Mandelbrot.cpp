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

	int max_iteration = 1000;
	int iteration = 0;

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// TODO: Map the y coordinate into the range minY to maxY
		//double y0 =
		double y0 = (maxY - minY) * (pixelY * 800) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			//double x0 =

			double x0 = (maxX - minX) * (pixelX * 800) + minX;

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels
			int x = pixelX + 1;
			x = (pixelX*pixelX) - (pixelY*pixelY) - y0;
			int y = pixelY + 1;
			y = (2 * pixelX * pixelY) + y0;
			
			int colour;
			colour = (pixelX*pixelX) + (pixelY*pixelY);

			int r = 255, g = 255, b = 255;

			int H = iteration, S = 1, V = 1;
			void hsv2rgb(H, S, V)
			{
				double r, g, b;

				double i = floor(H * 6);
				double f = H * 6 - i;
				double p = V * (1 - S);
				double q = V * (1 - f * S);
				double t = V * (1 - (1 - f) * S)

					switch (i % 6)
					{
					case 0: r = V, g = t, b = p; break;
					case 1: r = q, g = V, b = p; break;
					case 2: r = p, g = V, b = t; break;
					case 3: r = p, g = q, b = V; break;
					case 4: r = t, g = p, b = V; break;
					case 5: r = V, g = p, b = q; break;
					}
			}
			if (iteration == max_iteration) 
			{
				r = 0;
				g = 0;
				b = 0;
			}

			// Write the pixel
			// TODO: change the right-hand side of these three lines to write the desired pixel colour value
			image(pixelX, pixelY, 0, 0) = r; // red component
			image(pixelX, pixelY, 0, 1) = g; // green component
			image(pixelX, pixelY, 0, 2) = b; // blue component
			iteration++;
		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		display.display(image);
	}

	// Display the complete image
	display.display(image);

	// Uncomment this line to save the image to disk
	//image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}
