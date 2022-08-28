#include "vec.h"

void vecAlloc(Vec* vect, int typeSize)
{
	vect->vec = calloc(1, sizeof(typeSize));
	vect->size = 1;
	vect->typeSize = sizeof(typeSize);
}

void vecResize(Vec* vect, int newSize)
{
	vect->vec = realloc(vect->vec, newSize * vect->typeSize);
	vect->size = newSize;
}

void vecPush(Vec* vect, void* arg)
{
	if (vect->size == 0)
	{
		vecAlloc(vect, sizeof(arg));
	}
	else
	{
		vecResize(vect, vect->size + 1);
	}

	vect->vec[vect->size - 1] = (void*)arg;
}

void vecPop(Vec* vect, void* arg)
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

			vecResize(vect, vect->size - 1);
			return;
		}
	}
}

void vecFree(int n, ...)
{
	va_list args;
	va_start(args, n);

	for (int i = 0; i < n; i++)
	{
		Vec vec = va_arg(args, Vec);
		free(vec.vec);
	}

	va_end(args);
}
