#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>   // bracktrace


// Program for all operations of List
// Remove dupliate in a list
// Detect and Remove the node

struct list {
        struct list *next;
        int val;
};


void display(struct list *head)
{
        struct list *ptr = head;

        if(ptr == NULL) {
                printf("NULL\n");
                return;
        }
        while(ptr != NULL ) {
                printf("%d-->", ptr->val);
                ptr = ptr->next;
        }

        printf("NULL \n");
}

void insert(struct list **head, int data)
{
        struct list *ptr;

        ptr = (struct list *)malloc(sizeof(struct list));
        ptr->val = data;
        ptr->next = NULL;

        if(*head != NULL)
        {
                struct list *temp = *head;
                while(temp->next != NULL) {
                        temp = temp->next;
                }

                temp->next = ptr;
        }
        else
                *head = ptr;
}


void circular_list(struct list **head)
{
	struct list *tmp = *head;

	while(tmp ->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
}


int main()
{
        struct list *head = NULL;
        int i;
//      int arr[10] = {1, 2, 3, 4,5, 6 ,7,7,7, 7};

//      int arr[10] = {1, 1, 1, 1, 1,1, 1, 2, 2, 2};
//      int arr[10] = {1, 1, 1, 1, 1,1, 1, 2, 2, 2};
//
        //int arr[] = {1,2,3,4,5, 6, 7,8,9,10, 11};
        int arr[] = {1,2,3, 4};
        int n = sizeof(arr) / sizeof(arr[0]);

        for(i =0; i < n; i++)
                insert(&head, arr[i]);


	circular_list(&head);

        display(head);

	return 0;
}
