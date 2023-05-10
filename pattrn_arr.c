#include <stdio.h>


/* Pattern Printing
 *1
 *1 1
 *1 1 1   
 *1 1 1 1
 *1 1 1 1 1
 *
 *
 * 1
 * 1 2
 * 1 2 3
 * 1 2 3 4
 * 1 2 3 4 5
 *
 * Pascal Triangle
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 * 1 5 10 10 5 1
 * 1 6 15 20 15 6 1
 * 1 7 21 35 35 21 1
 */

int main()
{
	int i, j;
	int len = 8;
	int val = 1;
	
	//Pattern : 1
	for(i = 0; i < len; i++)
	{
		for(j = 0; j <= i; j++)
			printf("1 ");
		printf("\n");
	}
	
	// Pattern : 2
	for(i = 0; i < len; i++)
	{
		for(j = 0; j <= i; j++)
			printf("%d ", j+1);
		printf("\n");
	}

	// Pascal Triangle  : 3	
	for(i = 0; i < len; i++)
	{
		for(j = 0; j <= i; j++) {
			if((i == 0) || (j == 0))
				val = 1;
			else
				val = val *(i -j + 1)/j;
			printf("%d ", val);
					
		}
		printf("\n");
	}


}
