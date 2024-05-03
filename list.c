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

void print_backtrace()
{
    void *bt[32];
    int i, bt_size;
    char **bt_syms;
    //long tid = syscall(SYS_gettid);

    bt_size = backtrace(bt, 32);
    bt_syms = backtrace_symbols(bt, bt_size);
    for (i = 1; i < bt_size; i++) {
      //  snprintf(buf, sizeof(buf), "bt:%ld: %s", tid, bt_syms[i]);
       // syslog(LOG_DEBUG, buf);
        printf("%s\n", bt_syms[i]);
    }
    free(bt_syms);
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

void delete(struct list **head, int data)
{

	struct list *ptr, *temp;
	ptr = *head;

	if(ptr->val == data)
	{
		*head = ptr->next;
		free(ptr);
	}

	else {
		while(ptr->next != NULL)
		{
			if(ptr->next->val == data) {
				temp = ptr->next;
				ptr->next = ptr->next->next;
				free(temp);
			}
			else
				ptr = ptr->next;
		}
	}
	
}

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

void remove_duplicate(struct list **head)
{
	struct list *ptr, *tmp;
	ptr = *head;
	tmp = ptr->next;

	if(*head == NULL) {
		printf("List Empty\n");
		return;
	}

	while(tmp != NULL)
	{
		if(tmp->val == ptr->val) {
			ptr->next = tmp->next;
			free(tmp);
			tmp = ptr->next;
		}
		else {
			ptr = ptr->next;
			tmp = tmp->next;
		}
	}
}


void remove_all_duplicate(struct list **head)
{
	struct list *ptr, *tmp;
	ptr = *head;
	struct list *dum = (struct list *)malloc(sizeof(struct list));

	dum->next = *head;
	tmp = dum;

	if(ptr == NULL) {
		free(dum);
		return;
	}

	while(ptr != NULL) {

		// check if ptr->next != NULL
		// another condition to check 1 and 2 element are same or not
		while((ptr->next != NULL) && (tmp->next->val == ptr->next->val)) {	
			ptr = ptr->next;
		}

		// if ptr had unique value 
		// no need to delete just update the dummy node 
		// and current node (ptr)
		// not gone to while loop
		if(dum->next == ptr)
			dum = dum->next;

		// when curent(ptr) is updated [in while loop]
		// so need to update the dummy node 
		else
			dum->next = ptr->next;

		ptr = ptr->next;
	}

	// update with original
//	*head = dum->next;

}

void detect_remove_loop(struct list *head)
{
	struct list *slow = head;
	struct list *fast = head;

	while(slow && fast) {
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
		{
			printf("Loop Detected\n");
			break;
		}
	}

	// Move slow ptr to head to detect the entry point of loop
	slow = head;

	//  When their is full loop in a list, means head is entry point of loop
	if(slow == fast)
	{
		while(fast->next != slow)
			fast = fast->next;
	
		fast->next = NULL;
	}
	else {
	
		while(fast-> next != slow->next) {
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}
		
}

void dummy(struct list *head)
{
	struct list *np, *fp;

	np = head;
	fp = np->next;

	while(np && fp)
	{
		if(np == fp) {
			printf("PSK Loop Detected\n");
			break;
		}
	
		np = np->next;
		fp = fp->next->next;
	}

	np = head;
	
	if(np = fp)
	{
		while(fp->next != np)
			fp = fp->next;

		fp->next = NULL;
	}
	else {
		while(fp->next != np)
		{
			np = np->next;
			fp = fp->next;
		}
		fp = fp->next;
	}
}

void detelct_intersect(struct list **head1, struct list **head2)
{
	int d;
	int l1 = 0, l2 = 0;

	struct list *ptr, *ptr2;

	ptr = *head1;
	while(ptr != NULL) {
		l1++;
		ptr = ptr->next;
	}
	
	ptr = *head2;
	while(ptr != NULL) {
		l2++;
		ptr = ptr->next;
	}

	d = l1 - l2;

	// Travesrse the longest loop to till Diff
	ptr = *head1;

	while(d)
	{
		ptr = ptr->next;
		d--;
	}

	ptr2 = *head2;
	while(ptr != NULL)
	{
		if(ptr == ptr2) {
			printf("Intersect Point : %d\n", ptr->val);
			break;
		}
		
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
}

void delete_even_node(struct list **head)
{
	struct list *tmp, *ptr;
       	tmp = *head;
	ptr = tmp->next;

	if(tmp == NULL) {
		printf("List Empty or Single Node\n");
		return;
	}

	while(ptr && tmp)
	{
		tmp->next = ptr->next;
		free(ptr);
		tmp = tmp->next;
		if(tmp != NULL)
			ptr = tmp->next;
	}
}

void delete_k_node_end(struct list **head, int k)
{
	struct list *ptr = *head;
	struct list *tmp = *head;

	if((*head == NULL) || (k == 0))
		return;

	for(int i = 0; i < k; i++)
		ptr = ptr->next;

	printf("%p  %d", ptr, ptr->val);
	if(!ptr) {
		tmp = tmp->next;
		return;
	}

	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		tmp = tmp->next;
	}

	tmp->next = tmp->next->next;
}

struct list *rotate_list(struct list *head, int k)
{
	struct list *tmp = head;
	struct list *ptr = head;
	struct list *abc;

	if((tmp == NULL) || (k == 0))
		return head;

	int cnt = 1;
	while(tmp->next)
	{
		cnt++;
		tmp = tmp->next;
	}
	

	k = k % cnt;
	if(!k)
		return  head;

	tmp->next = head;
	cnt = cnt - k - 1;
	for(int i = 0; i< cnt; i++)
		ptr = ptr->next;

	printf("%d \n", ptr->val);	
	abc = ptr->next;
	ptr->next = NULL;
	display(abc);
	return abc;
}


void swap_pair_node(struct list **head)
{
	struct list *tmp = *head;
	struct list *ptr = tmp->next;
	struct list *abc;

	if((*head == NULL) || (tmp->next == NULL))  // no node or single node
		return;

	*head = ptr;

	while(ptr)
	{
		abc = ptr->next;
		ptr->next = tmp;

		if((abc == NULL) || (abc->next == NULL)) {
			tmp->next = abc;
			return;
		}

		tmp->next = abc->next;

		tmp = abc;
		ptr = tmp->next;
	}
}

void reverse_list(struct list **head)
{
	struct list *prev, *curr, *next;
	curr = *head;
	prev = NULL;
	next = NULL;

	while(curr != NULL)
	{
		// store the next
		next = curr->next;
		curr->next = prev;    // create a link
		
		//move the prev and curr ptr by 1
		prev = curr;
		curr = next;
	}
	
	*head = prev;
}

struct list *reverse_list_pos_n_m(struct list *head, int n, int m)
{
	
	struct list *curr, *prev;
	curr = head;
	int i = 0;

	// prev : To maintain the prev node that point to the next node of revese list
        // prev->next = reverse_head (nw_prev : that is actually a head in case of simple reverse of list)
        // curr : to maintain the last node link (right position) 
	// basically to maintain the last list after reverse of position m 
	// prev : maintain the link for n nodes and sv_link for after m position 
	for(i = 1; i < n;i++) {
		prev = curr;
		curr = curr->next;
	}

	struct list *sv_lint, *nw_prev;;
	sv_link = curr;
	nw_prev = NULL;
	while(i <= m)
	{
		next = curr->next;
		curr->next = nw_prev;
		nw_prev = curr;
		curr = next;
		i++;
	}

	if(prev != NULL)
		prev->next = nw_prev;
	else
		head = prev;

	printf("New_head: %d\n", new_head->val);
	sv_link->>next = curr;

	return head;

}

struct list *reverse_n_node(struct list *head, int k)
{
        struct list *prev, *curr, *nxt;
        curr = head;
        prev = head;
        int p = 0;

        // set the previuos to Nth node of list 
        while(p < k) {
                prev = prev->next;
                p++;
        }

        p = 0;
        while(p < k) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
                p++;
        }

        return prev;
}

struct list *reverse_after_n_node(struct list *head, int k)
{
        struct list *prev, *curr, *nxt, *tmp;
        curr = head;
        int p = 0;

        // set the previuos to Nth node of list 
        while(p < k) {
                tmp = curr;
                curr = curr->next;
                p++;
        }

        prev = NULL;
        while(curr) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
                p++;
        }

        tmp->next = prev;
        return head;
}


void list_display_unique(struct list **head)
{
	struct list *ptr, *tmp, *abc;
    ptr = *head;
    tmp = *head;

    if((ptr == NULL) || (ptr->next == NULL) || (ptr->next->next == NULL))
    	return;

    while(tmp != NULL)
    {
        ptr = tmp;
        while(ptr->next != NULL) {
            abc = ptr;
            ptr= ptr->next;
        }

        abc->next = NULL;
        abc = tmp->next;
        tmp->next = ptr;
        ptr->next = abc;
	tmp = abc;

	display(tmp);
	//return;
    }

    //return tmp;
}

struct list *reverse(struct list *ptr)
{
    struct list *curr, *prev, *next;

    prev = NULL;
    curr = ptr;
 
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int compare_list(struct list *ptr, struct list *tmp)
{
	while(ptr && tmp) {
		if(ptr->val != tmp->val)
			return 0;
		ptr = ptr->next;
		tmp = tmp->next;
	}
	return 1;
}

void palindrome_list(struct list **head)
{

#if 0 //M 1
    struct list *fp, *np, *prev_np, *mid;
    np = *head;
    fp = *head;
    mid = NULL;

    while(fp && fp->next)
    {
	    prev_np = np;
        np = np->next;
        fp = fp->next->next;
    }
    
    // in case of Odd fp->next = NULL
    // in case of odd fp = null

    if(fp != NULL) {
	    mid = np;
	    np = np->next;
    }

    printf("prev_np :%d  np: %d  mid: %p\n", prev_np->val, np->val, mid);

    struct list *sec_half_head = np;  // 2nd half list head 
    prev_np->next = NULL;  // seprate out the first half list

    reverse_list(&sec_half_head);  // reverse the 2nd half of the list

    display(sec_half_head);
    display(prev_np);

   	int k = compare_list(*head, sec_half_head);

	if(k)
		printf("YES");
	else
		printf("NO\n");

	if(mid) {
		prev_np->next = mid;
		mid->next = sec_half_head;
	}
	else {
		prev_np->next = sec_half_head;
	}
#endif

	struct list *tmp, *ptr;
	tmp = *head;
	ptr = *head;

	tmp = reverse(tmp);

	display(tmp);

	while(tmp && ptr)
	{
		if(tmp->val != ptr->val) {
			printf("NO\n");
			return;
		}
		tmp = tmp->next;
		ptr = ptr->next;
	}

	printf("YES\n");
}


int main()
{
	struct list *head = NULL;
	struct list *head2 = NULL;
	int i;
//	int arr[10] = {1, 2, 3, 4,5, 6 ,7,7,7, 7};

//	int arr[10] = {1, 1, 1, 1, 1,1, 1, 2, 2, 2};
//	int arr[10] = {1, 1, 1, 1, 1,1, 1, 2, 2, 2};
//
	//int arr[] = {1,2,3,4,5, 6, 7,8,9,10, 11};
	int arr[] = {1,2, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	for(i =0; i < n; i++)
		insert(&head, arr[i]);

	display(head);
	//printf("Position: ");
	//scanf("%d", &i);
	//delete_k_node_end(&head, i);
	//delete_even_node(&head);

	//head = rotate_list(head, 2);
	//swap_pair_node(&head);
	//head = reverse_list_pos_n_m(head, 1, 2);
	//list_display_unique(&head);
	palindrome_list(&head);
	display(head);

#if 0
	//remove_duplicate(&head);
	//remove_all_duplicate(&head);

	//reverse_list(&head);
	// to create a loop 
	head->next->next->next->next->next = head;
	dummy(head);


	display(head);
	//detect_remove_loop(head);

	struct list *ptr = (struct list *)malloc(sizeof(struct list));
        ptr->val = 50;
        ptr->next = NULL;
	head2 = ptr;


	head2->next = head->next->next->next->next;
	display(head2);
	
	detelct_intersect(&head, &head2);


	display(head);
#endif
	return 0;
}
