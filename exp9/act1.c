//header-files
#include<stdio.h>
#include<stdlib.h>

//size-of-array-to-hold-traversal
int size; 

//node-structure-body
struct node
{
    int data; 
    struct node *left; 
    struct node *right; 
}*new = NULL, *root = NULL, *ptr = NULL;

//function-prototypes
void clear(); 
void first(int index, int arr[]); 
void second(int index, int arr[]); 
void third(int arr[]);  

//main-function
int main()
{
    int job, index; 
    //get-the-size-of-the-tree
    printf("Enter number of elements in the tree: "); 
    scanf("%d", &size); 
    //number-of-parents-in-tree
    int count = (size)/2;
    //get-the-breadth-first-traversal
    int arr[size];  
    printf("\nEnter the breadth first traversal of the tree: "); 
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    //notify-traversal-obtained
    printf("Breadth First Traversal Obtained! "); 
    clear(); 
    system("clear"); 

    menu: 
    printf("\n\tMENU\t"); 
    printf("\n==========================="); 
    printf("\n1. Get parent and children for any position\n2. Get all children-parent combo in tree\n3. Get all leaf nodes\n4. Exit\nChoice: "); 
    scanf("%d", &job); 
    //invoke-suitable-function-using-switch-case
    switch (job)
    {
    case 1: 
        //get-position-user-wants-to-check
        ini:
        printf("\nEnter the position you want to check: "); 
        scanf("%d", &index); 
        //validate-position
        if(index < 1 || index > size)
        {
            printf("Index out of Range, select between 1-%d", size); 
            clear(); 
            system("clear"); 
            goto ini; 
        }
        //invoke-first-function
        else
        {
            first(index-1, arr); 
        }
        break;
    case 2: 
        //display-total-parents-in-tree
        printf("\nThis tree has total %d parents.", count);
        //visit-each-node-as-parent-and-print-child-nodes
        for(int i = 0; i < count; i++)
        {
            second(i, arr); 
        }
        break; 
    case 3: 
        //invoke-third-function
        third(arr); 
        break;
    case 4:   
        //exiting-program 
        exit(0); 
        break;
    default:
        //validate-job-input-by-user
        printf("\nInvalid Input, Please select a valid one.."); 
        break;
    }
    clear(); 
    system("clear"); 
    goto menu; 
    return 0; 
}

//function-for-clearing-buffer
void clear()
{
    while((getchar()) != '\n'); 
    printf("\nPress Enter to continue..");
    getchar(); 
}

//function-for-first-job
void first(int index, int arr[])
{
    int parent, lchild, rchild;
    //get-index-of-rightchild-leftchild-for-given-index 
    lchild = (2*index)+1; 
    rchild = (2*index)+2; 
    //now-if-element-exist-at-resp.-index-then-print-the-data
    //else-notify-not-found
    if(lchild < size)
        printf("\nLeft child of %d: %d.", arr[index], arr[lchild]); 
    else 
        printf("\nLeft child of %d: Not found", arr[index]); 
    if(rchild < size)
        printf("\nRight child of %d: %d.", arr[index], arr[rchild]); 
    else 
        printf("\nRight child of %d: Not found", arr[index]); 
    
    //if-the-index-passed-on-is-root
    if(index == 0)
    {
        printf("\nParent doesn't exist, because the node you selected is root of the tree."); 
    }
    //if-not-root-then-print-its-parent
    else
    {
        parent = (index-1)/2; 
        printf("\nParent of %d: %d", arr[index], arr[parent]); 
    }
}

//function-for-second-job
void second(int index, int arr[])
{
    //get-index-of-leftchild-and-rightchild
    int lchild, rchild; 
    lchild = (2*index)+1; 
    rchild = (2*index)+2;  
    
    //now-print-data-at-index-if-available
    printf("\nParent: %d", arr[index]) ; 
    if(lchild < size)
        printf("\nLeft child of %d: %d.", arr[index], arr[lchild]); 
    else 
        return; 
    if(rchild < size)
        printf("\nRight child of %d: %d.", arr[index], arr[rchild]); 
    else 
        return;  
    
}

//function-for-third-job
void third(int arr[])
{
    //traverse-through-whole-tree-and-check-if-it-is-leaf-not
    printf("\nLeafs present in the tree is/are: ");  
    for(int i = 0; i < size; i++)
    {
        //if-not-leaf-jump-to-next-node
        if(((i*2)+1)  < size)
            continue; 
        //if-leaf-print-its-data
        else 
            printf("%d ", arr[i]);
    }
 }