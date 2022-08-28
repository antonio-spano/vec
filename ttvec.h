#ifndef VEC
#define VEC

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct
{
	void** vec;
	int typeSize;
	int size;
} Vec;

#define vecNew() \
({ \
	Vec vec; \
	vec.size = 0; \
	vec; \
})

#define vecGetElem(vect, index, type) \
({ \
	(*(type*)vect.vec[index]); \
})

///used by the API! I advise you user not to use it.
void vecAlloc(Vec* vect, int typeSize);
///used by the API! I advise you user not to use it.
void vecResize(Vec* vect, int newSize);

void vecPush(Vec* vect, void* arg);

void vecPop(Vec* vect, void* arg);

void vecFree(int n, ...);

#endif
