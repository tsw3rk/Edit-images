
#include "image.h"
void filter_grayscale(Image *img,void *p){
    for(int y=0;y<img->height;y++)for(int x=0;x<img->width;x++){
        Pixel px=get_pixel(img,x,y);
        uint8_t g=0.299*px.r+0.587*px.g+0.114*px.b;
        Pixel q={g,g,g}; set_pixel(img,x,y,q);
    }
}
