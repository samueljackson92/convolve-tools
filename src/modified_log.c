#include <stdlib.h>
#include <stdio.h>

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
                        output->data[i][j] += input->data[ii][jj] * kernel->data[mm][nn];
                    }
                }
            }
        }
    }
}

Image* create_image_from_shape(Image* original) {
    Image* new = create_image_from_size(original->height, original->width);
    return new;
}

Image* create_image_from_size(int height, int width) {
    Image* new = malloc(sizeof(Image));
    new->height = height;
    new->width = width;

    new->data = malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++) {
        new->data[i] = malloc(width * sizeof(double));
        for(int j = 0; j < width; j++) {
            new->data[i][j] = 0;
        }
    }

    return new;
}

void print_image(Image* img) {
    for (int i = 0; i < img->height; i++){
        for (int j = 0; j < img->width; j++){
            printf("%.2f ", img->data[i][j]);
        }
        printf("\n");
    }
}

void free_image(Image* img) {
    //free each row of image
    for (int i = 0; i < img->height; i++)
    {
        double* current_row = img->data[i];
        free(current_row);
        current_row = NULL;
    }

    free(img->data);  //free the column of pointers to rows.
    free(img);
    img = NULL;
}


int main(int argc, char** argv) {
    Image* img = create_image_from_size(10,10);
    Image* out = create_image_from_shape(img);
    img->data[5][5] = 10;

    Image* kernel = create_image_from_size(5, 5);
    kernel->data[2][2] = 10;

    convolve(img, kernel, out);
    print_image(out);

    free_image(img);
    free_image(out);
    free_image(kernel);
    return 0;
}
