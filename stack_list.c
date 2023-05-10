#include <stdio.h>
#include <stdlib.h>

struct list {
	int val;
	struct list *next;
};

void push(struct list **head, int k)
{
	struct list *ptr;
	ptr = (struct list *)malloc(sizeof(struct list ));
	ptr->val = k;
	//ptr->next = NULL;

	if(*head == NULL) {
		ptr->next = NULL;
		*head = ptr;
	}

	else {
		ptr->next = *head;
		*head = ptr;
	}
}

void pop(struct list **head)
{
	struct list *tmp = *head;

	if(tmp == NULL) {
		printf("Stack EMPTY\n");
		return;
	}

	//struct list *ptr;

	printf("Pop: %d\n", tmp->val);

	tmp  = tmp->next;
	free(tmp);
	*head = ptr;
}


void display(struct list *head)
{
	struct list *ptr = head;

	while(ptr != NULL)
	{
		printf("%d->", ptr->val);
		ptr = ptr->next;
	}

	printf("NULL\n");
}


int main()
{
	struct list *head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);


	display(head);
	pop(&head);


	display(head);

	return 0;

}
