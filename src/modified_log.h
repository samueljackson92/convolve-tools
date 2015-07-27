/*
Modified LoG filter.

Convolves an image and a mask with a modified LoG filter that removes the strong
edge response produced by the boundary of the mask.
*/


#ifndef MODIFIED_LOG_H
#define MODIFIED_LOG_H

#include "image.h"

/*! \brief Perform 2D image convolution.

\param input The image to convolve with the kernel.
\param kernel The kernel to convolve with the image.
\param output Image struct to store the output of convolution in.
*/
void convolve(Image* input, Image* kernel, Image* output);

/*! \brief Python interface to the convolution function

\param in The image to convolve with the kernel.
\param kernel The kernel to convolve with the input image.
\param out The array to store the output of convolution in.
\param height The height of the image.
\param width The width of the image.
\param kernel_height The height of the kernel.
\param kernel_width The width of the kernel.
*/
void convolve_py(double* in, double* kern, double* out,
        int height, int width, int kernel_height, int kernel_width);

#endif
