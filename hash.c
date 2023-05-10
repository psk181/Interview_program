#include <stdio.h>

int main()
{

/// Find Freq of each char in string (small char)
#if 0
	char str[] = "abcdefanananehsna";

	int a[26][2] = {0};
	int i = 0;
	while(str[i] != '\0')
	{
		a[str[i]- 'a'][0]++;
		i++;
	}

	for(i = 0; i < 26; i++) {
		if(a[i][0] != 0)
			printf("%c  : %d\n", (i + 'a'), a[i][0]);
	}

#endif

// Find the non repreating char in a string 

	char str[] = "abcdffghabcdfgpabcdefgabced"

	int a[26][2] = {0};
	int i = 0;

	while(str[i] != '\0')
	{
			
	
	}



}
