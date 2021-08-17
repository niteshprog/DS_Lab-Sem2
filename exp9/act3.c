//header-files
#include <stdio.h>
#include <stdlib.h>

//node-structure-body
struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
}*p = NULL, *root = NULL;

//function-prototypes
void clear(); 
struct node* new_node(int x);
struct node* insert(struct node *root, int x);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

//main-function
int main()
{
	int job, ele; 
    //get-job-from-user
	menu: 
	printf("\n1. Insert element\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Travesal\n5. Exit\nChoice: "); 
	scanf("%d", &job);
	clear(); 
	system("clear"); 
    //invoke-appropriate-function
	switch (job)
	{
	case 1:
        //get-the-data-to-be-inserted
		printf("\nEnter the data you want to enter: "); 
		scanf("%d", &ele);
        //check-if-the-tree-is-empty
		if(root == NULL)
		{
			root = new_node(ele); 
		}
        //if-tree-is-not-empty
		else 
		{
			insert(root, ele); 
		}
        //notify-for-successful-insertion
		printf("\nElement Inserted in the tree..."); 
		break;
	case 2: 
        //invoke-inorder-traversal
		printf("\nInorder Traversal of tree is: \n"); 
        //check-if-tree-is-empty
        if(root == NULL)
        {
            printf("\nTree is empty"); 
        }
        //if-tree-is-not-empty
        else
		{
            inorder(root);
        } 
		break;
    case 3: 
        //invoke-preorder-traversal
        printf("\nPre Order Traversal of tree is: \n"); 
        //if-tree-is-empty
        if(root == NULL)
        {
            printf("\nTree is empty"); 
        }
        //if-tree-is-not-empty
        else 
        {
            preorder(root); 
        }
        break; 
    case 4: 
        //invoke-postorder-traversal
        printf("\nPost Order Traversal of tree is: \n"); 
        //check-if-tree-is-empty
        if(root == NULL)
        {
            printf("\nTree is empty"); 
        }
        //if-not-empty
        else
        {
            postorder(root); 
        }
        break;
	case 5: 
        //exit-program
		exit(0); 
	default:
        //validate-job-from-user
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
{;
    //DMA-for-node
    p = malloc(sizeof(struct node));
    //allocate-attributes-to-nodes
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
    //return-pointer
    return p;
}

//function-to-insert-node-in-tree
struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    //check-if-tree-is-empty
    if(root==NULL)
        return new_node(x);
    //if-data-is-greater-than-root-value
    else if(x>root->data)
        root->right_child = insert(root->right_child, x);
    //if-data-is-smaller-than-root-value
    else 
        root->left_child = insert(root->left_child,x);
    //return-pointer-pointing-to-root
    return root;
}

//function-for-inorder-traversal
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

//function-for-postorder-traversal
void postorder(struct node *root)
{
    //check-if-tree-is-empty
    if(root!=NULL) 
    {
        //visiting-left-child
        postorder(root->left_child);
        //visiting-right-child
        postorder(root->right_child);
        //print-root-value
        printf(" %d ", root->data); 
    }
}

void preorder(struct node *root)
{
    //check-if-tree-is-not-empty
    if(root!=NULL) 
    {
        //print-root-value
        printf(" %d ", root->data);
        //visiting-left-child
        preorder(root->left_child);
        //visiting-right-child
        preorder(root->right_child);
    }
}

