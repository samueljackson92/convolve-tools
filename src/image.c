#include <stdlib.h>
#include <stdio.h>

#include "image.h"

Image* create_image_from_shape(Image* original) {
    return create_image_from_size(original->height, original->width);
}

Image* create_image_from_size(int height, int width) {
    Image* new = malloc(sizeof(Image));
    new->height = height;
    new->width = width;

    new->data = malloc(height * width * sizeof(double*));
    for (int i = 0; i < height * width; i++) {
            new->data[i] = 0;
    }

    return new;
}

Image* create_image_from_array(double* data, int height, int width) {
    Image* img = malloc(sizeof(Image));
    img->data = data;
    img->height = height;
    img->width = width;
    return img;
}

inline double get_pixel(Image* img, int i, int j) {
    return img->data[i*img->height+j];
}

inline void set_pixel(Image* img, int i, int j, double value) {
    img->data[i*img->height+j] = value;
}

void print_image(Image* img) {
    for (int i = 0; i < img->height; i++){
        for (int j = 0; j < img->width; j++){
            printf("%.2f ", get_pixel(img, i, j));
        }
        printf("\n");
    }
}

void free_image(Image* img) {
    free(img->data);  //free the pixel data.
    img->data = NULL;
    free(img);  //free the image struct itself
    img = NULL;
}
