//header-files
#include<stdio.h>
#include<stdlib.h>

//function-prototypes
void clear();
void display(int arr[], int n); 
int linearsearch(int arr[], int n);
void bubblesort(int arr[], int n); 
void binarysearch(int arr[], int n);

//main-function
int main()
{
    int n, i = 0, job; 
    //get-the-size-of-the-array
    printf("Enter the size of the array: "); 
    scanf("%d", &n); 
    //declare-array-of-size(n)
    int arr[n]; 
    //get-the-elements-for-the-array
    printf("\nEnter the elements of array: \n"); 
    while(i < n)
    {
        scanf("%d", &arr[i]); 
        i++; 
    }
    clear(); 
    system("clear");
    //display-menu-and-ask-for-job
    menu:  
    printf("\n   MENU"); 
    printf("\n------------"); 
    printf("\n1.Display\n2.Operate Linear Search\n3.Operate Binary Search\n4.Exit"); 
    printf("\nChoice: ");
    scanf("%d", &job); 
    //call-respective-functions-using-switch-case
    switch(job)
    {
        case 1: 
            display(arr, n); 
            break; 
        case 2: 
            linearsearch(arr, n); 
            break ;
        case 3:
            //sort-array-then-apply-binary-search
            bubblesort(arr, n); 
            binarysearch(arr, n); 
            break;
        case 4: 
            exit(0);
        //to-handle-invalid-input-from-user 
        default: 
            printf("\nInvalid Option Selected, Choose a valid one.."); 
            break; 
    }
    clear(); 
    system("clear"); 
    //iterate-menu-until-user-exit-the-program
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

//function-defination-for-display-function
void display(int arr[], int n)
{
    //using-for-loop-print-all-the-elements-of-array
    printf("\nThe array is: "); 
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); 
    }
}

//function-defination-for-linearsearch-function
int linearsearch(int arr[], int n)
{
    int count = 0,data; 
    //ask-for-the-element-to-search
    printf("\nEnter the number to search: "); 
    scanf("%d", &data);
    //check-every-index-presence-of-the-element
    for(int i = 0; i < n; i++)
    {
        //if-available-then-prompt-with-index
        if(arr[i] == data)
        {
            printf("\n%d found at location %d.", data, i+1); 
            count++; 
        }
    }
    //prompt-if-element-is-not-found
    if(count == 0)
    {
        printf("\nElement not found....");
    }
    //prompt-number-of-times-element-was-found
    else 
    {
        printf("\n%d occured %d times in the array.", data, count); 
    }
    return 0; 
}

//function-defination-for-bubblesort-function
void bubblesort(int arr[], int n)
{
    int temp; 
    //access-nth-and-(n-1)th-element-using-loop
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            //Swapping Condition is Checked
            if(arr[j]>arr[j+1]) 
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//function-defination-for-binary-search
void binarysearch(int arr[], int n)
{
    //get-highest-lowest-and-mid-index
    int key, low = 0, high = n-1; 
    int mid = (low+high)/2; 
    //get-key-to-search
    printf("\nEnter the number to search in the array: "); 
    scanf("%d", &key);
    //divide-the-array-till-condition 
    while(low <= high)
    {
        //if-mid-element-smaller-than-key
        if(arr[mid] < key)
        {
            low = mid+1; 
            mid = (low+high)/2; 
        }
        //if-key-is-in-middle-of-array
        else if(arr[mid] == key)
        {
            printf("\nElement found at position: %d", mid+1); 
            break; 
        }
        //if-mid-element-bigger-than-key
        else 
        {
            high = mid -1; 
            mid = (low+high)/2; 
        }
    }
    //if-array-is-no-more-divisible
    if(low > high)
    {
        printf("\nData not found..."); 
    }
}