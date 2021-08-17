//header-files
#include<stdio.h>
#include<stdlib.h>

//size-of-list
int n;

//structure-body
struct node
{
    int data; 
    struct node *next; 
}*new = NULL, *ptr = NULL, *first = NULL;

//function-prototype
void clear(); 
void createnode(); 
void createlist(); 
void show(); 
void linearsearch(); 

//main-function
int main()
{
    int job; 
    //create-the-list
    printf("Creating the list:- "); 
    createlist(); 
    clear(); 
    system("clear"); 
    //display-menu-and-get-job-from-user
    menu: 
    printf("   Menu   "); 
    printf("\n----------"); 
    printf("\n1.Display\n2.Perform Linear Search\n3.Exit\nChoice: "); 
    scanf("%d", &job); 
    //using-switch-case-invoke-respective-function
    switch (job)
    {
    case 1:
        show();
        break;
    case 2: 
        linearsearch(); 
        break; 
    case 3: 
        exit(0); 
    //to-handle-invalid-input
    default:
        printf("\nInvalid Choice..Try with a valid one.."); 
        break;
    }
    clear(); 
    system("clear"); 
    //return-to-menu-to-get-other-job
    goto menu;
    return 0; 
}

//function-for-clearing-buffer
void clear()
{
    while((getchar()) != '\n');
    printf("\nPress Enter to continue..."); 
    getchar(); 
}

//function-defination-of-createnode
void createnode()
{
    //DMA-for-new-node
    new = malloc(sizeof(struct node));
    //validate-memory-allocated
    if(new == NULL)
    {
        printf("\nMemory Allocation failed.."); 
    }
    else
    {
        //get-and-set-data-value-for-node
        printf("\nEnter the data: "); 
        scanf("%d", &new->data); 
        new->next = NULL; 
    }
}

//function-defination-of-createlist
void createlist()
{
    //get-the-number-of-elements-in-the-list
    printf("\nEnter the elements you want to enter in the list: "); 
    scanf("%d", &n); 
    //get-element-for-list
    for(int i = 1; i <= n; i++)
    {
        createnode(); 
        //check-if-first-element-is-to-be-inserted
        if(first == NULL)
        {
            first = new; 
        }
        //add-element-at-end-using-end-insertion-algo
        else
        {
            for(ptr = first; ptr->next != NULL; ptr = ptr->next); 
            ptr->next = new; 
        }
        //notify-for-successful-insertion
        printf("\nElement Insertion Done!"); 
    } 
}

//function-defination-of-show
void show()
{
    //check-for-empty-list
    if(first == NULL)
    {
        printf("\nList is empty.."); 
    }
    //if-not-empty-then-traverse-print-all-elements
    else 
    {
        printf("\nList: "); 
        for(ptr = first; ptr != NULL; ptr = ptr->next)
        {
            printf("%d ", ptr->data); 
        } 
    }
}

//function-defination-of-linearsearch
void linearsearch()
{
    int key, count = 0, i = 1; 
    //get-the-number-to-search
    printf("\nEnter the element to search: "); 
    scanf("%d", &key); 
    //set-ptr-to-first-node
    ptr = first; 
    while(ptr != NULL)
    {
        //match-the-key-and-ptr-data
        if(ptr->data == key)
        {
            //prompt-if-found
            printf("\n%d found at position: %d", key, i); 
            //increment-count
            count++; 
        }
        ptr = ptr->next; 
        i++; 
    }

    //either-list-empty-or-element-not-found
    if(count == 0 )
    {
        printf("\nElement not found.."); 
    }
    //number-of-occurrences-of-element
    else
    {
        printf("\n%d occured %d times in the list.", key, count); 
    }
}