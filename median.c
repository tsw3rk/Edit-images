
#include "filters.h"
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(uint8_t*)a-*(uint8_t*)b;}
void filter_median(Image *img,void *pp){
    MedianParams *p=pp;
    int w=p->win, r=w/2, n=w*w;
    Image *c=create_image(img->width,img->height);
    for(int i=0;i<img->width*img->height;i++) c->data[i]=img->data[i];

    uint8_t R[225],G[225],B[225];
    for(int y=0;y<img->height;y++)for(int x=0;x<img->width;x++){
        int t=0;
        for(int j=-r;j<=r;j++)for(int i=-r;i<=r;i++){
            Pixel q=get_pixel(c,x+i,y+j);
            R[t]=q.r; G[t]=q.g; B[t]=q.b; t++;
        }
        qsort(R,n,1,cmp); qsort(G,n,1,cmp); qsort(B,n,1,cmp);
        Pixel m={R[n/2],G[n/2],B[n/2]};
        set_pixel(img,x,y,m);
    }
    free_image(c);
}
