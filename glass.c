
#include "filters.h"
#include <stdlib.h>
void filter_glass(Image *img,void *p){
    Image *c=create_image(img->width,img->height);
    for(int i=0;i<img->width*img->height;i++) c->data[i]=img->data[i];
    for(int y=0;y<img->height;y++)for(int x=0;x<img->width;x++){
        int dx=(rand()%5)-2, dy=(rand()%5)-2;
        Pixel q=get_pixel(c,x+dx,y+dy);
        set_pixel(img,x,y,q);
    }
    free_image(c);
}
