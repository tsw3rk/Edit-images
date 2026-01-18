
#include "filters.h"
void filter_edge(Image *img,void *pp){
    EdgeParams *p=pp;
    filter_grayscale(img,NULL);
    int k[3][3]={{0,-1,0},{-1,4,-1},{0,-1,0}};
    Image *c=create_image(img->width,img->height);
    for(int i=0;i<img->width*img->height;i++) c->data[i]=img->data[i];

    for(int y=0;y<img->height;y++)for(int x=0;x<img->width;x++){
        int s=0;
        for(int j=-1;j<=1;j++)for(int i=-1;i<=1;i++){
            Pixel q=get_pixel(c,x+i,y+j);
            s+=q.r*k[j+1][i+1];
        }
        uint8_t v=(s/255.0>p->t)?255:0;
        Pixel r={v,v,v};
        set_pixel(img,x,y,r);
    }
    free_image(c);
}
