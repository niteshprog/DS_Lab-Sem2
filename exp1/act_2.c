#include<stdio.h>
#include<stdlib.h>

void clear (void) //Clears the buffer memory
{    
  while ( getchar() != '\n' );
}

char input;
int A1[10], A2[10], A3[20];
int nA1=0, nA2=0, nA3=0;

void Delete(int*, int*, char);
void Copy(int*, int, int*, int*);
void Merge(int*, int, int*, int, int*, int*);
void Display(int*, int, char);
void MainMenu();
void Insert(int*, int*, char);

void Merge(int* A1, int sizeA1, int* A2, int sizeA2, int* A3, int* sizeA3)
{
	system("clear");
	if(sizeA1+sizeA2<=0) //Checking if both array are empty or not
	{
		printf("\nNo data to merge(copy). Press any key to continue...");
		clear(); getchar();
		return;
	}
	int i;
	for(i=0; i<sizeA1; i++) //Copying the contents of 1st array to 3rd array
	{
		A3[i]=A1[i];
	}
	for(i=sizeA1; i<sizeA1+sizeA2; i++) //Copying the contents of 2nd array to 3rd array
	{
		A3[i]=A2[i-sizeA1];
	}
	(*sizeA3)=sizeA1+sizeA2;
	return;
}

void Copy(int* A1, int sizeA1, int* A2, int* sizeA2)
{
	int i;
	system("clear");
	if((*sizeA2)+sizeA1>10) //Checking for Overflow
	{
		printf("\nCannot copy! Err: Data Overflow! Press any key to continue...");
		clear(); getchar();
		return;
	}
	if(sizeA1<=0) //Checking if the source array is empty
	{
		printf("\nSource array is empty! Press any key to continue...");
		clear(); getchar();
		return;
	}
	for(i=0; i<sizeA1; i++)
	{
		A2[i]=A1[i];
	}
	sizeA2=sizeA1;
	return;
}

void Delete(int* A, int* sizeA, char name)
{
	int pos, i;
	Delete_Menu_F:
	system("clear");
	if(*sizeA<=0) //Checking for underflow
	{
		printf("Data Underflow! Press any key to continue...");
		clear(); getchar();
		return;
	}
	Display(A, *sizeA, name);
	printf("\n\nEnter the position you want to delete(1-10): ");
	scanf("%d", &pos);
	if(pos>10 || pos<1) //Checking if position is valid or not (in range of 1-10 including both)
	{
		printf("\nWrong Input! Press any key to try again...");
		clear(); getchar();
		goto Delete_Menu_F;
	}
	if(pos>*sizeA) //Checking if there exists any element at the pos
	{
		printf("\nNo element at position %d.\nPress any key to continue...", pos);
		clear(); getchar();
		return;		
	}
	--pos;
	for(i=pos; i<*sizeA; i++) //Shifting data to overwrite the required element
	{
		A[i]=A[i+1];
	}
	--(*sizeA); //Adjusting size parameter
	system("clear");
}

void Insert(int* A, int* sizeA, char name)
{
	int pos, val, i;
	printf("Current occupancy of Array is: %d", nA1);
	if(*sizeA>=10) //Checking for overflow
	{
		printf("\nData overflow! Cannot store more data in Array A.\nPress any key to continue...");
		clear(); getchar();
		system("clear");
		MainMenu();
	}
	Insert_Menu_F:
	printf("\nEnter the position where you want to insert the element(1-10): ");
	scanf("%d", &pos);
	if(pos>10 || pos<1) //Checking if position is valid or not (in range of 1-10 including both)
	{
		printf("\nInvalid position entered! Press any key to try again...");
		clear(); getchar();
		system("clear");
		goto Insert_Menu_F;
	}
	--pos;
	printf("\nEnter the element to store: ");
	scanf("%d", &val);
	if(pos<=*sizeA) //If user wants to add in between existing data
	{
		for(i=(*sizeA); i>pos; i--) //Shifting elements
		{
			A[i]=A[i-1];
		}
		A[pos]=val;
	}
	else //If user wants to add at the end or beyond existing data
	{
		pos=(*sizeA);
		A[pos]=val;
	}
	++(*sizeA);
	system("clear");
}

void Display(int* A, int sizeA, char name)
{
	system("clear");
	int i;
	printf("\nNumber of elements in Array %c: %d", name, sizeA);
	printf("\n\nArray:");
	for(i=0; i<sizeA; i++)
	{
		printf("   %d", A[i]);
	}
	printf("\n\nPress any key to continue...");
	clear(); getchar();
}

void MainMenu()
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
					Display(A1, nA1, 'A');
					MainMenu();
					break;
				case'b':
				case'B':
					system("clear");
					Display(A2, nA2, 'B');
					MainMenu();
					break;
				case'c':
				case'C':
					system("clear");
					Display(A3, nA3, 'C');
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
					Insert(A1, &nA1, 'A');
					Display(A1, nA1, 'A');
					MainMenu();
					break;
				case'b':
				case'B':
					system("clear");
					Insert(A2, &nA2, 'B');
					Display(A2, nA2, 'B');
					MainMenu();
					break;
				case'c':
				case'C':
					system("clear");
					Insert(A3, &nA3, 'C');
					Display(A3, nA3, 'C');
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
						Delete(A1, &nA1, 'A');
						Display(A1, nA1, 'A');
						MainMenu();
						break;
					case'b':
					case'B':
						system("clear");
						Delete(A2, &nA2, 'B');
						Display(A2, nA2, 'B');
						MainMenu();
						break;
					case'c':
					case'C':
						system("clear");
						Delete(A3, &nA3, 'C');
						Display(A3, nA3, 'C');
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
						Copy(A1, nA1, A2, &nA2);
						Display(A2, nA2, 'B');
						MainMenu();
						break;
					case'b':
					case'B':
						system("clear");
						Copy(A2, nA2, A1, &nA1);
						Display(A1, nA1, 'A');
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
						Merge(A1, nA1, A2, nA2, A3, &nA3);
						Display(A3, nA3, 'C');
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
				MainMenu();
	}
}

int main()
{
	MainMenu();
}
