#include <stdio.h>

#define SIZE 5

int r = -1;
int f = -1;

int queue_full()
{
	if((f == r + 1) || (f == 0) && (r == SIZE -1))
		return 1;

	return 0;
}

int queue_empty()
{
	if((f == -1))
		return 1;


	return 0;
}

void enqueue(int a[], int k)
{
	// check queue full condition
	if(queue_full()) {
		printf("Queue Full \n");
		return;
	}

	if(r == -1)
	{
		r = f  = 0;
		a[r] = k;
	}
	else {
		r = (r + 1) % SIZE;
		a[r] = k;
	}

	printf("Enqueue:%d   r: %d  f: %d\n", a[r], r, f);
}

void dequeue(int a[])
{
	if(queue_empty()) {
		printf("Queue Empty\n");
		return;
	}

	printf("Dequeue: %d \n", a[f]);

	if(f == r)
		f = r = -1;
	else	
		f = (f+1) % SIZE;
}


void display(int a[])
{
	for(int i =0; i < SIZE; i++)
		printf("%d  ", a[i]);

	printf("\n");
}

int main()
{
	int a[SIZE] = {0};
	dequeue(a);
	enqueue(a, 1);
	enqueue(a, 2);
	enqueue(a, 3);
	enqueue(a, 4);
	enqueue(a, 5);
	enqueue(a, 6);
	dequeue(a);
	display(a);
	dequeue(a);
	enqueue(a, 7);
	enqueue(a, 8);
	enqueue(a, 9);
	dequeue(a);
	dequeue(a);
	dequeue(a);
	dequeue(a);
	dequeue(a);
	return 0;
}
