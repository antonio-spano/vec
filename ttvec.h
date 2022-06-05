#ifndef TTVEC
#define TTVEC

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct
{
	void** vec;
	int typeSize;
	int size;
} Ttvec;

#define ttNew() \
({ \
	Ttvec vec; \
	vec.size = 0; \
	vec; \
})

#define ttGetElem(vect, index, type) \
({ \
	(*(type*)vect.vec[index]); \
})

///used by the API! I advise you user not to use it.
void ttAlloc(Ttvec* vect, int typeSize);
///used by the API! I advise you user not to use it.
void ttResize(Ttvec* vect, int newSize);

void ttPush(Ttvec* vect, void* arg);

void ttPop(Ttvec* vect, void* arg);

void ttVecFree(int n, ...);

#endif
