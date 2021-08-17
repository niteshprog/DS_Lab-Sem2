//CHANGING_THE_STRING_IN_LOWERCASE
#include<stdio.h>
#include<string.h>

void main()
{
//	DECLARING_SIZE_OF_STRING
	int size; 
	printf("Enter the size of phrase:"); 
	scanf("%d", &size); 
//	DECLARING_STRING
	char str1[size];
	printf("Enter a string(only uppercase):"); 
	while (getchar() != '\n');      
	fgets(str1, size, stdin);       //get string in upper case from the user 
	int i; 
	for(i = 0; i <= size; i++)
	{
	  		if (str1[i] >= 'A' && str1[i] <= 'Z')      
	   {
		str1[i] = str1[i] + 32;           //updating every element of the string to upper case using ASCII code 
	    }
	}
	printf( "The lower case of this string: %s", str1);      //print the updated string 
		 
}
