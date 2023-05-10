#include <stdio.h>



int serach_keyword(char *buff, char *keyword)
{
	int cnt = 0;
	int len = 0;  // to store the len of world 
	int i = 0;
	int key_len = 2;

	while(buff[i] != '\0')   // traverse the buffer till end
	{
		len = 0;
		while((buff[i] != ' ') &&  (buff[i] != '\0'))   // seaching for space and . (end of statement)
		{
			len++;
			i++;
		}
		if(len == key_len)
		{
			if((keyword[0] == buff[i-2]) && (keyword[1] == buff[i-1]))
				cnt++;
			printf("len : %d  i :%d cnt: %d\n", len , i, cnt);
		}
		i++;
	}

	return cnt;
}

int main()
{
	char *buff = "Hello to is how to many to to";
	char *keyword = "to";

	int k = serach_keyword(buff, keyword);
	printf("cnt : %d\n", k);
}
