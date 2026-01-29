
#ifndef FILTERS_H
#define FILTERS_H
#include "image.h"

void filter_grayscale(Image*,void*);
void filter_negative(Image*,void*);
void filter_crop(Image*,void*);
void filter_sharpen(Image*,void*);
void filter_edge(Image*,void*);
void filter_median(Image*,void*);
void filter_blur(Image*,void*);
void filter_glass(Image*,void*);
void filter_crystallize(Image*,void*);
void filter_mosaic(Image*,void*);

typedef struct{int w,h;} CropParams;
typedef struct{float t;} EdgeParams;
typedef struct{int win;} MedianParams;
typedef struct{float sigma;} BlurParams;
typedef struct{int block;} BlockParams;

#endif
