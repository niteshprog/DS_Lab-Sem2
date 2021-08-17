#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial{
	float coeff; 
	int power; 
	struct polynomial* next; 
}poly;

void display(struct polynomial* p); 
poly* getPoly(); 
poly* addPoly(poly* poly1, poly* poly2); 


void main()
{
	poly* poly1, *poly2, *finalpoly; 
	printf("Enter the details for the first polynomial:\n");
	printf("Use one power only once to avoid unecessary crowding.\n");
	printf("-------------------------------------------\n"); 
	poly1 = getPoly(); 
	printf("First polynomial:"); 
	display(poly1); 
	printf("\n\nEnter the details for the second polynomial:\n");
	printf("Use one power only once to avoid unecessary crowding.\n");
	printf("-------------------------------------------\n"); 
	poly2 = getPoly(); 
	printf("Second Polynomial:"); 
	display(poly2);
	finalpoly = addPoly(poly1, poly2); 
	printf("\n\nThe addition of these two polynomials is:  "); 
	display(finalpoly);  
}

void display(struct polynomial* p)
{
	poly* currentterm; 
	for(currentterm = p; currentterm != NULL; currentterm = currentterm->next)
	{
		if(currentterm->power == 1)
		{
			printf("%.1fx", currentterm->coeff); 
		}
		else if(currentterm->power == 0)
		{
			printf("%.1f", currentterm->coeff); 
		}
		else
		{
			printf("%.1fx^%d", currentterm->coeff, currentterm->power); 
		}
		if(currentterm->next != NULL)
		{
			printf(" + "); 
		}
	}
}

poly* getPoly()
{
	int flag, lc, get; 
	poly* newterm, *currentterm, *firstterm = NULL; 
	currentterm = malloc(sizeof(poly)); 
	do{
	
		printf("\n"); 
		newterm = malloc(sizeof(poly)); 
		printf("Power:"); 
		scanf("%d", &newterm->power); 
		printf("\nCoefficient for x^%d:", newterm->power); 
		scanf("%f", &newterm->coeff); 
		newterm->next = NULL;
		if(firstterm == NULL)
		{
			firstterm = newterm ; 
			currentterm = newterm; 
		}
		else
		{
			currentterm->next = newterm; 
			currentterm = newterm; 
		}
	
		printf("Do you want to enter more terms(y=1/n=0):\n");
		scanf("%D", &get); 
		if(get == 1)
		{
			newterm->next = malloc(sizeof(poly));
			newterm = newterm->next;
			newterm->next = NULL;
		}
		else if (get == 0)
		{
			printf("Insertion done!\n"); 
			printf("_______________\n");
		}
		else
		printf("Invalid Input!\n"); 
}
		while(get == 1); 
	return firstterm; 
}

poly* addPoly(poly* poly1, poly* poly2)
{
	poly* finalpoly, *pol; 
	pol = malloc(sizeof(poly)); 
	finalpoly = pol; 
	while(poly1 != NULL && poly2 != NULL)
	{ 
		if(poly1->power > poly2->power)
		{
			finalpoly->coeff = poly1->coeff; 
			finalpoly->power = poly1->power; 
			poly1 = poly1->next; 
		}
		else if(poly2->power > poly1->power)
		{
			finalpoly->coeff = poly2->coeff; 
			finalpoly->power = poly2->power; 
			poly2 = poly2->next; 
		}
		else
		{
			finalpoly->coeff = poly1->coeff + poly2->coeff; 
			finalpoly->power = poly2->power; 
			poly1 = poly1->next; 
			poly2 = poly2->next; 
		}
		if (poly1 || poly2)
		{
			finalpoly->next = malloc(sizeof(poly)); 
			finalpoly = finalpoly->next; 
			finalpoly->next = NULL; 
		}
		else
		{
			finalpoly->next = NULL; 
		}
	}
//	while(poly1 != NULL || poly2 != NULL)
//	{
//		if(poly1 != NULL)
//		{
//			finalpoly->coeff = poly1->coeff; 
//			finalpoly->power = poly1->power; 
//			poly1 = poly1->next; 
//		}
//		else if(poly2 != NULL)
//		{
//			finalpoly->coeff = poly2->coeff; 
//			finalpoly->power = poly2->power; 
//			poly2 = poly2->next; 
//		}
//		if(poly1 || poly2)
//		{
//			finalpoly->next = malloc(sizeof(poly)); 
//			finalpoly = finalpoly->next; 
//			finalpoly->next = NULL; 
//		}
//		else
//		{
//			finalpoly->next = NULL; 
//		}
	}
	return pol; 

}
