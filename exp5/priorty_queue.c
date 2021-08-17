#include<stdio.h>
#include<stdlib.h>

//Clears the buffer memory
void clear (void) 
{    
  while ( getchar() != '\n' );
}

//variable-to-control-underflow-and-overflow
int first = -1; 

//function-prototypes
int insert(int size, int *queue, int i); 
int display(int size, int *queue, int i);
int delete(int size, int *queue, int i); 
//int search(int size, int *queue, int i); 

int main()
{
	//get-the-size-of-queue
	int size; 
	printf("Enter the size of the queue: "); 
	scanf("%d", &size);  
	printf("\nProvided size: %d", size); 
	printf("\n-------------------------------"); 
	//DMA-for-queue
	int *queue; 
	queue = malloc(size*sizeof(int)); 
	clear(); 
	printf("\nPress any key to continue...."); 
	getchar(); 
	system("clear"); 
	int i; 
	menu:
	//display-the-options-of-menu-and-get-operation-from-user
	printf("\nEnter you choice:\n1.Add element to the queue\n2.Display\n3.Delete Elements\n4.Exit\n");
	int job; 
	printf("\nCHOICE: "); 
	scanf("%d", &job);  
	system("clear"); 
	//invoke-respective-function-according-to-the-choice 
	switch(job)
	{
		case 1: 
			printf("\nLet's add element in the last of the queue: "); 
			printf("\n==========================================="); 
			insert(size, queue, i); 
			break; 
		case 2: 
			printf("\nPresent queue is: "); 
			printf("\n=================\n"); 
			display(size, queue, i); 
			break; 
		case 3: 
			printf("\nDeletion: "); 
			printf("\n=========="); 
			delete(size, queue, i); 
			break;
		case 4: 
			exit(0); 
		//handle-the-invalid-input-by-the-user
		default: 
			printf("\nEnter a valid input."); 
			break;
	 } 
	 //clear-the-console
	clear(); 
	printf("\nEnter to continue: "); 
	getchar(); 
	system("clear"); 
	goto menu; 
	return 0; 
}	

//function-to-insert-element-in-the-queue
int insert(int size, int *queue, int i)
{
	int proceed; 
	i = 0;
	do{
		//check-for-overflow
		if(first == size-1)
	{
		printf("Queue Full can't add more elements! Try after some deletion!\n");
		printf("\n-------------------------------");
		return 0;  
	}
	//if-not-overflow-then-add-element-in-the-end-of-queue-and-increase-counter-by-one
	else
	{
			//if-the-queue-is-empty
			if(first == -1)
					{
						printf("\nPresent members in the queue: %d", first+1); 
						printf("\nList is empty!\nEnter your first element: "); 
						scanf("%d", ((queue)+i)); 
						printf("Element Inserted...at address: %p", ((queue)+i)); 
						printf("\n-------------------------------");
						first ++; 	
						i++; 
					}
			//if-it-is-not-empty
			else
			{
				printf("\nPresent members in the queue: %d", first+1); 
				printf("\nEnter the element: "); 
				scanf("%d", ((queue)+i)); 
				printf("Element Inserted...at address: %p", ((queue)+i)); 
				printf("\n-------------------------------");
				first ++; 
				i++; 
			}
			//ask-if-the-user-want-to-add-more-element
			clear();
			yesorno:
			printf("\nDo you want to add more: Yes(1) or No(0)\nChoice: "); 
			scanf("%d", &proceed);
				
		}
	}while(proceed == 1); 
	
	return 0; 
}

//display-function
int display(int size, int *queue, int i)
{
	//check-for-underflow
	if(first == -1)
	{
		printf("\nQueue Underflow! No element in the queue to print...Add some and try again!!"); 
		printf("\n-----------------------------------------------------------------------------"); 
		return 0; 
	}
	//else-print-the-queue
	else
	{
		for(i = 0; i <= first; ++i)
		{
			printf("\nPriority: %d\nAddress: %p\nData: %d", i+1, ((queue)+i), *((queue)+i)); 
			printf("\n-------------------------------------"); 
		}
	}
	return 0; 
}

//delete-function
int delete(int size, int *queue, int i)
{

	int t;  
	//check-for-underflow
	if(first == -1)
	{
		printf("\nList is empty...Can't Delete"); 
		return 0; 
	}
	//else-delete-the-first-element-in-the-queue-as-first-come-first-go-rule
	else
	{
		//shift-the-elements-to-left
		for( i = 0; i < first; ++i)
		{
			//make-sure-shifting-doesn't-exceed-queue-size
			if(i < size)
			{
				t = i + 1; 
				*((queue)+i) = *((queue)+t); 
			}
			else{
				break; 
			}
		}
		first--; 
	}
	return 0;
}
