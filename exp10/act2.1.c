//header-files
#include<stdio.h>
#include<stdlib.h>

//number-of-vertices
int size; 

//function-prototypes
void clear(); 
void getarrud(int arr[][size], char vertices[]); 
void getarrdg(int arr[][size], char vertices[]);
void degreeud(int arr[][size], char vertices[]); 
void degreedg(int arr[][size], char vertices[]);
void display(int arr[][size], char vertices[]);
void menu(int choice, int uarr[][size], int darr[][size], char vertices[]);

//main-function
int main()
{ 
    int job;
    //get-number-of-vertices-in-graph
    printf("Enter the number of vertices: "); 
    scanf("%d", &size); 
    char vertices[size]; 
    int adj_mat_udg[size][size]; 
    int adj_mat_dg[size][size]; 
    //get-vertex-IDs-using-loop
    printf("\nEnter the vertex IDs\n");
    for(int i = 0; i < size; ++i)
    {
        scanf(" %c", &vertices[i]); 
    }
    clear();
    //display-menu-and-get-graph-type
    menu: 
        printf("\nSelect your graph type:\n1.Undirected Graph\n2.Directed Graph\nChoice: ");
        scanf("%d", &job);
        //handle-invalid-selection 
        if(job < 0 || job > 2)
        {
            printf("\nInvalid Input. Try again");
            clear();  
            goto menu; 
        }
        //for-valid-selection-invoke-menu-function
        else
        {
            clear(); 
            menu(job, adj_mat_udg, adj_mat_dg, vertices); 
        }
    return 0; 
}

//function-to-clearing-screen
void clear()
{
    printf("\nPress Enter to Continue.."); 
    while((getchar()) != '\n'); 
    getchar(); 
    system("clear"); 
}

//function-for-geting-undirected-matrix
void getarrud(int arr[][size], char vertices[])
{
    int temp; 
    //get-conectivity-status-between-every-two-vertices-pairs
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; ++j)
        {
            menu:
            printf("\nIs %c is connected to %c: ", vertices[i], vertices[j]);     
            scanf("%d", &temp);
            //handle-invalid-input-by-user
             if(temp > 1 || temp < 0)
            {
                printf("\nYou entered a invalid input, please read the instructions carefully.Try again..."); 
                goto menu;     
            }
            //for-valid-input-perform-insertion-and-prompt-message
            else
            {
                arr[i][j] = temp;   
                if(i < size-1 || j < size-1)
                    printf("\nInput recorded..Insert next elemnt\n"); 
            }
        }
    }
}

//function-for-getting-diagraph-matrix
void getarrdg(int arr[][size], char vertices[])
{
    int temp; 
    //get-conectivity-status-between-every-two-vertices-pairs
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; ++j)
        {
            menu:
            printf("\nConnectivity Status of %c and %c: ", vertices[i], vertices[j]);     
            scanf("%d", &temp);
            //handle-invalid-input-by-user
             if(temp > 2 || temp < 0)
            {
                printf("\nYou entered a invalid input, please read the instructions carefully.Try again..."); 
                goto menu;     
            }
            //for-valid-input-perform-insertion-and-prompt-message
            else
            {
                arr[i][j] = temp; 
                if(i < size-1 || j < size-1)  
                    printf("\nInput recorded..Insert next element\n"); 
            }
        }
    }
}

//function-for-getting-degree-of-vertices-in-undirected-graphs
void degreeud(int arr[][size], char vertices[])
{
    //visit-each-pair-using-loops
    for(int i = 0; i < size; ++i)
    {
        //degree-counter
        int counter = 0;
        for(int j = 0; j < size; ++j)
        {
            //if-vertices-are-connected-increment-counter
            if(arr[i][j] == 1)
            {
                counter++; 
            }
        }
        //prompt-degree-of-the-vertex
        printf("\n%c is having degree %d.", vertices[i], counter); 
    }
}

//function-for-getting-indegree/outdegre-of-vertices-in-diagraph
void degreedg(int arr[][size], char vertices[])
{
    //visit-each-pair-using-loops
    for(int i = 0; i < size; ++i)
    {
        //indegree-or-outdegree-counter
        int counter = 0, count = 0;
        for(int j = 0; j < size; ++j)
        {
            //increment-counters-if-conditions-true
            if(arr[i][j] == 1)
            {
                counter++; 
            }
            else if(arr[i][j] == 0)
            {
                count++; 
            }
        }
        //prompt-indegree-and-outdegree-of-vertex
        printf("\n%c is having out-degree: %d and in degree: %d.", vertices[i], counter, count); 
    }
}

//function-for-displaying-adjacency-matrix
void display(int arr[][size], char vertices[])
{
    printf("\n   "); 
    //visit-every-vertex-IDs
    for(int i = 0; i < size; i++)
    {
        //print-vertices-IDs
        printf("%c ", vertices[i]); 
    }
    //visit-every-vertex-pairs
    for(int i = 0; i < size; ++i)
    {
        //print-vertex-IDs-and-data-at-index
        printf("\n%c  ", vertices[i]); 
        for(int j = 0; j < size; ++j)
        {
            printf("%d ", arr[i][j]);
        }
    }
}

//menu-function
void menu(int choice, int uarr[][size], int darr[][size], char vertices[])
{
     //get-matrix-for-asked-graph
     if(choice == 1)
            {
                printf("\nEnter the data for Undirected Graph\n(If mentioned vertices are connected insert 1, if not insert 0.)\n"); 
                getarrud(uarr, vertices);
                printf("\nAdjacency Matrix for the Undirected Graph has been obtained.");
                clear(); 
            }
            else if(choice == 2)
            {
                printf("\n(If edge is directed from 1st to 2nd insert 1, else insert 0.\nIf vertices are not connected then enter 2.)\n");
                getarrdg(darr, vertices); 
                printf("\nAdjacency Matrix for the Directed Graph has been obtained.");
                clear();
            }
    int job;
    //display-menu-get-job-from-user
    menu:
        printf("\nOperation Available\n1.Degree of vertices(in-degree/out-degree for diagraph OR degree for undirected graph\n2.Display Adjacency Matrix\n3.Exit\nChoice: "); 
        scanf("%d", &job); 
        //toggle-between-different-jobs
        switch (job)
        {
        case 1:
            //finding-degree-for-the-graph
            if(choice == 1)
            {
                printf("\nDegrees of all the vertices of the Undirected Graph is: \n"); 
                degreeud(uarr, vertices);
            }
            else if(choice == 2)
            {
                printf("\nIn-Degree and Out-Degree of the vertices of the Diagraph: \n"); 
                degreedg(darr, vertices); 
            }
            break; 
        case 2:
            //printing-adjacency-matrix 
            if(choice == 1)
            {
                printf("\nAdjacency Matrix for the Undirected Graph is: \n\n"); 
                display(uarr, vertices); 
            }
            else if(choice == 2)
            {
                printf("\nAdjacency Matrix for the Directed Graph is: \n\n"); 
                display(darr, vertices); 
            }
            break;
        case 3: 
            //exiting-program
            exit(0); 
        default:
            //handling-invalid-input-from-user
            printf("\nInvalid Input. Try a valid one.");
            break;
        }
        clear(); 
        goto menu;
}