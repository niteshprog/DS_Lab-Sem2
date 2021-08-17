//Reverse a string using stack implemented with Dynamic 1D Array.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//initialize some variables
int first = -1; 
int size; 

//prototypes
void push(char *stack, char *phrase); 
void pop(char *stack); 

//main function
int main()
{
  
    //get the size of the phrase
	printf("Enter the size of the phrase: "); 
    scanf("%d", &size); 
    //dynamically allocate memory for the phrase and the stack
    char *phrase; 
    phrase = malloc(size*sizeof(char)); 
    char *stack; 
    stack = malloc(size*sizeof(char)); 
    //validate the memory allocated to the stack and the phraseN
    if(stack == NULL)
    {
    	printf("Stack Memory allocation failed!\n"); 
    	exit(0); 
	}
	 if(phrase == NULL)
    {
    	printf("Phrase Memory allocation failed!\n"); 
    	exit(0); 
	}
	//clear the buffer
    while((getchar()) != '\n');
    //get the phrase
    printf("Enter the phrase: "); 
    scanf("%[^\n]%*c", phrase); 
    //push the characters in the stack
    push(stack, phrase);
    //pop the characters from the stackv and display them
    pop(stack);
    return 0; 
}

void push(char *stack, char *phrase)
{
    int i; 
    //check for overflow
    if(first >= size-1)
    {
        printf("Pushing failed because of Stack Overflow!\n"); 
        return;  
    }
    //if not overflow then push the characters in the stack
    else
    {
     for(i = 0; i < size; ++i)
        {
           first++; 
           *(stack+first) = *(phrase+i); 
        }
    }
   
}

void pop(char *stack)
{
    //check for underflow
	if(first == -1 )
    {
        printf("We can't print because ofStack Underflow!\n");
        return;
    }
    //if not underflow then pop the characters from the stack and display them
    else
    {
        while(first >= 0)
        {
             printf("%c", *((stack)+first)); 
             first--; 
        }
    }
}
