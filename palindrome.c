#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	int i = 0;
	int flag = 1, pal = 1;
	int len;

	char str[20];
	printf("String:");
	scanf("%s", str);
	len = strlen(str);

	while(len & flag)
	{
		if(str[i] != str[len -1]){
			flag = 0;
			pal = 0;
			printf("String is Not Palindrom\n");
		}
		len--;
		i++;
	}

	if(pal == 1)
		printf("Palindrom\n");

	return 0;

}
