#include <stdio.h>
#include <stdlib.h>

int index_stack[1000];
char char_stack[1000];
int top_index = 0;
int top_char = -1;

void push_char(char a)
{
    top_char++;
    char_stack[top_char] = a;
}

void push_index(int i)
{
    top_index++;
    index_stack[top_index] = i;
}

void pop_char()
{
    top_char--;
}

void pop_index()
{
    top_index--;
}

int longestValidParentheses(char * s){

    int i = 0;
    int len = 0;
    int max = 0;
    index_stack[0] = -1;

    while(s[i++] != '\0');
        len = i -1;

    for(i = 0; i < len; i++)
    {
        if(s[i] == '(')
        {
            push_char(s[i]);
            push_index(i);
            printf("PUSH :%d  %d\n", index_stack[top_index], top_index);
        }
        else {  // closing bracket
		printf("Closing : i : %d top_char: %d\n", i, top_char);
            if((top_char != -1) && (char_stack[top_char] == '(')) {
                pop_char();
                pop_index();
                int k =  i - index_stack[top_index];
                printf("POP %d  %d  %d\n", max, k, index_stack[top_index]);
                max = max > k?max:k;
            }
            else
            push_index(i);
        }
    }

    return max;
}

int main()
{
	//char *s = "()";
	char *s = ")()())";

	int k = longestValidParentheses(s);

	printf("MAX :%d\n", k);

}
