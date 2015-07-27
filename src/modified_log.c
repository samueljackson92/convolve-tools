#include <stdlib.h>

#include "image.h"
#include "modified_log.h"

void convolve(Image* input, Image* kernel, Image* output) {
    int rows = input->height;
    int cols = input->width;

    int k_rows = kernel->height;
    int k_cols = kernel->width;

    int k_centre_x = k_cols / 2;
    int k_centre_y = k_rows / 2;

    unsigned int mm = 0;  // row index of flipped kernel
    unsigned int nn = 0;  // column index of flipped kernel

    int ii = 0;  //row index of input signal
    int jj = 0;  //col index of input signal

    for(unsigned int i = 0; i < rows; ++i)               // rows
    {
        for(unsigned int j = 0; j < cols; ++j)           // columns
        {
            for(unsigned int m = 0; m < k_rows; ++m)     // kernel rows
            {
                mm = k_rows - 1 - m;

                for(unsigned int n = 0; n < k_cols; ++n) // kernel columns
                {
                    nn = k_cols - 1 - n;

                    // index of input signal, used for checking boundary
                    ii = i + (m - k_centre_y);
                    jj = j + (n - k_centre_x);

                    // ignore input samples which are out of bound
                    if( ii >= 0 && ii < rows && jj >= 0 && jj < cols ) {
                        double current = get_pixel(output, i, j);
                        double value = get_pixel(input, ii, jj) * get_pixel(kernel, mm, nn);
                        set_pixel(output, i, j, current+value);
                    }
                }
            }
        }
    }
}

void py_convolve(double* in, double* kern, double* out,
    int height, int width, int kernel_height, int kernel_width) {

    Image* input = create_image_from_array(in, height, width);
    Image* kernel = create_image_from_array(kern, kernel_height, kernel_width);
    Image* output = create_image_from_array(out, height, width);

    convolve(input, kernel, output);
    out = output->data;

    free(input);
    free(kernel);
    free(output);
}
