#include "ttvec.h"

void ttAlloc(Ttvec* vect, int typeSize)
{
	vect->vec = calloc(1, sizeof(typeSize));
	vect->size = 1;
	vect->typeSize = sizeof(typeSize);
}

void ttResize(Ttvec* vect, int newSize)
{
	vect->vec = realloc(vect->vec, newSize * vect->typeSize);
	vect->size = newSize;
}

void ttPush(Ttvec* vect, void* arg)
{
	if (vect->size == 0)
	{
		ttAlloc(vect, sizeof(arg));
	}
	else
	{
		ttResize(vect, vect->size + 1);
	}

	vect->vec[vect->size - 1] = (void*)arg;
}

void ttPop(Ttvec* vect, void* arg)
{
	for (int i = vect->size - 1; i >= 0; i--)
	{
		if (vect->vec[i] == arg)
		{
			if (i < vect->size - 1)
			{
				for (int i = i; i < vect->size - 1; i++)
				{
					vect->vec[i] = vect->vec[i + 1];
				}
			}

			ttResize(vect, vect->size - 1);
			return;
		}
	}
}

void ttVecFree(int n, ...)
{
	va_list args;
	va_start(args, n);

	for (int i = 0; i < n; i++)
	{
		Ttvec vec = va_arg(args, Ttvec);
		free(vec.vec);
	}

	va_end(args);
}
