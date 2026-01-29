
#include "filters.h"
#include <math.h>
void filter_blur(Image *img,void *pp){
    BlurParams *p=pp;
    int r=(int)(3*p->sigma);
    int sz=2*r+1;
    float k[49]; float sum=0;
    for(int i=0;i<sz;i++)for(int j=0;j<sz;j++){
        int dx=i-r, dy=j-r;
        float v=exp(-(dx*dx+dy*dy)/(2*p->sigma*p->sigma));
        k[i*sz+j]=v; sum+=v;
    }
    for(int i=0;i<sz*sz;i++) k[i]/=sum;

    Image *c=create_image(img->width,img->height);
    for(int i=0;i<img->width*img->height;i++) c->data[i]=img->data[i];

    for(int y=0;y<img->height;y++)for(int x=0;x<img->width;x++){
        float sr=0,sg=0,sb=0;
        for(int j=0;j<sz;j++)for(int i=0;i<sz;i++){
            Pixel q=get_pixel(c,x+i-r,y+j-r);
            float w=k[j*sz+i];
            sr+=q.r*w; sg+=q.g*w; sb+=q.b*w;
        }
        Pixel o={sr,sg,sb};
        set_pixel(img,x,y,o);
    }
    free_image(c);
}
