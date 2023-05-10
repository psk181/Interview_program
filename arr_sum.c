#include <stdio.h>

int main()
{


// Find subarray (start and end index) that sum egual to target sum
// M1 : nested loop
// M2: Sliding Window (adding an element from start and removing if sum > tar)

#if 0
	int a[10] = {1, 2, 5, 4, 5, 6, 7, 8, 9, 10};

	int i;
	int tar = 15;
	int s = 0, e = 0;

	int sum = 0;
	for(i = 0; i< 10; i++) {
		sum += a[i];
	
		while((sum > tar) && (s < i-1))
		{
			sum = sum - a[s];
			s++;
		}
		if(sum == tar) {
			e = i;
			printf("Start %d  end: %d\n", s, e);
			break;
		}
		printf("i: %d sum : %d s:%d\n ", i, sum, s);
	}
#endif

// Find max sum of a subarray (non-negative)

#if 1

	int a[] = {-2, -3, -3, 4, -1, -2, 1, 5, -3};

	int max_sum = -100;
	int sum = 0;
	for(int i =0; i< 9; i++)
	{
		sum += a[i];
		max_sum = (sum > max_sum)?sum:max_sum;

		if(sum < 0)
			sum = 0;
	}

	printf("Max Sum %d\n", max_sum);

#endif



}

