#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minWindow(char *str, char *ptrn)
{
	int hash_str[128] = {0};
	int hash_ptrn[128] = {0};
	int str_len, ptrn_len;
	int i = 0;
	int min_len = 10000;
	int st_index = -1;
	int start = 0;
	int cnt = 0;

	str_len = strlen(str);
	ptrn_len = strlen(ptrn);
	//while(str[str_len++] != '\0');
	//while(ptrn[ptrn_len++] != '\0');

	if(ptrn_len > str_len) {
		printf("String is Small Than Pattern\n");
		return;
	}

	printf("Len : %d %d\n", ptrn_len, str_len);
	
	while(ptrn[i] != '\0')
		hash_ptrn[ptrn[i++]]++;	

	
	for(i = 0; i < str_len; i++)
	{
		hash_str[str[i]]++;

		if(hash_str[str[i]] <= hash_ptrn[str[i]])
			cnt++;
		
		// remove
		if(cnt == ptrn_len)
		{
			while((hash_ptrn[str[start]] == 0) || (hash_str[str[start]] > hash_ptrn[str[start]]))
			{
				if(hash_str[str[start]] > hash_ptrn[str[start]]) {
					hash_str[str[start]]--;
					printf("Item Removed\n");
				}
				start++;
				printf("while start: %d\n", start);
			}
			int len = i - start + 1;
			if(min_len > len) {
				min_len = len;
				st_index = start;
			}
			printf("start : %d  min_len: %d  len: %d\n", start,min_len, len);
		}

	}

	if(st_index == -1) {
		printf("NO MATCHING STRNG FOUND\n");
		return;
	}

	printf("FINAL min_len: %d  st_index : %d\n", min_len, st_index);
}

int main()
{
	char *str = "ADOBECODEBANC";
	//char *str = "AOWQABC";
	char *ptrn = "ABC";
	
	minWindow(str, ptrn);
}


