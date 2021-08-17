//header-files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//defining-size-of-array
#define size 10

//function-prototype
void clear();
int getkey(float data);
void createnode(float temp);
void show();
void insert(float data, int key);
void search(float get, int key);

//structure-body
struct node
{
    float data;
    struct node *next;
} *new = NULL, *ptr = NULL;

//declaration-of-array
struct node *table[size] = {NULL};

int main()
{
    float data, get;
    int job, key;
    //display-menu-and-get-job-from-user
    menu:
    printf("   MENU   ");
    printf("\n----------");
    printf("\n1.Insert element\n2.Search\n3.Display\n4.Exit\nChoice: ");
    scanf("%d", &job);
    //switch-between-job-and-invoke-resepctive-function
    switch (job)
    {
    case 1:
        printf("\nEnter the element to enter(0-100): ");
        scanf("%f", &data);
        //validate-input
        if(data > 100.00)
        {
            printf("\nYou tried to enter a number greater than 100...try again"); 
            break;
        }
        key = getkey(data);
        insert(data, key);
        break;
    case 2:
        printf("\nEnter the element to search: "); 
        scanf("%f", &get);
        if(get > 100.00)
        {
            printf("\nYou tried to enter a number greater than 100...try again"); 
            break;
        }
        key = getkey(get); 
        search(get, key);
        break;
    case 3:
        show();
        break;
    case 4:
        exit(0);
    default:
        //handle-invalid-input-from-user
        printf("\nInvalid Input..Try a valid one!");
        break;
    }
    //clear-screen-and-ask-for-next-job
    clear();
    system("clear");
    goto menu;
    return 0;
}

//function-for-clearing-buffer
void clear()
{
    while ((getchar()) != '\n');
    printf("\nPress Enter to continue...");
    getchar();
}

//function-for-getkey
int getkey(float data)
{
    //calculate-key
    float temp = data / 10.0000;
    temp = ceil(temp);
    int key = temp;
    //return-key(index)
    if (key == 0)
    {
        return 0;
    }
    else
    {
        return (key - 1);
    }
}

//function-defination-of-createnode
void createnode(float temp)
{
    //DMA-for-new-node
    new = malloc(sizeof(struct node));
    //validate-memory-allocated
    if (new == NULL)
    {
        printf("\nMemory Allocation failed..");
    }
    else
    {
        //set-value-for-node
        new->data = temp;
        new->next = NULL;
    }
}

//function-defination-of-insert
void insert(float data, int key)
{
    float temp = data;
    //call-createnode-function
    createnode(temp);
    //check-and-place-new-node-at-appropriate-function
    if (table[key] == NULL)
    {
        table[key] = new;
    }
    else
    {
        ptr = table[key]; 
        new->next = ptr; 
        table[key] = new; 
    }
    //notify-user-for-successfull-insertion
    printf("\nInsertion done!");
}

//function-defination-for-printing-all-data-in-table
void show()
{
    printf("\nPosition        Data");
    printf("\n====================");
    //traverse-through-array-and-print-all-Linked-lists
    for (int i = 0; i < size; i++)
    {
        //check-for-underflow
        if (table[i] == NULL)
        {
            printf("\n%d               Index Empty", i + 1);
        }
        //if-not-underflow-then-insert-at-appropriate-function
        else
        {
            printf("\n%d               ", i + 1);
            for (ptr = table[i]; ptr != NULL; ptr = ptr->next)
            {
                printf("%.1f", ptr->data);
                if (ptr->next != NULL)
                {
                    printf(", ");
                }
            }
        }
    }
}

//function-defination-for-searh
void search(float get, int key)
{
    //counter-to-keep-monitor-of-frequency
    int count = 0; 
    //traverse-through-whole-List-at-that-index
    for(ptr = table[key]; ptr != NULL; ptr = ptr->next)
    {
        //condition-for-element-found
        if(ptr->data == get)
        {
            count++; 
        }
    }
    //element-not-found
    if(count == 0)
    {
        printf("\nElement not found in the hash table.");
    }
    //details-of-element-found
    else
    {
        printf("\nElement found!!\nIndex: %d\nFrequency: %d", key, count);
    }
}