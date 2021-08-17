#include <stdio.h>

#define max 50
int top = -1, size;
float st[max];  


void push(float st[], float val); 
float pop(float st[]); 
float evaluate(char exp[]); 

int main()
{
	float val; 
	printf("Enter the size of the expression(including operators): "); 
	scanf("%d", &size); 
//	float st[size];
	char exp[size]; 
	printf("Enter the postfix expression: ");
	while((getchar()) != '\n'); 
	fgets(exp, size, stdin); 
	val = evaluate(exp); 
	printf("\nEvaluated value of this postfix expression = %.2f ", val); 
	return 0; 
}

float evaluate(char exp[])
{
	int i = 0; 
	float op1, op2, value; 
	while(exp[i] != '\0')
	{
		if(isdigit(exp[i]))
		{
			push(st, (float)(exp[i] - '0')); 
		}
		else
		{
			op1 = pop(st); 
			op2 = pop(st); 
			switch(exp[i])
			{
				case '+':
					value = op1 + op2; 
					break; 
				case '-':
					value = op1 - op2; 
					break; 
				case '*':
					value = op1 * op2; 
					break; 
				case '/':
					value = op1 / op2; 
					break; 
				case '%':
					value = (int)op1 % (int) op2; 
					break; 
			}
			push(st, value); 
		}
		i++; 
	}
	return(pop(st)); 		
}

void push(float st[], float val)
{
	if(top == size -1)
	{
		printf("\nStack Overflow!\n"); 
		return; 
	}
	else 
	{
		top++; 
		st[top] = val; 
	}
}

float pop(float st[])
{
	float val = -1; 
	if (top == -1)
	{
		printf("\nStack Underflow!\n"); 
	}
	else 
	{
		val = st[top]; 
		top--; 
	}
	return val; 
}
