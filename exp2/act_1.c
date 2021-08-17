//To-find-sum-of-two-arrays
#include<stdio.h>

//create-structure
typedef struct complex{
	float real, img;
}complex;      //providing-the-aliasing-name-of-the-data-type

//function-prototype
complex add(complex c1, complex c2);     

//start-main
void main()
{
	//making-variables
	complex c1, c2, cf; 
	
	//get-inputs-for-the-resp.-complex-numbers
	printf("Complex Number 1:\n"); 
	printf("\nEnter the real and imaginary parts respectively:\n"); 
	scanf("%f %f", &c1.real, &c1.img); 
	printf("Complex Number 1 = %.2f + (%.2f)i\n", c1.real, c1.img); 
	
	printf("\nComplex Number 2:\n"); 
	printf("\nEnter the real and imaginary parts respectively:\n"); 
	scanf("%f %f", &c2.real, &c2.img); 
	printf("Complex Number 2 = %.2f + (%.2f)i\n", c2.real, c2.img); 
	
	//call-the-add-function
	cf = add(c1, c2); 
	
	//printing-the-result
	printf("\nSUM of both complex numbers = %0.2f + %0.2f i", cf.real, cf.img); 
}

complex add(complex c1, complex c2)
{
	complex final; 
	
	final.real = c1.real + c2.real; 
	final.img = c1.img + c2.img; 
	
	return final; 
}
