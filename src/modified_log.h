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
Image* convolve(Image* input, Image* kernel);

#endif
