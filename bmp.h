
#ifndef BMP_H
#define BMP_H
#include "image.h"
Image *read_bmp(const char *path);
int write_bmp(const char *path,const Image *img);
#endif
