//sum of elements of array by recursion
//introducing header files
#include<stdio.h>
#include<stdlib.h>

//declare function with diff. parameters
int sumofarray(int arr[], int start, int len); 

int main()
{
	//declaration of some variables 
	int n,i,sum; 
	printf("Enter the length of the array:"); 
	scanf("%d", &n);     //get the length of the string 
	if (n <= 0)
	{
		printf("Invalid Length!!");      //progaram terminates with this message
		exit(0); 
	}
	int arr[n];    //declaration of array with length "n"
	printf("Now enter the elements of the array:"); 
	for(i = 0; i < n ; ++i)
	{
		scanf("%d", &arr[i]);     //getting every element of the array 
	}
	sum = sumofarray(arr, 0, n);      //calling the sumofarray function
	printf("The total of the elements of array is : %d", sum); 
	return 0; 
}	

//declaration of the sumofarray function 
int sumofarray(int arr[], int start, int len)
{
	if(start >= len)
	{
		return 0;        //if the initial index is greater than length then terminate program 
	}
	return(arr[start] + sumofarray(arr, start+1, len));      //else return the sum got by recurssion of the function 
}
