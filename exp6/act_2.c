#include <stdio.h>
#include<stdlib.h>

int count=0,size;

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

void display(int table[])
{
    printf("Family |    SAP-Id\n");
    printf("------------------\n");
    for(int i=0;i<=size-1;i++)
    {
        if(i<10)
        {
            if(table[i]==-1) printf(" %d  |   ~~\n",i);
            else    printf(" %d  |   %d\n",i,table[i]);
        }
        else
        {
            if(table[i]==-1) printf(" %d |   ~~\n",i);
            else    printf(" %d  |   %d\n",i,table[i]);
        }
    }

    return;
}

//insert-function
void insert(int table[])
{
    //get-sap
	int sap;
    printf("Enter the SAP ID of the student: ");
    scanf("%d",&sap);
    
    //get-key-from-getkey-function
    int index=getkey(sap);
    
    //allocate-data
    if(table[index]==-1)  
    {
        table[index]=sap;
    }
    else
    {
        for(int i=index+1;i<=index+(size-1);i++)
        {
            if(i<=size-1)
            {
                if(table[i]==-1)
                {
                    table[i]=sap;
                    break;
                }
            }
            else
            {
                if(table[i-size]==-1)
                {
                    table[i-size]=sap;
                    break;
                }
            }
        }
    }
    return;
}

//delete-function
void delete(int table[])
{
    int index;
    //get-the-key-you-want-to-delete
	printf("Enter the key number where you want to delete: ");
    scanf("%d",&index);
    //delete-the-element
    table[index]=-1;
    //decrement-the-count
    count--;
}

//search_function
void search(int table[])
{
    //get-the-id-to-search
	int sap;
    printf("Enter the SAP ID to be searched: ");
    scanf("%d",&sap);
    
    //hash-the-key
    int index=getkey(sap);
    
    //search-through-the-array
    if(table[index]==sap)  
    {
        printf("The element '%d' is fount in position(key) '%d'.\n",table[index],index);
    }
    else
    {
        for(int i=index+1;i<=index+(size-1);i++)
        {
            if(i<=size-1)
            {
                if(table[i]==sap)
                {
                    printf("The element '%d' is fount in position(key) '%d'.\n",table[index],i);
                    break;
                }
            }
            else
            {
                if(table[i-size]==sap)
                {
                    printf("The element '%d' is fount in position(key) '%d'.\n",table[index],i);
                    break;
                }
            }
        }
    }
    return;
}

//main-function
int main()
{
    int job;
    //get-the-size-of-array
	printf("Enter the size of Hash Table: ");
    scanf("%d",&size);
    int table[size];
    
    for(int i=0;i<=size-1;i++)   table[i]=-1;
    //display-menu-and-get-job-and-invoke-respective-function
	do{
        printf("\n1.Insert\n2.Delete\n3.Search\n0.Exit\nEnter your Choice: ");
        scanf("%d",&job);
        if(job==1)   
        {
            if(count<size)   
            {
                insert(table);
                count++;
            }
            else
            {
                printf("Hash table is full ! Cannot insert.\n");
            }
            display(table);
        }
        else if(job==2)   
        {
            delete(table);
            display(table);
        }
        else if(job==3)   
        {
            search(table);
        }
            
    }while(job!=0);   
    return 0;
}
