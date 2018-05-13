#ifndef __GC_H__
#define __GC_H__

#include "object.h"

typedef struct gc_mem
{
    char mark;
    object * object_value;
    unsigned int next;
} gc_mem;

typedef struct gc
{
    unsigned int free;
    unsigned int mem_size;
    gc_mem * mem;
} gc;

gc * gc_new(unsigned int mem_size);
void gc_delete(gc * collector);

void gc_mark_vec(gc * collector, unsigned int index);
void gc_mark(gc * collector, unsigned int index);
void gc_mark_access(gc * collector, unsigned int * omfalos, unsigned int size);
void gc_run(gc * collector, unsigned int * omfalos, unsigned int size);

unsigned int gc_alloc_int(gc * collector, int value);
unsigned int gc_alloc_vec(gc * collector, unsigned int size);
unsigned int gc_alloc_func(gc * collector, unsigned int vec, unsigned int addr);

#endif /* __GC_H__ */

