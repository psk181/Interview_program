#include <stdio.h>



int main()
{
	int a[5] = {1, 2, 3,4, 5};
	int k = 1, p;
	int n = 5, i;
	
	for(i = n-1; i >=0; i--)
	{
		p = i - k;
		if(p < 0) {
			p = i + n - k;
		}
		printf("i : %d   p : %d  %d\n", i, p, a[p]);
	
		a[i] = a[p];
	}

	for(i = 0; i < n; i++)
		printf("%d  ", a[i]);

	printf("\n");
	
	return 0;

}

