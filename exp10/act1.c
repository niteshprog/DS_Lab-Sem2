//header-files
#include<stdio.h>
#include<stdlib.h>

//function-prototype
void clear(); 

//main-function
int main()
{
    //declaring-variables
    int vertices, temp, counter = 0;
    //get-the-number-of-vertices
    printf("\nEnter the number of vertices in the graph: "); 
    scanf("%d", &vertices); 
    //declare-a-adjacency-matrix
    int adj_mat[vertices][vertices]; 
    //get-the-adjacency-matrix
    for(int i = 0; i < vertices; ++i)
    {
        for(int j = 0; j < vertices; ++j)
        {
            check: 
                //get-the-input
                printf("\nEnter '1' if the %d is connected to %d, and if are not connected than press '0': ", i+1, j+1); 
                scanf("%d", &temp); 
            //validating-the-user-input
            if(temp > 1 || temp < 0)
            {
                printf("\nYou entered a invalid input, please read the instructions carefully."); 
                clear(); 
                goto check;     
            }
            //if-input-is-valid-prompt-successful-insertion
            else
            {
                adj_mat[i][j] = temp;   
                printf("\nInput recorded..Insert Next Element\n"); 
            }
        }
    }
    //check-for-type-of-graph
    for(int i = 0; i < vertices; ++i)
    {
        for(int j = 0; j < vertices; ++j)
        {
            //checking-each-position-before-and-after-transpose
            if(adj_mat[i][j] != adj_mat[j][i])
            {
                counter = 1; 
                //break-the-loop
                break; 
            }
        }
        //break-the-loop-to-reduce-execution-time
        if(counter == 1)
        {
            break; 
        }
    }
    //prompt-respective-message-on-the-basis-of-examination
    if(counter == 1)
    {
        printf("\nThis adjacency matrix is for diagraph."); 
    }
    else if(counter == 0)
    {
        printf("\nThis adjacency matrix if for the undirected graph."); 
    }
    return 0; 
}

//function-for-clearing-buffer-and-clearing-screen
void clear()
{
    printf("\nPress Enter to Continue.."); 
    while((getchar()) != '\n'); 
    getchar(); 
    system("cls"); 
}