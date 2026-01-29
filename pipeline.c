
#include "pipeline.h"
void apply_pipeline(Image *img,Filter *f,int n){
    for(int i=0;i<n;i++) f[i].apply(img,f[i].params);
}
