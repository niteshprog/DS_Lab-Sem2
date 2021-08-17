#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

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
	system("cls");
	if(scrArray1Size+scrArray2Size<=0)
	{
		printf("Data Underflow! No data to merge(copy). Press any key to continue...");
		getch();
		return;
	}
	int i;
	for(i=0; i<scrArray1Size; i++)
	{
		destArray[i]=scrArray1[i];
	}
	for(i=scrArray1Size; i<scrArray1Size+scrArray2Size; i++)
	{
		destArray[i]=scrArray2[i-scrArray1Size];
	}
	(*destArraySize)=scrArray1Size+scrArray2Size;
	return;
}

void Copy(int* scrArray, int scrArraySize, int* destArray, int* destArraySize)
{
	int i;
	system("cls");
	if((*destArraySize)+scrArraySize>10)
	{
		printf("\nCannot copy! Err: Data Overflow! Press any key to continue...");
		getch();
		return;
	}
	if(scrArraySize<=0)
	{
		printf("\nSource array is empty! Press any key to continue...");
		getch();
		return;
	}
	if((*destArraySize)<=0)
	{
		for(i=0; i<scrArraySize; i++)
		{
			destArray[i]=scrArray[i];
		}
		return;
	}
	else
	{
		Copy_Menu_F:
		printf("\nThere is some data in the destination array.");
		printf("\nO) Overwrite.");
		printf("\nL) Insert to left");
		printf("\nR) Insert to right");
		printf("Input: ");
		input=getch();
		switch (input)
		{
			case'o':
			case'O':
				for(i=0; i<scrArraySize; i++)
				{
					destArray[i]=scrArray[i];
				}
				if(scrArraySize>(*destArraySize))
				{
					(*destArraySize)=scrArraySize;
				}
				return;
				break;
			case'l':
			case'L':
				for(i=0; i<(*destArraySize); i++)
				{
					destArray[scrArraySize+i]=destArray[i];
				}
				for(i=0; i<scrArraySize; i++)
				{
					destArray[i]=scrArray[i];
				}
				(*destArraySize)=(*destArraySize)+scrArraySize;
				return;
				break;
			case'r':
			case'R':
				for(i=0; i<scrArraySize; i++)
				{
					destArray[(*destArraySize)+i]=scrArray[i];
				}
				(*destArraySize)=(*destArraySize)+scrArraySize;
				return;
				break;
			default:
				printf("Wrong Input! Press any key to try again...");
				getch();
				system("cls");
				goto Copy_Menu_F;
		}
	}
}

void Delete(int* array, int* arraySize, char name)
{
	Delete_Menu_F:
	int position, i;
	system("cls");
	if(*arraySize<=0)
	{
		printf("Data Underflow! Press any key to continue...");
		getch();
		return;
	}
	Display(array, *arraySize, name);
	printf("\n\nEnter the position you want to delete(1-10): ");
	scanf("%d", &position);
	if(position>10 || position<1)
	{
		printf("\nWrong Input! Press any key to try again...");
		getch();
		goto Delete_Menu_F;
	}
	if(position>*arraySize)
	{
		printf("\nNo element at position %d.\nPress any key to continue...", position);
		getch();
		return;		
	}
	--position;
	for(i=position; i<*arraySize; i++)
	{
		array[i]=array[i+1];
	}
	--(*arraySize);
	system("cls");
}

void Insert(int* array, int* arraySize, char name)
{
	int position, value, i;
	printf("Current occupancy of array is: %d", countA);
	if(*arraySize>=10)
	{
		printf("\nData overflow! Cannot store more data in Array A.\nPress any key to continue...");
		getch();
		system("cls");
		MainMenu();
	}
	Insert_Menu_F:
	printf("\nEnter the position where you want to insert the element(1-10): ");
	scanf("%d", &position);
	if(position>10 || position<1)
	{
		printf("\nInvalid position entered! Press any key to try again...");
		getch();
		system("cls");
		goto Insert_Menu_F;
	}
	--position;
	printf("\nEnter the element to store: ");
	scanf("%d", &value);
	if(position<=*arraySize)
	{
		for(i=(*arraySize); i>position; i--)
		{
			array[i]=array[i-1];
		}
		array[position]=value;
	}
	else
	{
		position=(*arraySize);
		array[position]=value;
	}
	++(*arraySize);
	system("cls");
}

void Display(int* array, int arraySize, char name)
{
	system("cls");
	int i;
	printf("\nNumber of elements in array %c: %d", name, arraySize);
	printf("\n\nArray:");
	for(i=0; i<arraySize; i++)
	{
		printf("   %d", array[i]);
	}
	printf("\n\nPress any key to continue...");
	getch();
}

void MainMenu()
{
	system("cls");
	printf("       Main Menu\n=======================");
	printf("\nA) Display array.");
	printf("\nB) Insert an element.");
	printf("\nC) Delete an element.");
	printf("\nD) Copy an array.");
	printf("\nE) Merge two arrays.");
	printf("\nX) Exit.");
	printf("\n\n( Arrays available: 3 )");
	printf("\n\nInput:");
	input=getch();
	switch (input)
	{
		case'a':
		case'A':
			system("cls");
			Display_Menu:
			printf("Select an arrray.\n=====================");
			printf("\nA) Array 1");
			printf("\nB) Array 2");
			printf("\nC) Array 3");
			printf("\nX) Go back.");
			printf("\n\nInput:");
			input=getch();
			switch (input)
			{
				case'a':
				case'A':
					system("cls");
					Display(arrayA, countA, 'A');
					MainMenu();
					break;
				case'b':
				case'B':
					system("cls");
					Display(arrayB, countB, 'B');
					MainMenu();
					break;
				case'c':
				case'C':
					system("cls");
					Display(arrayC, countC, 'C');
					MainMenu();
					break;
				case'x':
				case'X':
					system("cls");
					MainMenu();
					break;
				default:
					system("cls");
					printf("Wrong Input!\n\n");
					goto Display_Menu;
			}
			break;
		case'b':
		case'B':
			Insert_Menu:
			system("cls");
			printf("Select an arrray.\n=====================");
			printf("\nA) Array 1");
			printf("\nB) Array 2");
			printf("\nC) Array 3");
			printf("\nX) Go back.");
			printf("\n\nInput:");
			input=getch();
			switch (input)
			{
				case'a':
				case'A':
					system("cls");
					Insert(arrayA, &countA, 'A');
					Display(arrayA, countA, 'A');
					MainMenu();
					break;
				case'b':
				case'B':
					system("cls");
					Insert(arrayB, &countB, 'B');
					Display(arrayB, countB, 'B');
					MainMenu();
					break;
				case'c':
				case'C':
					system("cls");
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
					getch();
					goto Insert_Menu;
			}
			break;
			case'c':
			case'C':
				Delete_Menu:
				system("cls");
				printf("Select an arrray.\n=====================");
				printf("\nA) Array 1");
				printf("\nB) Array 2");
				printf("\nC) Array 3");
				printf("\nX) Go back.");
				printf("\n\nInput:");
				input=getch();
				switch (input)
				{
					case'a':
					case'A':
						system("cls");
						Delete(arrayA, &countA, 'A');
						Display(arrayA, countA, 'A');
						MainMenu();
						break;
					case'b':
					case'B':
						system("cls");
						Delete(arrayB, &countB, 'B');
						Display(arrayB, countB, 'B');
						MainMenu();
						break;
					case'c':
					case'C':
						system("cls");
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
						getch();
						goto Delete_Menu;
			}
			break;
			case'd':
			case'D':
				Copy_Menu:
				system("cls");
				printf("Select an option.\n=====================");
				printf("\nA) Copy Array 1 to Array 2");
				printf("\nB) Copy Array 2 to Array 1");
				printf("\nX) Go back.");
				printf("\n\nInput:");
				input=getch();
				switch(input)
				{
					case'a':
					case'A':
						system("cls");
						Copy(arrayA, countA, arrayB, &countB);
						Display(arrayB, countB, 'B');
						MainMenu();
						break;
					case'b':
					case'B':
						system("cls");
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
						getch();
						goto Copy_Menu;
				}
				break;
			case'e':
			case'E':
				Merge_Menu:
				system("cls");
				printf("Select an option.\n=====================");
				printf("\nM) Merge Array 1 and Array 2 to Array 3");
				printf("\nX) Go back.");
				printf("\n\nInput:");
				input=getch();
				switch (input)
				{
					case'm':
					case'M':
						system("cls");
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
						getch();
						system("cls");
						goto Merge_Menu;
				}
			case'x':
			case'X':
				exit(0);
			default:
				printf(" Wrong Input! Press any key to try again...");
				getch();
				MainMenu();
	}
}

int main()
{
	MainMenu();
}
