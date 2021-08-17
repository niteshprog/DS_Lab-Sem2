#include<stdio.h>
#include<stdlib.h>

struct date
{
	int day, month, year;
};

struct student
{
	char name[30], enrollment[10];
	int sapid;
	struct date dob, dor;
	struct student* next;
	float marks[5];
}*first=NULL, *last=NULL, *temp;

void create()
{
	int i;
	temp=(struct student *)malloc(sizeof(struct student));
	printf("\nEnter name of student: ");
	while ( getchar() != '\n' );
	scanf("%[^\n]s", temp->name);
	while ( getchar() != '\n' );
	printf("\nEnter enrollment number: ");
	scanf("%[^\n]s", temp->enrollment);
	printf("\nEnter SAP-ID: ");
	scanf("%d", &temp->sapid);
	printf("\nEnter Date of Birth\nDay: ");
	scanf("%d", &temp->dob.day);
	printf("\nMonth: ");
	scanf("%d", &temp->dob.month);
	printf("\nYear: ");
	scanf("%d", &temp->dob.year);
	printf("\nEnter Date of Registration\nDay: ");
	scanf("%d", &temp->dor.day);
	printf("\nMonth: ");
	scanf("%d", &temp->dor.month);
	printf("\nYear: ");
	scanf("%d", &temp->dor.year);
	for(i=0; i<5; i++)
	{
		printf("\nEnter marks in subject %d: ", i+1);
		scanf("%f", &temp->marks[i]);
	}
	if(first==NULL)
	{
		temp->next=NULL;
		first=last=temp;
		
	}
	else
	{
		last->next=temp;
		temp->next=NULL;
		last=temp;
	}
}

void gradesheet(int n)
{
	int i;
	struct student* ptr;
	if(first==NULL)
	{
		printf("No records!");
	}
	else
	{
		ptr=first;
		for(i=1; i<n; i++)
		ptr=ptr->next;
		printf("\nName: %s", ptr->name);
		printf("\nEnrollment number: %s", ptr->enrollment);
		printf("\nSAP-ID: %d", ptr->sapid);
		printf("\nD.O.B: %d/%d/%d", ptr->dob.day, ptr->dob.month, ptr->dob.year);
		printf("\nD.O.R: %d/%d/%d", ptr->dor.day, ptr->dor.month, ptr->dor.year);
		float per;
		per=((ptr->marks[0])+(ptr->marks[1])+(ptr->marks[2])+(ptr->marks[3])+(ptr->marks[4]))/5;
		printf("\nMarks in Subject 1: %f", ptr->marks[0]);
		printf("\nMarks in Subject 2: %f", ptr->marks[1]);
		printf("\nMarks in Subject 3: %f", ptr->marks[2]);
		printf("\nMarks in Subject 4: %f", ptr->marks[3]);
		printf("\nMarks in Subject 5: %f", ptr->marks[4]);
		printf("\nPercentage: %f", per);
	}
}

int main()
{
	unsigned int n, i;
	printf("How many student records to enter: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	create();
	for(i=1; i<=n; i++)
	{
		gradesheet(i);
		printf("\nPress enter to print next gradesheet...");
		getchar();
	}
}
