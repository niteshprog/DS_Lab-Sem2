#include<stdio.h>
#include<stdlib.h>

//structure-body
struct node{
	int data; 
	struct node *next; 
}*first = NULL, *temp = NULL, *ptr = NULL;

//function-prototypes
void createnode(); 
void show(); 
void insert(); 
void bubblesort();
int length(); 

//main-function
int main()
{
    int job; 
    menu:
    printf("           MENU               "); 
    printf("\n------------------------------"); 
    printf("\n1.Insertion at end\n2.Get Length\n3.Display\n4.Get sorted list\n5.Exit"); 
    printf("\nChoice: "); 
    scanf("%d", &job); 
    system("clear"); 
    switch(job)
    {
        case 1: 
            insert(); 
            break; 
        case 2: 
            printf("\nLength of the present list: %d", length()); 
            break; 
        case 3: 
            show(); 
            break; 
        case 4: 
            printf("\nBefore sorting: "); 
            show(); 
            bubblesort(); 
            printf("\nAfter sorting: "); 
            show(); 
            break; 
        case 5: 
            exit(0); 
        default: 
            printf("\nInvalid option chosen..!"); 
            break; 
    }
    while((getchar()) != '\n'); 
    printf("\nPress enter to continue..");
    getchar(); 
    system("clear"); 
    goto menu; 
	return 0; 
}

//function-to-create-block
void createnode()
{
	//DMA-for-the-block
	temp = malloc(sizeof(struct node)); 
	//setting-up-the-members-of-the-node
	printf("\nEnter the data: "); 
	scanf("%d", &temp->data); 
	temp->next = NULL; 
}

//function-to-display-list
void show()
{
	//check-for-underflow
	if(first == NULL)
	{
		printf("\nNothing to print..."); 
	}
	//if-not-underflow-then-traverse-throughout-the-list-and-print-all-elements
	else
	{
		printf("\nList: "); 
		for(ptr = first; ptr != NULL; ptr = ptr->next)
		{
			printf("%d ", ptr->data); 
		}
	}
}

//function-to-insert-at-the-end-and-to-create-the-list
void insert()
{
	//to-take-user-choice-to-continue
	int choice; 
	//insert-the-element-at-the end
	do{
		printf("\nInsertion at the end.."); 
		createnode(); 
		//check-for-underflow
		if(first == NULL)
		{
			first = temp; 
		}
		//if-not-underflow-then-insert-the-block-next-to-last-block
		else
		{
			for(ptr = first; ptr->next != NULL; ptr = ptr->next); 
			ptr->next = temp; 
		}
		printf("\nNode Inserted..."); 
		while((getchar()) != '\n'); 
		printf("\nPress enter to continue..."); 
		getchar(); 
		system("clear"); 
		//get-user-choice-to-continue-or-not
		label: 
		printf("\nDo you want to continue insertion\n1. Yes\n2. No\nChoice: "); 
		scanf("%d", &choice); 
		//to-handle-the-invalid-choice-made-by-user
		if(choice < 1)
		{
			printf("\nInvalid choice....");
			goto label; 
		}
		else if(choice > 2)
		{
		    printf("\nInvalid choice...."); 
		    goto label; 
		}
		}while(choice == 1); 
}

//function-to-get-the-length-of-the-LL
int length()
{
    int count = 0; 
    //iterate-through-all-node-and-get-length
    for(ptr = first; ptr != NULL; ptr = ptr->next)
    {
        count++; 
    }
    return count; 
}

//function-to-perform-bubble-sort
void bubblesort()
{
    int i, len = length(); 
    //to-iterate-till-the-length-of-list
    for(i = 0; i < len; ++i)
    {
        //pointers-to-shift-nodes
        struct node* prev = NULL;  //to-keep-track-of-last-shifted-node
        struct node* current = first;  
        struct node* n;
        while(current != NULL && current->next != NULL)
        {
            //when-data-of-current-greater-than-next-node
            if(current->data > current->next->data)   //swapping-condition
            {
                if(prev == NULL)  //first-iteration
                {
                    n = current->next; 
                    current->next = n->next; 
                    n->next = current; 
                    first = prev = n; 
                }
                //after-first-iteration
                else 
                {
                    n = current->next; 
                    prev->next = n; 
                    current->next = n->next; 
                    n->next = current; 
                    prev = n; 
                }
            }
            //data-of-current-is-smaller-next-node
            else 
            {
                n = current->next; 
                prev = current; 
                current = n; 
            }
        }
    }
}
