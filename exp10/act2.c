//header-files
#include<stdio.h>
#include<stdlib.h>

//number-of-vertex
int size; 

//function-prototypes
void scrnclr(); 
void arrug(int temp_arr[][size], char vertex[]); 
void arrdg(int temp_arr[][size], char vertex[]);
void getdegreeud(int temp_arr[][size], char vertex[]); 
void getdegreedg(int temp_arr[][size], char vertex[]);
void show(int temp_arr[][size], char vertex[]);
void menu(int choice, int uarr[][size], int darr[][size], char vertex[]);

//main-function
int main()
{ 
    int command;
    //get-number-of-vertex-in-graph
    printf("Enter the number of vertex: "); 
    scanf("%d", &size); 
    char vertex[size]; 
    int udg[size][size]; 
    int dg[size][size]; 
    //get-vertex-IDs-using-loop
    printf("\nEnter the vertex IDs\n");
    for(int i = 0; i < size; ++i)
    {
        scanf(" %c", &vertex[i]); 
    }
    scrnclr();
    //show-menu-and-get-graph-type
    menu: 
        printf("\nGraph type:\n1.Undirected Graph\n2.Directed Graph\nInput: ");
        scanf("%d", &command);
        //handle-invalid-selection 
        if(command < 0 || command > 2)
        {
            printf("\nInvalid Input.");
            scrnclr();  
            goto menu; 
        }
        //for-valid-selection-invoke-menu-function
        else
        {
            scrnclr(); 
            menu(command, udg, dg, vertex); 
        }
    return 0; 
}

//function-to-scrnclring-screen
void scrnclr()
{
    printf("\nPress Enter.."); 
    while((getchar()) != '\n'); 
    getchar(); 
    system("clear"); 
}

//function-for-geting-undirected-matrix
void arrug(int temp_arr[][size], char vertex[])
{
    int temp; 
    //get-conectivity-status-between-every-two-vertex-pairs
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; ++j)
        {
            menu:
            printf("\nIs %c is connected to %c: ", vertex[i], vertex[j]);     
            scanf("%d", &temp);
            //handle-invalid-input-by-user
             if(temp > 1 || temp < 0)
            {
                printf("\nInvalid input.Try again..."); 
                goto menu;     
            }
            //for-valid-input-perform-insertion-and-prompt-message
            else
            {
                temp_arr[i][j] = temp;   
                if(i < size-1 || j < size-1)
                    printf("\nInput recorded..\n"); 
            }
        }
    }
}

//function-for-getting-diagraph-matrix
void arrdg(int temp_arr[][size], char vertex[])
{
    int temp; 
    //get-conectivity-status-between-every-two-vertex-pairs
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; ++j)
        {
            menu:
            printf("\nConnectivity Status of %c and %c: ", vertex[i], vertex[j]);     
            scanf("%d", &temp);
            //handle-invalid-input-by-user
             if(temp > 2 || temp < 0)
            {
                printf("\nInvalid input.Try again..."); 
                goto menu;     
            }
            //for-valid-input-perform-insertion-and-prompt-message
            else
            {
                temp_arr[i][j] = temp; 
                if(i < size-1 || j < size-1)  
                    printf("\nInput recorded..\n"); 
            }
        }
    }
}

//function-for-getting-degree-of-vertex-in-undirected-graphs
void getdegreeud(int temp_arr[][size], char vertex[])
{
    //visit-each-pair-using-loops
    for(int i = 0; i < size; ++i)
    {
        //degree-counter
        int counter = 0;
        for(int j = 0; j < size; ++j)
        {
            //if-vertex-are-connected-increment-counter
            if(temp_arr[i][j] == 1)
            {
                counter++; 
            }
        }
        //prompt-degree-of-the-vertex
        printf("\n%c has degree %d.", vertex[i], counter); 
    }
}

//function-for-getting-indegree/outdegre-of-vertex-in-diagraph
void getdegreedg(int temp_arr[][size], char vertex[])
{
    //visit-each-pair-using-loops
    for(int i = 0; i < size; ++i)
    {
        //indegree-or-outdegree-counter
        int counter = 0, count = 0;
        for(int j = 0; j < size; ++j)
        {
            //increment-counters-if-conditions-true
            if(temp_arr[i][j] == 1)
            {
                counter++; 
            }
            else if(temp_arr[i][j] == 0)
            {
                count++; 
            }
        }
        //prompt-indegree-and-outdegree-of-vertex
        printf("\n%c has out-degree: %d and in degree: %d.", vertex[i], counter, count); 
    }
}

//function-for-showing-adjacency-matrix
void show(int temp_arr[][size], char vertex[])
{
    printf("\n   "); 
    //visit-every-vertex-IDs
    for(int i = 0; i < size; i++)
    {
        //print-vertex-IDs
        printf("%c ", vertex[i]); 
    }
    //visit-every-vertex-pairs
    for(int i = 0; i < size; ++i)
    {
        //print-vertex-IDs-and-data-at-index
        printf("\n%c  ", vertex[i]); 
        for(int j = 0; j < size; ++j)
        {
            printf("%d ", temp_arr[i][j]);
        }
    }
}

//menu-function
void menu(int choice, int uarr[][size], int darr[][size], char vertex[])
{
     //get-matrix-for-asked-graph
     if(choice == 1)
            {
                printf("\nEnter the data for Undirected Graph\n(If mentioned vertex are connected insert 1, if not insert 0.)\n"); 
                arrug(uarr, vertex);
                printf("\nAdjacency Matrix for the Undirected Graph has been obtained.");
                scrnclr(); 
            }
            else if(choice == 2)
            {
                printf("\n(If edge is directed from 1st to 2nd insert 1, else insert 0.\nIf vertex are not connected then enter 2.)\n");
                arrdg(darr, vertex); 
                printf("\nAdjacency Matrix for the Directed Graph has been obtained.");
                scrnclr();
            }
    int command;
    //show-menu-get-command-from-user
    menu:
        printf("\nOperation Available\n1.Degree of vertex(in-degree/out-degree for diagraph OR degree for undirected graph\n2.show Adjacency Matrix\n3.Exit\nChoice: "); 
        scanf("%d", &command); 
        //toggle-between-different-commands
        switch (command)
        {
        case 1:
            //finding-degree-for-the-graph
            if(choice == 1)
            {
                printf("\nDegrees of all the vertex of the Undirected Graph is: \n"); 
                getdegreeud(uarr, vertex);
            }
            else if(choice == 2)
            {
                printf("\nIn-Degree and Out-Degree of the vertex of the Diagraph: \n"); 
                getdegreedg(darr, vertex); 
            }
            break; 
        case 2:
            //printing-adjacency-matrix 
            if(choice == 1)
            {
                printf("\nAdjacency Matrix for the Undirected Graph is: \n\n"); 
                show(uarr, vertex); 
            }
            else if(choice == 2)
            {
                printf("\nAdjacency Matrix for the Directed Graph is: \n\n"); 
                show(darr, vertex); 
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
        scrnclr(); 
        goto menu;
}