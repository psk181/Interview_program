#include <stdio.h>

int isprime(int n)
{
	for(int i = 2;i < (n/2 +1 ); i++)
	{
		if(!(n % i)) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n, i;
	printf("NUM :");
	scanf("%d", &n);

	int prm = 2;
	while(n != 1)
	{
	//	printf("%d\n", prm);
		if(isprime(prm) && (!(n % prm)))
		{
			printf("%d ", prm);
			n = n/prm;
		}
		else
			prm++;

	}
	printf("\n");
}
