
#include "image.h"
void filter_negative(Image *img,void *p){
    for(int y=0;y<img->height;y++)for(int x=0;x<img->width;x++){
        Pixel px=get_pixel(img,x,y);
        px.r=255-px.r; px.g=255-px.g; px.b=255-px.b;
        set_pixel(img,x,y,px);
    }
}
