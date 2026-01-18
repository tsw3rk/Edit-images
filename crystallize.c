
#include "filters.h"
void filter_crystallize(Image *img,void *pp){
    BlockParams *p=pp;
    int K=p->block;
    for(int y=0;y<img->height;y+=K)for(int x=0;x<img->width;x+=K){
        Pixel q=get_pixel(img,x,y);
        for(int j=0;j<K;j++)for(int i=0;i<K;i++)
            if(x+i<img->width && y+j<img->height)
                set_pixel(img,x+i,y+j,q);
    }
}
