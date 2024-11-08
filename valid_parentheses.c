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
	int start = 0;
	int end  = 0;

    while(s[i] != '\0')
    {
	    // Push both index and char to stack
        if(s[i] == '(')
        {
            push_char(s[i]);
            push_index(i);
            printf("PUSH :%d  %d\n", index_stack[top_index], top_index);
        }
        else {  
		// closing bracket and stack is not empty , means found a correct pair
		// of parentheses, so pop char and index
		//printf("Closing : i : %d top_char: %d\n", i, top_char);
            if((top_char != -1) && (char_stack[top_char] == '(')) {
                pop_char();
                pop_index();
		// Find the length curr index - last wrong index 
                int k =  i - index_stack[top_index];	
                printf("POP %d  %d  %d\n", max, k, index_stack[top_index]);
                // Below condition is commented to maintain the start and end index, 
		//max = max > k?max:k;

      		//Below code is needed only to maintain the start and end index
		if(max  < k)
		{
			start = index_stack[top_index] + 1;
			end = i;
			max = k;
		}

            }
		// Push the wrong index to maintain the len
            else {
            push_index(i);
	    }

	}
	    i++;
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
