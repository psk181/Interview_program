#include <stdio.h>
#include <stdlib.h>

// front : 1st element (Delete)
// rear : The last element (Add)

struct list {
        int val;
        struct list *next;
};

struct queue {
	struct list *rear;
	struct list *front;
};

struct queue* createqueue()
{
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	q->front = q->rear = NULL;

	return q;
}


void enqueue(struct queue *q, int k)
{
	struct list *tmp;
	tmp = (struct list*)malloc(sizeof(struct list));
	tmp->val = k;
	tmp->next = NULL;

	printf("Enque : %d\n", k);
	if(q->rear == NULL) {
		q->rear = q->front = tmp;
		return;
	}

	q->rear->next = tmp;
	q->rear = tmp;
}

void dequeue(struct queue *q)
{
	if(q->front == NULL) {
		printf("Queue Underflow\n");
		return;
	}
	struct list *tmp = q->front;
	q->front = q->front->next;

	if(q->front == NULL)
		q->rear = NULL;

	printf("Dequue : %d\n", tmp->val);
	free(tmp);
}


void display(struct queue *q)
{
        struct list *ptr = q->front;

        while(ptr != NULL)
        {
                printf("%d->", ptr->val);
                ptr = ptr->next;
        }

        printf("NULL\n");
}

int main()
{
        struct queue *q = createqueue();

	dequeue(q);
	enqueue(q, 1);
	enqueue(q, 2);
	//display(q);
	dequeue(q);
	//display(q);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	dequeue(q);
	enqueue(q, 6);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);

	display(q);

        return 0;

}
