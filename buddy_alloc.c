#include <stdio.h>
#include <stdlib.h>

// To Design n buddy allocator free list
// Basicllay its a array of pointer to circular linked list

#define SIZE 11

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


int main()
{
	struct list *buddy_list[3];   // array of pointer to list
	struct list *order_0, *order_1, *order_2;   // creating a 3 list of order 0, 1, 2, 

	//struct list *order_0;	
	int i;

	// create a list for order 0, 1, 2

	int arr_0[10] = {1, 2, 3, 4,5, 6 ,7, 8, 9, 10};
	int arr_1[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 99};
	int arr_2[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 999};


        for(i =0; i < 10; i++) {
                insert(&order_0, arr_0[i]);
                insert(&order_1, arr_1[i]);
                insert(&order_2, arr_2[i]);
	}


//        circular_list(&head);

        display(order_0);
	display(order_1);
        display(order_2);

	buddy_list[0] = order_0;
	buddy_list[1] = order_1;
	buddy_list[2] = order_2;


	return 0;
}
