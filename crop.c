
#include "filters.h"
#include <stdlib.h>
void filter_crop(Image *img,void *p){
    CropParams *c=p;
    int w=c->w<img->width?c->w:img->width;
    int h=c->h<img->height?c->h:img->height;
    Pixel *n=calloc(w*h,sizeof(Pixel));
    for(int y=0;y<h;y++)for(int x=0;x<w;x++)
        n[y*w+x]=get_pixel(img,x,y);
    free(img->data);
    img->data=n; img->width=w; img->height=h;
}
