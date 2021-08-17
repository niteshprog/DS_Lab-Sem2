#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int flag=0;

struct eqn
{

    float a,b,c,r1,r2;
    struct eqn* next;

}*first,*last,*temp;

void display(struct eqn* e)
{
	printf("\nEquation no. 1: %fx^2 + %fx + %f", e->a, e->b, e->c);
}

void calculate_eqn(struct eqn* e)
{
	e->a=1;
	e->b = -(e->r1 + e->r2);
    e->c = (e->r1)*(e->r2);	//Calculating coeffs according to roots formula
}

void calculate_roots(struct eqn* e1, struct eqn* e2, struct eqn* sop, int sum)
{
	float d;
	d=4*(e1->r2+e2->r2)*(e1->r2+e2->r2)-4*(e1->r2*e2->r2-sum);
	if(d>=0) //checking for valid determinant(no complex root)
	{
		sop->r1=-(2*(e1->r2+e2->r2) + sqrt(d))/2;
		sop->r2=-(2*(e1->r2+e2->r2) - sqrt(d))/2; //calculating roots of sum of products equation
	}
	else
	flag=1;
}

int main()
{
    struct eqn eqn1, eqn2, eqn3, sop;
	float d, sum;
    printf("\nEnter the coefficient of x^2: "); //Inputting details of 3rd equation
    scanf("%f",&eqn3.a);
    printf("\nEnter the coefficient of x: ");
    scanf("%f",&eqn3.b);
    printf("\nEnter the Constant: ");
    scanf("%f",&eqn3.c);
    d= (eqn3.b*eqn3.b)-(4*eqn3.a*eqn3.c); //calculating determinant of 3rd eqn
    if(d<0) //checking if 3rd eqn has complex roots
    {
        printf("Roots are complex!! Can't proceed.");
        exit(0); // exit if complex root
    }
    if(d==0)
    {
        eqn3.r1= -eqn3.b/2*eqn3.a;
        eqn3.r2= -eqn3.b/2*eqn3.a;
        if(eqn3.r1<0 || eqn3.r2<0) // Checking for negative roots
        {
            printf("Roots are negative, cant proceed!");
            exit(0); //Exit if either is negative
        }
    }
    if(d>0)
    {
        eqn3.r1=(-eqn3.b + sqrt(d))/(2*eqn3.a);
        eqn3.r2=(-eqn3.b - sqrt(d))/(2*eqn3.a);
        if(eqn3.r1<0 || eqn3.r2<0) // Checking for negative roots
        {
            printf("Roots are negative, cant proceed!");
            exit(0); //Exit if either is negative
        }
    }
    printf("\nEnter sum of products: ");
    scanf("%f", &sum); //inputting sum of products
	eqn1.r2=eqn3.r1;
	eqn2.r2=eqn3.r2; //assigning uncommon roots
	calculate_roots(&eqn1, &eqn2, &sop, sum);
	if(flag==1)
	{
		printf("Solution doesn't exists!");
		exit(0);
	}
	if(sop.r1>0) //checking for validity of common root
	{
		printf("\nWhen common root is: %f", sop.r1);
		eqn1.r1=eqn2.r1=sop.r1;
		calculate_eqn(&eqn1);
		calculate_eqn(&eqn2); //calculating eqn according to roots
		display(&eqn1);
		display(&eqn2);
	}
	if(sop.r2>0) //checking for validity of common root
	{
		printf("\nWhen common root is: %f", sop.r2);
		eqn1.r1=eqn2.r1=sop.r2;
		calculate_eqn(&eqn1);
		calculate_eqn(&eqn2); //calculating eqn according to roots
		display(&eqn1);
		display(&eqn2);
	}
    return 0;
    
}
