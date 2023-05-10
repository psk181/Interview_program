#include <stdio.h>
#include <stdlib.h>


struct queue {
	int val;
};

int sz = 0;

struct stack {
	struct queue *stack[100];
	int front;
	int rear;
};

struct stack *create_stack()
{
	struct stack *st = (struct stack *)malloc(sizeof(struct stack));
	st->rear = st->front = -1;
	return st;
}

void enqueue(struct stack *st, struct queue *node)
{
	if(st->rear == -1) {
		st->front = st->rear = 0;
		st->stack[st->rear] = node;
	}
	else
	{
		st->rear++;
		st->stack[st->rear] = node;
	}
	printf("Enqueue:%d  r: %d  f: %d\n", node->val, st->rear, st->front);
}

struct queue *dequeue(struct stack *st)
{
	if(st->front == -1) {
		return NULL;
	}

	struct queue *q = st->stack[st->front];
	if(st->front == st->rear)
		st->rear = st->front = -1;

	else
		st->front++;
	return q;
}

void push(struct stack *st, int k)
{
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));

	q->val = k;
	
	enqueue(st, q);
	int size = st->rear - st->front + 1;

	while(size > 1) {
		struct queue *front = dequeue(st);
		enqueue(st, front);
		size--;
	}
}

void top(struct stack *st)
{
	struct queue *front = st->stack[st->front];
	printf("TOp: %d\n", front->val);
}


int main()
{
	struct stack *st = create_stack();
	int flag = 1;
	int k;

	printf("1: Push\n");
	printf("2: Pop\n");
	printf("3: Top\n");
	printf("4: Exit\n");

	while(flag) {
		printf("Choice :");
		scanf("%d", &k);

		switch (k){
			case 1:
				printf("Data: ");
				scanf("%d",&k);
				push(st, k);
				break;
			case 2:
				//pop(st);
				break;
			case 3:
				top(st);
				break;
			case 4:
				flag = 0;
				break;
			default:
				break;
		}
	}

	return 0;
}
