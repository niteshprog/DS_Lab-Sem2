#include<stdio.h>
#include<stdlib.h>

//structure-body-type-and-some-pointers-for-pop-push-and-traversal
struct node{
	char data;
	struct node *next; 
}*first = NULL,*last = NULL, *temp, *ptr;

//create-a-node
void createnode(char keyword)
{
	//dynamically-allocate-memory-to-the-node
	temp = malloc(sizeof(struct node)); 
	//set-data-and-next-of-node
	temp->data = keyword ;  
	temp->next = NULL; 
}

//function-for-pushing-character-in-the-queue
void push(char keyword, struct node *list)
{
	char tp = keyword; 
	list = first; 	
	//invoke-createnode-function-to-create-a-node
	createnode(tp); 
	//now-check-if-the-queue-is-empty
	if(first == NULL)
	{ 
		first = temp; 
		last = temp; 
	}
	//check-if-queue-has-only-one-element
	else if(first->next == NULL){
		first->next = temp; 
		last = last->next; 
	}
	//if-has-more-than-elements-link-node-to-last
	else 
	{
		last->next = temp; 
		last = last->next; 	
	}
}

//function-for-popping-out-the-element
char pop(struct node* list)
{
	//declare-a-temporary-variable-that-will-hold-popped-out-value
	char val = 0; 
	if(first == NULL)
	{
		printf("\nNothing to pop out..."); 
		return val; 
	}
	//check-if-the-queue-has-only-one-element
	else if(first->next == NULL)
	{
		val = first->data;
		first = NULL; 
		last = NULL;  
		return val; 
	}
	//if-the-queue-has-more-than-one-element
	else 
	{
		val = first->data; 
		first = first->next; 
		return val;	
	}
}

//main-function
int main()
{
	//define-variable-for-size-of-string,-loop-controller,-and-counter
	int size, i, counter = 1; 
	
	//declare-a-structure-variable
	struct node *list; 
	
	//get-the-size-of-string-from-the-user
	printf("\nEnter the size of the string: "); 
	scanf("%d", &size);
	
	//define-a-character-array-of-given-size
	//get-the-string-from-the-user
	char word[size]; 
	printf("\nEnter the word: "); 
	scanf("%s", word); 
	
	//show-the-entered-word
	printf("\nWord enterd by you: %s", word);
	
	//take-each-character-of-the-string-and-push-in-the-queue 
	for(i = 0; i < size; ++i)
	{
		push(word[i], list); 
	}
	
	//pop-first-element-of-the-queue-and-compare
	for(i = size-1; i >=0; --i)
	{
		//if-equal-set-counter-to-1
		if(pop(list) == word[i])
		{
			counter = 1; 
		}
		//if-unequal-set-counter-to-0
		else if(pop(list) != word[i])
		{
			counter = 0; 
			break;
		}
		//if-some-error-happens
		else{
			printf("\nSome error happened..."); 
		}
	}
	
	//via-value-of-counter-print-the-result-palindrome-or-not
	if(counter == 1)
	{
		printf("\nWord is palindrome\n"); 
	}
	else if(counter == 0)
	{
		printf("\nNot a palindrome word\n"); 
	}
	else
		return 0; 
	printf("=========================================\n"); 
	return 0; 
}

