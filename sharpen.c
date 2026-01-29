
#include "filters.h"
void filter_sharpen(Image *img,void *p){
    int k[3][3]={{0,-1,0},{-1,5,-1},{0,-1,0}};
    Image *c=create_image(img->width,img->height);
    for(int i=0;i<img->width*img->height;i++) c->data[i]=img->data[i];

    for(int y=0;y<img->height;y++)for(int x=0;x<img->width;x++){
        int sr=0,sg=0,sb=0;
        for(int j=-1;j<=1;j++)for(int i=-1;i<=1;i++){
            Pixel p=get_pixel(c,x+i,y+j);
            int w=k[j+1][i+1];
            sr+=p.r*w; sg+=p.g*w; sb+=p.b*w;
        }
        Pixel q={sr<0?0:sr>255?255:sr,
                 sg<0?0:sg>255?255:sg,
                 sb<0?0:sb>255?255:sb};
        set_pixel(img,x,y,q);
    }
    free_image(c);
}
