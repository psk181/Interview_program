#include <stdio.h>

/*
 * Set Matrix Zero
 * Given a matrix if an element in the matrix is 0 then 
 * you will have to set its entire column and row to 0 and then return the matrix.
 *
 *
 * Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 *
 * */



int main()
{
	int arr[3][3] = {{1, 1,0},
			 {1, 1, 1},
			 {1, 1,1} };

	int i, j;

	int flag = 0;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++) {
			if(arr[i][j] == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}

	int k = i;
	printf("%d %d\n", i , j);
	for(i = 0; i < 3;i++)
		arr[i][j] = 0;
	for(j = 0; j < 3; j++)
		arr[k][j] = 0;

	for(i = 0; i < 3;i++) {
		for(j = 0; j < 3; j++) {
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}


}

