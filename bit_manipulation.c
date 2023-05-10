#include <stdio.h>

int mask = 0x3;

#if 0
// Program to find the contigeos tar in a num 
int main()
{
	int x = 0xCFFF;
	int tar = 1;
	int cnt = 0;

	int flag = 1;
	while(x)
	{
		int p = (x & mask);
		if((p == tar) && flag) {
			cnt++;
			flag = 1;
		}
		else
			flag = 0;

		x = x >> 2;
	}

	printf("cnt: %d\n", cnt);

}
#endif


#if 1
int main()
{

/*  Power of 2 
*/

	printf("Hello World!!!!!!\n");    
	int n = 0x34;
	int x = 7;

find_nibble:
	printf("GOTO Func\n");
        n = ((n & 0xf) << 4) | ((n & 0xF0) >> 4);
        printf("NIbble n : %0x\n", n);

	if(x & (x-1)) {
		printf("NOOO Power of 2\n");
		x--;
		goto find_nibble;
	}
	else	
		printf("YES Power of 2\n");

/* Count Set Bits
	int cnt = 0;
	int n = 176;
	while(n)
	{
		n = n & (n -1);   // used to find the right most bit of a number
		cnt++;
	}
	printf("cnt : %d\n", cnt);

*/

/* Swap of Niblle 
 
	int n = 0x34;
		
	n = ((n & 0xf) << 4) | ((n & 0xF0) >> 4);
	printf("n : %0x\n", n);
*/
/* Swap of Bytes 
 
	int n = 0x1234;
		
	n = ((n & 0xFF) << 8) | ((n & 0xFF00) >> 8);
	printf("n : %0x\n", n);

*/

/* Covert Little India to Big Indian
 * Litte : Lower --- LSB
 * Big : Higher ---- LSB

	int n = 0x12345678;   // LE	

	int x = ((n & 0xFF) << 24) | ((n & 0xFF00) << 8) | ((n & 0xFF0000) >> 8) | ((n & 0xFF000000) >> 24);

	printf("0x%x\n", x);
*/


// Set a particular bit

	x = 12;
	int pos = 0;

	x = x | (1 << pos);
	printf("x : 0x%x\n", x);


// Clear a particular bit
	x = 10;
	pos = 1;
	x = x & (~(1 << pos));
	printf("x : 0x%x\n", x);

// Toggle




}
#endif
