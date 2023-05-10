#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int val;
}STACK;

typedef struct queue {
	STACK *s1[100];
	STACK *s2[100];
	int top;
}QUEUE;


void top(QUEUE *q)
{
	if(q->top == -1) {
		printf("Queue Empty\n");
		return;
	}
	STACK *s1 = q->s1[q->top];
	printf("TOP Element : %d\n", s1->val);
}

QUEUE *create_queue()
{
	QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
	q->top = -1;
	return q;
}

void push(int k, QUEUE *q)
{
	STACK *ptr = (STACK *)malloc(sizeof(STACK));
	ptr->val = k;
	
	q->top++;
	q->s1[q->top] = ptr;
}


void enqueue(QUEUE *q, int k)
{
	printf("Enqueu: %d\n", k);
	push(k, q);
}

int pop(QUEUE *q)
{
	STACK *s ;
	if(q->top == 0) {
		s = q->s1[q->top];
		q->top--;
		return s->val;
	}
	// copy all S1 data to S2 to find the last element pushed to stack
	// Queue : L1FO

	int top = q->top;
	int s2_top = 0;
	int val = 0;
	
	while(top) // moving s1 ---> s2
	{
		q->s2[s2_top++] = q->s1[top--];
	};
	
	q->s2[s2_top] = q->s1[top];
	s = q->s2[s2_top];
	val = s->val;
	top = 0;

	while(s2_top)
	{
		s2_top--;
		q->s1[top++] = q->s2[s2_top];
	}

	q->top--;
	return val;
}

void dequeue(QUEUE *q)
{
	int val;
	if(q->top == -1) {
		printf("Queue Empty\n");
		return;
	}
	val = pop(q);
	printf("Dequeue :%d\n", val);
}


int main()
{
	QUEUE *q = create_queue();

	enqueue(q, 10);
	enqueue(q, 20);
	dequeue(q);
	
	top(q);
	enqueue(q, 30);
	top(q);
	enqueue(q, 40);
	enqueue(q, 50);
	top(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
}
