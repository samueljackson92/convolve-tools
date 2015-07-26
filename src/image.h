
#ifndef IMAGE_H
#define IMAGE_H

/*
Defines an Image datatype and corresponding manipulation functions.
*/

/*! \brief Stores a 2D array of doubles representing a greyscale image along with
additional meta information about the image.
*/
typedef struct image_struct {
    double** data;        ///< the 2D array of image data.
    int height;  ///< the number of pixels along the 1st axis.
    int width;   ///< the number of pixels along the 2nd axis.
} Image;

/*! \brief Create a new image with the same dimensions as another image.
This will also initialise the image data to 0.

\param other Image defining the shape of the new image.
\return A new image with the shape shape.
*/
Image* create_image_from_shape(Image* other);

/*! \brief Create a new image with the given dimensions
This will also initialise the image data to 0.

\param height The height of the image.
\param width The width of the image.
\return A new image with the given dimensions.
*/
Image* create_image_from_size(int height, int width);

/*! \brief Print an image to the console.
\param img The image to print.
*/
void print_image(Image* img);

/*! \brief Free a pointer to an image struct.
\param img The image to free.
*/
void free_image(Image* img);

#endif
