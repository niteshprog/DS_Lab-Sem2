#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct registration{
	int date, year;
	char *month[10]; 
}registration;

typedef struct marks{
	float maths, eng, phy, chem, pe; 
}marks;

typedef struct date{
	int day, year; 
	char *month[10]; 
}date;

typedef struct student_record{
	char name[10]; 
	int sap_id, enr_no;
	struct registration registration; 
	struct date date; 
	struct marks marks;  
}student_record;

void main()
{
	int n, i; 
	
	printf("Number of records you want to maintain:\n"); 
	scanf("%d", &n); 
	
	student_record *student = (student_record*)malloc(n*sizeof(student_record)); ; 
	
	for( i = 0; i < n; ++i)
	{ 
		printf("\nEnter the data for the student %d:\n", i+1); 
	
		
		printf("\nEnter the name of student:\n"); 		//intialize name	
		while ( getchar() != '\n' );
		scanf("%[^\n]s", student[i].name);
		while ( getchar() != '\n' ); 
		
		printf("Enter the SAP Id:\n"); 			//initialize sap id	
		scanf("%d", &student[i].sap_id); 
		
		printf("Enter the registration month(e.g: January):\n"); 		//initialize reg. info
		while((getchar()) != '\n'); 
		scanf("%s", &student[i].registration.month); 
		
		printf("Enter the date and year of registration respectively:\n"); 
		scanf("%d %d", &student[i].registration.date, &student[i].registration.year); 
		
		printf("Enter the enrollment number:\n"); 		//initiallize enr. no.
		scanf("%d", &student[i].enr_no); 
		
		printf("Enter the month of your birth(e.g: January):\n"); 		//intialize dob
		scanf("%s", &student[i].date.month);
		
		printf("Enter the date and year of birth respectively:\n"); 
		scanf("%d %d", &student[i].date.day, &student[i].date.year); 
		
		//initialize marks
		printf("Enter the marks in order(English, Mathematics, Physics, Chemistry, Phy. Ed.):\n");  
		scanf("%f %f %f %f %f", &student[i].marks.eng, &student[i].marks.maths, &student[i].marks.phy, &student[i].marks.chem, &student[i].marks.pe);
	} printf("\n");
	
	for( i = 0; i < n; ++i)
	{
		printf("\nGradesheet of student %d\n", i+1); 
		printf("Name: %s\n", student[i].name );
		printf("SAP Id: %d\n", student[i].sap_id); 
		printf("Enrollment Number: %d\n", student[i].enr_no); 
		printf("Registration Date: %d, %s, %d\n", student[i].registration.date, student[i].registration.month, student[i].registration.year); 
		printf("D.O.B: %d, %s, %d\n", student[i].date.day, student[i].date.month, student[i].date.year); 
		float avg = student[i].marks.eng + student[i].marks.maths + student[i].marks.phy + student[i].marks.chem + student[i].marks.pe ; 
		avg = avg/5; 
		printf("Average marks: %f\n", avg); 
	}
}
