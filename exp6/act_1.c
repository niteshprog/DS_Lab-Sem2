#include<stdio.h>
#include<stdlib.h>

struct body{
	int data; 
	struct body *next; 
}*temp = NULL, *ptr = NULL;

struct body *table[10]; 

int hashfunction(int id); 
void map(int key, int id); 
void createnode(int id)
{
	temp = malloc(sizeof(struct body));
	temp->data = id; 
	temp->next = NULL; 
}
void display(); 

int main()
{
	int id, key; 
	printf("\nEnter the SAP Id: "); 
	scanf("%d", &id); 
	key = hashfunction(id); 
	map(key, id); 
	display(); 
	return 0; 
}

int hashfunction(int id)
{
	int temp, sum = 0; 
	temp = id % 5000000; 
	while(temp / 10 != 0)
	{
		sum = sum + (temp % 10); 
		temp = temp / 10; 
	}
	if(sum > 10)
	{
		temp = sum; 
		sum = 0; 
		while(temp / 10 != 0)
		{
			sum = sum + (temp % 10); 
			temp = temp / 10; 
		}
		return sum; 
	}
	else
	{
		return sum; 
	}
}

void map(int key, int id)
{
	
		int n = id;
		createnode(id); 
 
	ptr = table[key]; 
	if(ptr == NULL)
	{
		ptr = temp; 
	}
	else 
	{
		for(ptr = table[key]; ptr->next != NULL; ptr = ptr->next); 
		ptr->next = temp; 
	}
}

void display()
{
	int i;
	printf("\nFAMILIY   ||   IDs\n");
	for(i = 0; i < 10; ++i)
	{
		printf("%d   ||   %s", i+1, *((table)+i)); 
		printf("\n"); 
	}
}
