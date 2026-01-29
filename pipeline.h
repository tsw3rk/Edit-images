
#ifndef PIPELINE_H
#define PIPELINE_H
#include "image.h"
typedef struct{ void (*apply)(Image*,void*); void *params; } Filter;
void apply_pipeline(Image *img,Filter *f,int n);
#endif
