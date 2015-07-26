/*
Modified LoG filter.

Convolves an image and a mask with a modified LoG filter that removes the strong
edge response produced by the boundary of the mask.
*/


/*! \brief Stores a 2D array of doubles representing a greyscale image along with
additional meta information about the image.
*/
typedef struct image_struct {
    double** data;        ///< the 2D array of image data.
    int height;  ///< the number of pixels along the 1st axis.
    int width;   ///< the number of pixels along the 2nd axis.
} image;


/*! \brief Perform 2D image convolution.

\param input The image to convolve with the kernel.
\param kernel The kernel to convolve with the image.
\param output Image struct to store the output of convolution in.
*/
void convolve(image* input, image* kernel, image* output);

/*! \brief Create a new image with the same dimensions as another image.
This will also initialise the image data to 0.

\param other Image defining the shape of the new image.
\return A new image with the shape shape.
*/
image* create_image_from_shape(image* other);

/*! \brief Create a new image with the given dimensions
This will also initialise the image data to 0.

\param height The height of the image.
\param width The width of the image.
\return A new image with the given dimensions.
*/
image* create_image_from_size(int height, int width);

/*! \brief Print an image to the console.
\param img The image to print.
*/
void print_image(image* img);

/*! \brief Free a pointer to an image struct.
\param img The image to free.
*/
void free_image(image* img);
