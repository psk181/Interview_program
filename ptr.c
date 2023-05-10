#include <stdio.h>
#include <stdlib.h>

#if 0
int main()
{
	int k = 10;
	int *ptr = &k;

	/*
	*ptr++;   // ptr is increaring 
	ptr += 3; // ptr is increment by 3 (Type of value hold by PTR)
	*/

	(*ptr)++;    // value at PTR i increasing
	printf("%p  %d  %d\n", ptr, *ptr, k);

	++*ptr;  // value at PTR ++ 
	printf("%p  %d  %d\n", ptr, *ptr, k);

	*++ptr;
	printf("%p  %d  %d\n", ptr, *ptr, k);


	char a[] = "Hello World !!!!";
	char *p;
	p = a;

	p = p+3;    // Ptr shifted to 3 byte (ptr holding a char array)
	printf("%p  %s  %s\n", p, a, p);

	*p = 100;    // ascii of 100 will be set on ptr base (3 byte)
	printf("%p  %s  %s\n", p, a, p);


	k = 0x0000;
	char *x = (char *)&k;

	x[0] = 6;
	x[1] = 5;

	printf("%d %d\n", k, *x);

}
#endif

#if 0

int f(int x, int *py, int **ppz)
{
  int y, z;
  **ppz += 1;
   z  = **ppz;
  *py += 2;
   y = *py;
   x += 3;
   return x + y + z;
}

int  main()
{
   int c, *b, **a;
   c = 4;
   b = &c;
   a = &b;
   printf("%d ", f(c, b, a));   // C is not a ptr
   return 0;
}

#endif

#if 0
int main()
{
    int a = 12;
    void *ptr = (int *)&a;
    printf("%d", *ptr);    // void ptr must be type casted not de-refence 
    return 0;

    //op : Compilation Error
}

#endif

#if 0
void swap (char *x, char *y)
{
    char *t = x;
    x = y;   // t = x = Geeksforgreeks 
    y = t;   // y = geeksforgeeks
}

int main()
{
    char *x = "geeksquiz";
    char *y = "geeksforgeeks";
    char *t;
    swap(x, y);
    printf("(%s, %s)", x, y);
    t = x;
    x = y;
    y = t;
    printf("n(%s, %s)", x, y);
    return 0;
}

#endif

int swap(int *p, int *q)
{
	int *t;
	t = p;
	p = q;
	q = t;
	
	// Ptr are only local to func

}

int swap2(int *p, int *q)
{
	int t = *p;
	*p = *q;
	*q = t;
}	
int main()
{
	int a = 10, b = 15, c = 20, d= 25;

	swap(&a, &b);

	printf("%d  %d\n", a, b);
	swap2(&a, &b);
	printf("%d  %d\n", a, b);

	return 0;
}





