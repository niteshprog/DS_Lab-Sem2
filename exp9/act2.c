//header-files
#include <stdio.h>
#include <stdlib.h>

//node-structure-body
struct node
{
    int data; 
    struct node *right_child; 
    struct node *left_child; 
}*p = NULL, *root = NULL;

//function-prototypes
void clear(); 
struct node* new_node(int x);
struct node* insert(struct node *root, int x);
void inorder(struct node *root);

//main-function
int main()
{
	int job, ele; 
	//get-job-from-user
	menu: 
	printf("\n1. Insert element\n2. Inorder Traversal\n3. Exit\nChoice: "); 
	scanf("%d", &job);
	clear(); 
	system("clear");
	//invoke-the-respective-function-using-switch-case 
	switch (job)
	{
	case 1:
		//get-the-element-to-be-inserted
		printf("\nEnter the data you want to enter: "); 
		scanf("%d", &ele);
		//if-tree-is-empty
		if(root == NULL)
		{
			root = new_node(ele); 
		}
		//if-not-empty
		else 
		{
			insert(root, ele); 
		}
		//notify-for-successful-insertion
		printf("\nElement Inserted in the tree..."); 
		break;
	case 2: 
		//invoke-inorder-function
		printf("\nInorder Traversal of tree is: \n"); 
		inorder(root); 
		break;
	case 3: 
		//exit-program
		exit(0); 
	default:
		printf("\nInvalid Input, Try with a valid one.."); 
		break;
	}
	clear(); 
	system("clear"); 
	goto menu; 
	return 0; 
}

//function-for-clearing-buffer
void clear()
{
    while ((getchar()) != '\n');
    printf("\nPress Enter to continue...");
    getchar();
}

//function-to-create-a-node
struct node* new_node(int x)
{
	//DMA-for-a-node
    p = malloc(sizeof(struct node));
	//assign-attributes-to-node
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
	//return-the-pointer
    return p;
}

//function-for-insertion-of-node-in-tree
struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
	//if-tree-is-empty
    if(root==NULL)
        return new_node(x);
	//if-data-is-greater-than-root-value
    else if(x>root->data) 
        root->right_child = insert(root->right_child, x);
	//if-data-is-smaller-than-root-value
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    //return-pointer-pointing-to-root
	return root;
}	

//function-to-perform-inorder-traversal
void inorder(struct node *root)
{
    //if-tree-is-not-empty
	if(root!=NULL)
    {
        //visiting-left-child
		inorder(root->left_child);
		//print-root-value
        printf(" %d ", root->data);
		//visiting-right-child
        inorder(root->right_child);
    }
}

