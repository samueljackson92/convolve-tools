#include <stdlib.h>
#include <stdio.h>

#include "image.h"

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
