/**
 * Document: MaxCompiler Training (maxcompiler-training.pdf)
 * Chapter: 2
 * Exercise Solution: 2
 * Summary:
 * 	 Performs SobelSolution edge detection on an image.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

#include "ppmIO.h"

int main(void)
{
    struct timeval t0;
    struct timeval t1;
    gettimeofday(&t0, 0);
	printf("Loading image.\n");
	int32_t *inImage;
	int width = 0, height = 0;
	loadImage("lena.ppm", &inImage, &width, &height, 1);

	int dataSize = width * height * sizeof(int);
	// Allocate a buffer for the output image
	int32_t *outImage = malloc(dataSize);

	printf("Running Kernel.\n");
	SobelSolution(width * height, inImage, outImage);

	printf("Saving image.\n");
	writeImage("lena_sobel.ppm", outImage, width, height, 1);

	printf("Exiting\n");
	gettimeofday(&t1, 0);
	long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	printf("%lu\n", elapsed);
	return 0;
}
