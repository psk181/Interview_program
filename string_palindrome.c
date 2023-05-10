#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) a>b?a:b

int find_palindrome(char *s, int i, int j, int len)
{
	int flag = 0;
	char cnt = s[i];
	while((i > 0) && (j < len) && (s[i] == s[j]))
	{
		i--;
		j++;
		flag = 1;
	}

	if(flag)
		printf("Palindrome:%c   i: %d  j : %d\n",cnt,  i, j);
	return (j - i - 1);
}

char * longestPalindrome(char * s)
{
	int i = 0, j, start = 0;
	int max_len = 0;
	int end = 0;

	int len;
	while(s[i++] != '\0');

	len = i-1;

	for(i = 0; i < len; i++)
	{
		int len1 = find_palindrome(s, i, i, len);
		int len2 = find_palindrome(s, i, i+1, len);
		len1 = MAX(len1, len2);

		printf("Len1 : %d  %d\n", len1, i);
		if((end - start) < len1)
		{
			start = i - (len1 - 1)/2;
			end = (i + len1 /2);
		}
	}


	char *ptr;
	j = 0;
	ptr = (char *)malloc(sizeof(max_len+1));
	for(i = start; i < end+1; i++)
		ptr[j++] = s[i];

	ptr[j] = '\0';

	return ptr;

}



// using Brute Force Methord 
// Complexcity : O (N^3)
// 3 Nested loop are used

#if 0
char * longestPalindrome(char * s){

    int start = 0;
    int i = 0, j, k;
    int max_len = 0;
    int flag = 0;

    int len;
    while(s[i++] != '\0');

    len = i-1;

    for(i = 0; i < len; i++)
    {
        for(j = i; j < len; j++)
        {
            flag = 1;
            for(k = i; k < (j-1+1)/2; k++) {
                if(s[i + k] != s[ j-k])
                    flag = 0;
            }
            if(flag && ((j - i + 1 ) > max_len))
            {
                start = i;
                max_len = (j - i + 1 );
            }
        }
    }

    printf("st: %d    max_len: %d\n", start, max_len);

    char *ptr;
    j = 0;
    ptr = (char *)malloc(sizeof(max_len+1));
    for(i = start; i < max_len; i++)
        ptr[j++] = s[i];

    ptr[j] = '\0';

    return ptr;
}

#endif

int main()
{
	//char *str = "acvghgvpaba";
	//char *str = "bababd";
	char *str = "aaaa";

	char *ptr = longestPalindrome(str);

	printf("%s\n", ptr);

}

