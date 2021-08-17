//MATRIX_MULTIPLICATION_USING_POINTERS
//header_files
#include<stdio.h>
#include<stdlib.h>

//declaring_functions
void Read_matrix(int x, int y, int z[][10]);
void Write_matrix(int x, int y, int z[][10]);
void Multiply(int m1[][10], int m2[][10], int fm[][10], int r1, int c2, int c1);
 
int main()
{
//	declaring_three_matrices
	int m1[10][10]; 
	int m2[10][10]; 
	int fm[10][10]; 
	int r1, c1, r2, c2;      //declaring_rows_and_columns_for_both_matrix
	//defining_rows_and_columns_for_both_matrix
	Matrix_1:
	printf("Enter the rows and columns of the first matrix(1-10):\n"); 
	scanf("%d %d", &r1, &c1); 
	if(r1 > 10 || c1 > 10)
	{
		printf("Invalid input for row or column!!, Try with some valid input.\n"); 
		goto Matrix_1;  
	}
	Matrix_2:
	printf("Enter the rows and columns of the second matrix(1-10):\n");
	scanf("%d %d", &r2, &c2); 
	if(r2 > 10 || c2 > 10)
	{
		printf("Invalid input for row or column!!, Try with some valid input.\n"); 
		goto Matrix_2;  
	}
	//check_the_condition_for_matrix_multiplication
	if(c1 != r2)
	{
		printf("Invalid Inputs...Matrix mulitplication can't be executed!!'"); 
//		getch(); 
		exit(1); 
	}
	//get_elements_of_resp._matrices_by_calling_"Read_matrix"_function
	printf("For the first matrix:\n"); 
	Read_matrix(r1, c1, m1); 
	printf("For the second matrix:\n"); 
	Read_matrix(r2, c2, m2); 
	//print_the_first_and_second_matrices_by_calling_"Write_matrix"_function
	printf("First matrix is:\n"); 
	Write_matrix(r1, c1, m1); 
	printf("Second matrix is:\n"); 
	Write_matrix(r2, c2, m2); 
	//multiply_the_two_matrices_and_store_in_final_matrix_by_calling_"Multiply"_function
	Multiply(m1, m2, fm, r1, c2, c1); 
	printf("Matrix multiplication of these matrix is:\n"); 
	//print_final_matrix_using_"Write_matrix"_function 
	Write_matrix(r1, c2, fm); 
//	getch(); 
	return 0 ; 
}

//defining_the_functions_declared_earlier 

void Read_matrix(int x, int y, int z[][10])     //function_to_get_input_for_matrix
{
	int i, j; 
	printf("Enter the element row wise:\n"); 
	for(i = 0; i < x; ++i)
	{
		for(j = 0; j < y; ++j)
		{
			scanf("%d", (*(z+i)+j));     //takes_input_from_the_user_for_resp._matrices_position
		}
	}
}

void Write_matrix(int x, int y, int z[][10])   //function_to_print_the_matrix
{
	int i, j; 
	for(i =0; i < x; ++i)
	{
		for(j = 0; j < y; ++j)
		{
			printf("%d ", *(*(z+i)+j));    //print_element_for_resp._position
		}printf("\n");      //print_upcoming_elements_in_next_line
	}
}

void Multiply(int m1[][10], int m2[][10], int fm[][10], int r1, int c2, int c1)   //function_for_multiplication
{
	int i, j, k; 
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			*(*(fm+i)+j) = 0; 
			for(k = 0; k < c1; ++k)
			{
				*(*(fm+i)+j) += *(*(m1+i)+k) * *(*(m2+k)+j);   //multiplies_resp._elements_and_stores_at_suitable_location
			}
			}
		}
	}

