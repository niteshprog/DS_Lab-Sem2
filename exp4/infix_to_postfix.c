#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//create a node and create two pointers 
struct node
{
	char data;
	//self referential strucutre  
	struct node *next;
}*top=NULL,*pstart=NULL;


void insert(char ch)
{
	//create structure variables 
	struct node *t,*block;
    block=(struct node *)malloc(sizeof(struct node));
    block->next=NULL;
    block->data=ch;
    t=pstart;
	//check if the postfix list is empty 
    if(pstart==NULL)
    {
    	pstart=block;
    }
    //if not empty make suitable assignment 
    else
    {
	    while(t->next!=NULL)
	    t=t->next;
	    t->next=block;
    }
}


void push (char symbol)
{
    //declare structure variable and do DMA
	struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=symbol;
    //check for empty stack
    if(top==NULL)
    {
	    top=p;
	    p->next=NULL;
    }
    //if not empty then do suitable assignment 
    else
    {
	    p->next=top;
	    top=p;
    }
}

char  pop()
{
	//define two struct pointers and character to return 
	struct node *x,*y;
	char k;
	//check for underflow
	if(top==NULL)
	{
	    printf("stack underflow\n");
	    return 0;
	}
	//if not underflow then return(pop) elements out of stack
	else
	{
		x=top;
		top=top->next;
		k=x->data;
		free(x);
		x=NULL;
		return k;
	}
}


void displaypost()
{
    //define a local structure variable
	struct node *to;
	//check for empty stack
    if(pstart==NULL)
    {
		printf("Nothing to print!\n");
    }
	//if not empty then print the element in the list
    else
    {
	    to=pstart;
	    while(to!=NULL)
	    {
	        printf("%c",to->data);
	        to=to->next;
	    }
    }
}



int precedence(char ch)
{

	//define the priority of the symbols 
	if(ch=='^')
	return (5);
	else if(ch=='*' || ch== '/')
	return (4);
	else if (ch== '+' || ch== '-')
	return (3);
	else
	return (2);
}



void intopost(char infix[])
{
    //declare varibales and loop control
	int len;
    int index=0;
    char symbol,temp;
    len= strlen(infix);
    //read and perform the suitable action till the index of the stack is less than lenght of the infix
    while(len>index)
    {
        symbol=infix[index];
        switch(symbol)
        {
        	//check for parentheses 
        case '(':
	        push(symbol);
	        break;

        case ')':
	        temp=pop();
	        while(temp!='(')
	        {
		        insert(temp);
		        temp=pop();
	        }
	        break;
		//check for the priority of the operators  
        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
	        if(top==NULL)
	        {
	            push(symbol);
	        }
	        else
	        {
		        while(top!=NULL && (precedence(top->data)>=precedence(symbol)))
		        {
		            temp=pop();
		            insert(temp);
			 	}
		        push(symbol);
			 }   
	        break;
	        
        default:
	        insert(symbol);
	
	         }
	         index=index+1;
    }
    while(top!=NULL)
    {
	    temp=pop();
	    insert(temp);
    }
    displaypost();
    return;
}


int main()
{
	//declare ta variable for infix
	char infix[50];
	printf("enter infix expression: ");
	//get the infix from the user 
	fgets(infix, 50, stdin);
	//print the postfix form
	printf("\n\nequivalent postfix expression is---> ");
	intopost(infix);
	return 0;
}
