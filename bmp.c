
#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push,1)
typedef struct{uint16_t t;uint32_t s;uint16_t r1,r2;uint32_t off;} BMPH;
typedef struct{uint32_t sz;int32_t w,h;uint16_t pl,b;uint32_t c,isz;int32_t x,y;uint32_t u,i;} DIBH;
#pragma pack(pop)

Image *read_bmp(const char *p){
    FILE *f=fopen(p,"rb"); if(!f) return NULL;
    BMPH bh; DIBH dh;
    fread(&bh,1,sizeof(bh),f);
    fread(&dh,1,sizeof(dh),f);
    if(dh.b!=24){ fclose(f); return NULL; }

    Image *img=create_image(dh.w,abs(dh.h));
    int pad=(4-(img->width*3)%4)%4;

    for(int y=img->height-1;y>=0;y--){
        for(int x=0;x<img->width;x++){
            Pixel p;
            fread(&p.b,1,1,f); fread(&p.g,1,1,f); fread(&p.r,1,1,f);
            set_pixel(img,x,y,p);
        }
        fseek(f,pad,SEEK_CUR);
    }
    fclose(f); return img;
}

int write_bmp(const char *p,const Image *img){
    FILE *f=fopen(p,"wb"); if(!f) return 0;
    int pad=(4-(img->width*3)%4)%4;
    int ds=(img->width*3+pad)*img->height;

    BMPH bh={0x4D42,54+ds,0,0,54};
    DIBH dh={40,img->width,img->height,1,24,0,ds,0,0,0,0};
    fwrite(&bh,1,sizeof(bh),f);
    fwrite(&dh,1,sizeof(dh),f);

    uint8_t z[3]={0,0,0};
    for(int y=img->height-1;y>=0;y--){
        for(int x=0;x<img->width;x++){
            Pixel p=get_pixel(img,x,y);
            fwrite(&p.b,1,1,f); fwrite(&p.g,1,1,f); fwrite(&p.r,1,1,f);
        }
        fwrite(z,1,pad,f);
    }
    fclose(f); return 1;
}
