#include<stdio.h>
int main()
{
	union product
	{
		char prodName[30];
		float price, amount, quantity;
	};
	union product p, *x;
	int a, b;
	x=&p;
	printf("Enter product name: ");
	scanf("%[^\n]s", p.prodName); //Input and display name

	printf("\nEnter the price: ");
	scanf("%f", &p.price); 
	a=x->price; //Store price
	
	printf("\nEnter the quantity: ");
	scanf("%f", &p.quantity);
	b=x->quantity; //Store quantity
	
	p.amount=a*b; //Calculate amount
	printf("Product name: %s", x->prodName);
	printf("Price: %f", x->price);
	printf("Quantity: %f", x->quantity);
	printf("\nAmount: %f", x->amount);
}
