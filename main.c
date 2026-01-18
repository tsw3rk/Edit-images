
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bmp.h"
#include "pipeline.h"
#include "filters.h"

int main(int argc,char **argv){
    if(argc<3){printf("usage: image_craft in.bmp out.bmp [filters]\n"); return 0;}
    Image *img=read_bmp(argv[1]); if(!img){printf("bmp error\n"); return 1;}

    Filter f[64]; int n=0;

    for(int i=3;i<argc;i++){
        if(!strcmp(argv[i],"-gs")) f[n++]=(Filter){filter_grayscale,NULL};
        else if(!strcmp(argv[i],"-neg")) f[n++]=(Filter){filter_negative,NULL};
        else if(!strcmp(argv[i],"-crop")){
            CropParams *p=malloc(sizeof(*p)); p->w=atoi(argv[++i]); p->h=atoi(argv[++i]);
            f[n++]=(Filter){filter_crop,p};
        }
        else if(!strcmp(argv[i],"-sharp")) f[n++]=(Filter){filter_sharpen,NULL};
        else if(!strcmp(argv[i],"-edge")){
            EdgeParams *p=malloc(sizeof(*p)); p->t=atof(argv[++i]);
            f[n++]=(Filter){filter_edge,p};
        }
        else if(!strcmp(argv[i],"-med")){
            MedianParams *p=malloc(sizeof(*p)); p->win=atoi(argv[++i]);
            f[n++]=(Filter){filter_median,p};
        }
        else if(!strcmp(argv[i],"-blur")){
            BlurParams *p=malloc(sizeof(*p)); p->sigma=atof(argv[++i]);
            f[n++]=(Filter){filter_blur,p};
        }
        else if(!strcmp(argv[i],"-glass")) f[n++]=(Filter){filter_glass,NULL};
        else if(!strcmp(argv[i],"-crystal")){
            BlockParams *p=malloc(sizeof(*p)); p->block=atoi(argv[++i]);
            f[n++]=(Filter){filter_crystallize,p};
        }
        else if(!strcmp(argv[i],"-mosaic")){
            BlockParams *p=malloc(sizeof(*p)); p->block=atoi(argv[++i]);
            f[n++]=(Filter){filter_mosaic,p};
        }
    }

    apply_pipeline(img,f,n);
    write_bmp(argv[2],img);
    free_image(img);
    return 0;
}
