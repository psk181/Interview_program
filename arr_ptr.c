#include <stdio.h>
#include <stdlib.h>


int main()
{

#if 0
	// arr of ptr 
	int *p[3];
	int a[3] = {10, 20, 30};
	int i = 0;

	for(i = 0; i < 3; i++)
	{
		p[i] = &a[i];
	}

	for(i = 0; i < 3; i++)
	{
		printf("%d\n", *p[i]);
	}
#endif	

// 2D array
// using single ptr

	int cnt = 10;
	int r = 3, c = 4;
	int i, j;

	int *ptr = (int *)malloc(r * c * sizeof(int));

	// Assign
	for(i = 0; i < (r*c); i++)
			ptr[i] = cnt++;
	// print
	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			printf("%d  ", ptr[i*c + j]);
		}
		printf("\n");
	}

// Using an array of pointers

	int *p[r];

	for(i = 0;i < r; i++)
	{
		p[i] = (int *)malloc(c * sizeof(int));
	}

	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			p[i][j] = cnt++;

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			printf("%d  ", (*(*(p + i) + j)));
		}
		printf("\n");
	}
	
	for(i = 0;i < r; i++)
		free(p[i]);
	
// Using Double Ptr

	int **db_ptr;
	db_ptr = (int **)malloc(r * sizeof(int));
	
	for(i = 0;i < r; i++)
	{
		db_ptr[i] = (int *)malloc(c * sizeof(int));
	}

	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			db_ptr[i][j] = cnt++;

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			printf("%d  ", (*(*(db_ptr + i) + j)));
		}
		printf("\n");
	}

	for(i = 0;i < r; i++)
		free(db_ptr[i]);		

}
