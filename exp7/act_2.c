//pre-headerfiles
#include<stdlib.h>
#include<stdio.h>

//function-prototypes
void clear();
int insert(int arr[], int size); 
int show(int arr[], int size); 
void InsertSort(int arr[], int size);
void selectionsort(int *arr, int size); 
void sort(int arr[],int first,int last);  
void merge(int arr[],int i1,int j1,int i2,int j2);
void quicksort(int arr[],int first,int last);

//main-function
int main()
{
    int size, job; 
    //get-the-size-of-the-array
    printf("\nEnter the size of the  array: "); 
    scanf("%d", &size);
	//declare-array 
    int arr[size]; 
    //insert-elements-in-array
    insert(arr, size);
    clear();
	//display-menu-and-get-the-job-from-user  
    menu:
	printf("\nMake a choice:"); 
	printf("\n--------------"); 
	printf("\n1.Insertion Sort\n2.Selection sort\n3.Merge sort\n4.Quick sort\n5.Display\n6.Exit\nChoice: "); 
	scanf("%d", &job); 
	//using-switch-case-invoke-respective-function
	switch(job)
	{
		case 1: 
			InsertSort(arr, size); 
			break; 
		case 2: 
			selectionsort(arr, size); 
			printf("\nSorting done"); 
			break; 
		case 3: 
			sort(arr,0,size-1); 
			printf("\nSorting done"); 
			break; 
		case 4: 
			quicksort(arr,0,size-1); 
			printf("\nSorting done"); 
			break; 
		case 5: 
			show(arr, size); 
			break; 
		case 6: 
			exit(0); 
			break; 
		default: 
			printf("\nInvalid input"); 
			break; 
	}
    clear();
    //cler-screen-and-ask-for-job-again
    goto menu;
    return 0;
}

//insert-function
int insert(int arr[], int size)
{
    int i; 
    printf("\nEnter the elements:\n"); 
    //using-loop-insert-elements-in-array
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]); 
    }
    return 0; 
}

//display-function
int show(int arr[], int size)
{
    int i; 
    printf("\nList: "); 
    //using-loop-display-all-the-elements-in-array
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); 
    }
    return 0; 
}

//function-for-insertsort
void InsertSort(int arr[], int size)
{
    int temp,i,j,k;
    //visit-the-elements-in-the-array
    for(i=1;i<size;i++)
    {
        temp=arr[i];
        j=i-1;
        //swapping-condition
        while((j>=0) && (arr[j]>temp))
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
        //display-all-the-step-in-swapping
        printf("\nPass %d: ",i);
        for(k=0;k<size;k++)
        {
            printf("%d ",arr[k]);
        }
    }
}

//function-for-selection-sort
void selectionsort(int *arr, int size)
{
    printf("\nRunning selection sort..."); 
    int i, j, minindex, temp; 
    for(i = 0; i < size-1; i++)
    {
        minindex = i; 
        for(j = i+1; j < size; j++)
        {
            if(arr[j] < arr[minindex])
            {
                minindex = j; 
            }
        }
        //swapping
        temp = arr[i]; 
        arr[i] = arr[minindex]; 
        arr[minindex] = temp; 
    }
}

//merging-the-two-arrays-function
void merge(int arr[],int i1,int j1,int i2,int j2)
{
	int temp[100];	
	int i=i1,j=i2,k=0;
	//merge-temp-arrays
	while(i<=j1 && j<=j2)
	{
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=j1)
		temp[k++]=arr[i++];
	while(j<=j2)	
		temp[k++]=arr[j++];
	//copy-elements-from-temp-array-to-initial-array
	for(i=i1,j=0;i<=j2;i++,j++)
		arr[i]=temp[j];
}

//sorting-array-for-merge-function
void sort(int arr[],int first,int last)
{
	int mid;
	if(first<last)
	{
		//get-the-mid-of-array
		mid=(first+last)/2;
		//recursively-spilt-the-arrays
		sort(arr,first,mid);		
		sort(arr,mid+1,last);	
		//compare-the-elements-merge-both-arrays
		merge(arr,first,mid,mid+1,last);
	}
}

//function-for-quicksort
void quicksort(int arr[],int first,int last)
{
   int i, j, pivot, temp;
   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;
      
      while(i<j)
      {
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j)
         {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      sort(arr,first,j-1);
      sort(arr,j+1,last);
   }
}

//function-to-clear-screen
void clear()
{
    while((getchar()) != '\n'); 
    printf("\nPress enter to continue.."); 
    getchar(); 
    system("clear"); 
}
