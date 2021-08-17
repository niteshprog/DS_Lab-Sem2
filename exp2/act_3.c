#include<stdio.h>
#include<stdlib.h>
typedef struct qeq{
    int a, b, c; 
}qeq; 

void main()
{
	qeq *eq = malloc(sizeof(qeq)); 
	int i; 
	input:
	printf("Standard format of equation = ax^2 + bx +c\n"); 
	for (i = 0; i < 2; ++i)
	{
		printf("\nEnter the coeff. of x^2:\n"); 
		scanf("%d", &eq[i].a); 
		printf("Enter the coeff. of x:\n"); 
		scanf("%d", &eq[i].b); 
		printf("Enter the value of constant:\n"); 
		scanf("%d", &eq[i].c); 
		printf("Eq %d: %dx^2 + %dx + %d\n", i+1, eq[i].a, eq[i].b, eq[i].c); 
	}
//	printf("\nEnter the information of third eq.:\n"); 
}
