#include <stdio.h>
#include <stdlib.h>

int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div_psk(int x, int y);

int (*hndler_list []) (int, int) = {	
	add,
	sub,
	mul,
	div_psk
};

int add(int x, int y)
{
	printf("ADD\n");
	return (x+y);
}

int sub(int x, int y)
{
	printf("SUB\n");
	return (x-y);
}

int mul(int x, int y)
{
	printf("MUL\n");
	return (x*y);
}

int div_psk(int x, int y)
{
	printf("DIV\n");
	return (x/y);
}

int main()
{
	int x, y, ops;
	int result;
	//scanf("%d  %d  %d\n", x, y, ops);

	x = 10;
	y = 5;
	ops = 1;
	for(int i = 0; i < 4; i++)
	{
		if(i == ops)
		{
			result = hndler_list[i](x,y);
			break;
		}
	}

	printf("Result: %d\n", result);
	return 0;
}
