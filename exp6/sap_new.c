#include <stdio.h>
#include <stdlib.h>
//define-the-size-of-array
#define SIZE 10

//defining-structure-body
struct body
{
   int data;
   struct body *next;
};

//declare-an-array(size = SIZE)-and-pointer
struct body *table[SIZE]={NULL},*ptr;

//define-the-hash-function
int getkey(int sap)
{
   	//adding-the-last-three-digits-till-key-less-than-10
    int key=sap%10; 
	sap/=10;
    key+=sap%10; 
	sap/=10;
    key+=sap%10;
    key= key%10 + key/10;
    return key;
}

//define-insert-function
void insert()
{
    //declare-variable-for-id-and-key
	int i,id;
	//get-the-id
    printf("Enter a SAP ID: ");
    scanf("%d",&id);
    //get-the-key-by-calling-getkey-function
    i=getkey(id);
    //DMA-for-a-new-node
    struct body * newnode=(struct body *)malloc(sizeof(struct body));
    //set-the-id-to-data-and-set-next-to-null
    newnode->data=id;
    newnode->next = NULL;
    //check-if-the-list-is-empty
    if(table[i] == NULL)
		table[i] = newnode;
	//if-not-then-link-to-the-end
    else
    {
		ptr=table[i];
		while(ptr->next != NULL)
	   	{
	   		ptr=ptr->next;
		}
		ptr->next=newnode;
    }
    printf("Id inserted in the table!!"); 
}

//define-display-function
void display()
{
    //declare-variable(loop-controllers)
	int i;
	printf("Family     SAP ID");
	printf("\n-----------------");
	//using-for-loop-visit-each-index-in-array
    for(i=0;i<SIZE;i++)
  	{
   		printf("\n%d:         ",i);
   		//check-if-the-table-is-empty
		if(table[i] == NULL)
		{
			printf("No ID found in the family!");
		}
		//if-false-then-print-the-items-in-the-array
		else
		{
		  for(ptr=table[i];ptr!=NULL;ptr=ptr->next)
		    if(ptr->next != NULL)
		        printf("| %d, ",ptr->data);
	        else    
	            printf("%d",ptr->data);
		}
  	}
}

//defining-main-function
int main()
{
	//declare-some-variables
	int job,id,i = 1;
    while(i = 1)
    {
    	
    	//show-the-menu
    	printf("Menu\n================="); 
		printf("\n1.Insert\n2.Display\n3.Exit\nEnter choice:");
		//get-the-job
		scanf("%d",&job);
		//invoke-respective-function-for-respective-function
		switch(job)
		{
		    case 1:
		    	//invoking-insert-function-to-insert-id
				insert();
				break;
		    case 2:
		    	//invoke-display-items-in-the-table
				display();
				break;
		    case 3:
		    	//exit-the-program
				exit(0);
		    default:
		    	//handle-the-invalid-inputs-by-the-user
		    	printf("Enter Valid Choice!");
		}
		//clear-buffer-memory
		 while ( getchar() != '\n' );
		printf("\n\nPress enter to continue: "); 
	    getchar(); 
		system("clear"); 
	}return 0; 
}
