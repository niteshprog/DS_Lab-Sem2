#include<stdio.h>
#include<stdlib.h>

void clear (void) //Clears the buffer memory
{    
  while ( getchar() != '\n' );
}

char input;
int arrayA[10], arrayB[10], arrayC[20];
int countA=0, countB=0, countC=0;

void Delete(int*, int*, char);
void Copy(int*, int, int*, int*);
void Merge(int*, int, int*, int, int*, int*);
void Display(int*, int, char);
void MainMenu();
void Insert(int*, int*, char);

void Merge(int* scrArray1, int scrArray1Size, int* scrArray2, int scrArray2Size, int* destArray, int* destArraySize)
{
	system("clear");
	if(scrArray1Size+scrArray2Size<=0) //Checking if both array are empty or not
	{
		printf("\nNo data to merge(copy). Press any key to continue...");
		clear(); getchar();
		return;
	}
	int i;
	for(i=0; i<scrArray1Size; i++) //Copying the contents of 1st array to 3rd array
	{
		destArray[i]=scrArray1[i];
	}
	for(i=scrArray1Size; i<scrArray1Size+scrArray2Size; i++) //Copying the contents of 2nd array to 3rd array
	{
		destArray[i]=scrArray2[i-scrArray1Size];
	}
	(*destArraySize)=scrArray1Size+scrArray2Size;
	return;
}

void Copy(int* scrArray, int scrArraySize, int* destArray, int* destArraySize)
{
	int i;
	system("clear");
	if((*destArraySize)+scrArraySize>10) //Checking for Overflow
	{
		printf("\nCannot copy! Err: Data Overflow! Press any key to continue...");
		clear(); getchar();
		return;
	}
	if(scrArraySize<=0) //Checking if the source array is empty
	{
		printf("\nSource array is empty! Press any key to continue...");
		clear(); getchar();
		return;
	}
	for(i=0; i<scrArraySize; i++)
	{
		destArray[i]=scrArray[i];
	}
	*destArraySize = scrArraySize;
	return;
}

void Delete(int* array, int* arraySize, char name)
{
	int position, i;
	Delete_Menu_F:
	system("clear");
	if(*arraySize<=0) //Checking for underflow
	{
		printf("Data Underflow! Press any key to continue...");
		clear(); getchar();
		return;
	}
	Display(array, *arraySize, name);
	printf("\n\nEnter the position you want to delete(1-10): ");
	scanf("%d", &position);
	if(position>10 || position<1) //Checking if position is valid or not (in range of 1-10 including both)
	{
		printf("\nWrong Input! Press any key to try again...");
		clear(); getchar();
		goto Delete_Menu_F;
	}
	if(position>*arraySize) //Checking if there exists any element at the position
	{
		printf("\nNo element at position %d.\nPress any key to continue...", position);
		clear(); getchar();
		return;		
	}
	--position;
	for(i=position; i<*arraySize; i++) //Shifting data to overwrite the required element
	{
		array[i]=array[i+1];
	}
	--(*arraySize); //Adjusting size parameter
	system("clear");
}

void Insert(int* array, int* arraySize, char name)
{
	int position, value, i;
	printf("Current occupancy of array is: %d", countA);
	if(*arraySize>=10) //Checking for overflow
	{
		printf("\nData overflow! Cannot store more data in Array A.\nPress any key to continue...");
		clear(); getchar();
		system("clear");
		MainMenu();
	}
	Insert_Menu_F:
	printf("\nEnter the position where you want to insert the element(1-10): ");
	scanf("%d", &position);
	if(position>10 || position<1) //Checking if position is valid or not (in range of 1-10 including both)
	{
		printf("\nInvalid position entered! Press any key to try again...");
		clear(); getchar();
		system("clear");
		goto Insert_Menu_F;
	}
	--position;
	printf("\nEnter the element to store: ");
	scanf("%d", &value);
	if(position<=*arraySize) //If user wants to add in between existing data
	{
		for(i=(*arraySize); i>position; i--) //Shifting elements
		{
			array[i]=array[i-1];
		}
		array[position]=value;
	}
	else //If user wants to add at the end or beyond existing data
	{
		position=(*arraySize);
		array[position]=value;
	}
	++(*arraySize);
	system("clear");
}

void Display(int* array, int arraySize, char name)
{
	system("clear");
	int i;
	printf("\nNumber of elements in array %c: %d", name, arraySize);
	printf("\n\nArray:");
	for(i=0; i<arraySize; i++)
	{
		printf("   %d", array[i]);
	}
	printf("\n\nPress any key to continue...");
	clear(); getchar();
}

void main()
{
	system("clear");
	printf("       Main Menu\n=======================");
	printf("\nA) Display array.");
	printf("\nB) Insert an element.");
	printf("\nC) Delete an element.");
	printf("\nD) Copy an array.");
	printf("\nE) Merge two arrays.");
	printf("\nX) Exit.");
	printf("\n\n( Arrays available: 3 )");
	printf("\n\nInput:");
	input=getchar();
	switch (input)
	{
		case'a':
		case'A':
			system("clear");
			Display_Menu: //Sub menu for display
			printf("Select an arrray.\n=====================");
			printf("\nA) Array 1");
			printf("\nB) Array 2");
			printf("\nC) Array 3");
			printf("\nX) Go back.");
			printf("\n\nInput:");
			clear(); input=getchar();
			switch (input)
			{
				case'a':
				case'A':
					system("clear");
					Display(arrayA, countA, 'A');
					MainMenu();
					break;
				case'b':
				case'B':
					system("clear");
					Display(arrayB, countB, 'B');
					MainMenu();
					break;
				case'c':
				case'C':
					system("clear");
					Display(arrayC, countC, 'C');
					MainMenu();
					break;
				case'x':
				case'X':
					system("clear");
					MainMenu();
					break;
				default:
					system("clear");
					printf("Wrong Input!\n\n");
					goto Display_Menu;
			}
			break;
		case'b':
		case'B':
			Insert_Menu: //Sub menu for insert
			system("clear"); 
			printf("Select an arrray.\n=====================");
			printf("\nA) Array 1");
			printf("\nB) Array 2");
			printf("\nC) Array 3");
			printf("\nX) Go back.");
			printf("\n\nInput:");
			clear(); input=getchar();
			switch (input)
			{
				case'a':
				case'A':
					system("clear");
					Insert(arrayA, &countA, 'A');
					Display(arrayA, countA, 'A');
					MainMenu();
					break;
				case'b':
				case'B':
					system("clear");
					Insert(arrayB, &countB, 'B');
					Display(arrayB, countB, 'B');
					MainMenu();
					break;
				case'c':
				case'C':
					system("clear");
					Insert(arrayC, &countC, 'C');
					Display(arrayC, countC, 'C');
					MainMenu();
					break;
				case'x':
				case'X':
					MainMenu();
					break;
				default:
					printf(" Wrong Input! Press any key to try again...");
					clear(); getchar();
					goto Insert_Menu;
			}
			break;
			case'c':
			case'C':
				Delete_Menu:
				system("clear"); //Sub menu for delete
				printf("Select an arrray.\n=====================");
				printf("\nA) Array 1");
				printf("\nB) Array 2");
				printf("\nC) Array 3");
				printf("\nX) Go back.");
				printf("\n\nInput:");
				clear(); input=getchar();
				switch (input)
				{
					case'a':
					case'A':
						system("clear");
						Delete(arrayA, &countA, 'A');
						Display(arrayA, countA, 'A');
						MainMenu();
						break;
					case'b':
					case'B':
						system("clear");
						Delete(arrayB, &countB, 'B');
						Display(arrayB, countB, 'B');
						MainMenu();
						break;
					case'c':
					case'C':
						system("clear");
						Delete(arrayC, &countC, 'C');
						Display(arrayC, countC, 'C');
						MainMenu();
						break;
					case'x':
					case'X':
						MainMenu();
						break;
					default:
						printf(" Wrong Input! Press any key to try again...");
						clear(); getchar();
						goto Delete_Menu;
			}
			break;
			case'd':
			case'D':
				Copy_Menu:
				system("clear"); //Sub menu for Copy
				printf("Select an option.\n=====================");
				printf("\nA) Copy Array 1 to Array 2");
				printf("\nB) Copy Array 2 to Array 1");
				printf("\nX) Go back.");
				printf("\n\nInput:");
				clear(); input=getchar();
				switch(input)
				{
					case'a':
					case'A':
						system("clear");
						Copy(arrayA, countA, arrayB, &countB);
						Display(arrayB, countB, 'B');
						MainMenu();
						break;
					case'b':
					case'B':
						system("clear");
						Copy(arrayB, countB, arrayA, &countA);
						Display(arrayA, countA, 'A');
						MainMenu();
						break;
					case'x':
					case'X':
						MainMenu();
						break;
					default:
						printf(" Wrong Input! Press any key to try again...");
						clear(); getchar();
						goto Copy_Menu;
				}
				break;
			case'e':
			case'E':
				Merge_Menu:
				system("clear"); //Sub menu for merge
				printf("Select an option.\n=====================");
				printf("\nM) Merge Array 1 and Array 2 to Array 3");
				printf("\nX) Go back.");
				printf("\n\nInput:");
				clear(); input=getchar();
				switch (input)
				{
					case'm':
					case'M':
						system("clear");
						Merge(arrayA, countA, arrayB, countB, arrayC, &countC);
						Display(arrayC, countC, 'C');
						MainMenu();
						break;
					case'x':
					case'X':
						MainMenu();
						break;
					default:
						printf("Wrong Input! Press any key to try again...");
						clear(); getchar();
						system("clear");
						goto Merge_Menu;
				}
			case'x':
			case'X':
				exit(0);
			default:
				printf(" Wrong Input! Press any key to try again...");
				clear(); getchar();
//				MainMenu();
	}
	return 0; 
}

//int main()
//{
//	MainMenu();
//}
