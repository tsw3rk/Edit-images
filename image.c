
#include "image.h"
#include <stdlib.h>

static int clamp(int v,int a,int b){ return v<a?a:(v>b?b:v); }

Image *create_image(int w,int h){
    Image *img=malloc(sizeof(Image));
    img->width=w; img->height=h;
    img->data=calloc(w*h,sizeof(Pixel));
    return img;
}

void free_image(Image *img){
    free(img->data); free(img);
}

Pixel get_pixel(const Image *img,int x,int y){
    x=clamp(x,0,img->width-1);
    y=clamp(y,0,img->height-1);
    return img->data[y*img->width+x];
}

void set_pixel(Image *img,int x,int y,Pixel p){
    img->data[y*img->width+x]=p;
}
