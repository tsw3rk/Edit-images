
#ifndef IMAGE_H
#define IMAGE_H
#include <stdint.h>

typedef struct { uint8_t r,g,b; } Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *create_image(int w,int h);
void free_image(Image *img);

Pixel get_pixel(const Image *img,int x,int y);
void set_pixel(Image *img,int x,int y,Pixel p);

#endif
