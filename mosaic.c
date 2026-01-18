
#include "filters.h"
void filter_mosaic(Image *img,void *pp){
    BlockParams *p=pp; int K=p->block;
    for(int y=0;y<img->height;y+=K)for(int x=0;x<img->width;x+=K){
        long sr=0,sg=0,sb=0,c=0;
        for(int j=0;j<K;j++)for(int i=0;i<K;i++)
            if(x+i<img->width && y+j<img->height){
                Pixel q=get_pixel(img,x+i,y+j);
                sr+=q.r; sg+=q.g; sb+=q.b; c++;
            }
        Pixel a={sr/c,sg/c,sb/c};
        for(int j=0;j<K;j++)for(int i=0;i<K;i++)
            if(x+i<img->width && y+j<img->height)
                set_pixel(img,x+i,y+j,a);
    }
}
