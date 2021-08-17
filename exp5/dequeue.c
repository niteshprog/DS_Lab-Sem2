		#include<stdio.h>
		#include<stdlib.h>
		
		
		//structure-defination
		struct node{
			struct node *prev; 
			int data; 
			struct node *next; 
		};
		
		//create-one-node
		struct node *createNode(int d){
			//DMA-for-single-node
			struct node *p = (struct node*)malloc(sizeof(struct node)); 
			p->data = d; 
			p->prev = NULL; 
			p->next = NULL;
			//return-pointer-to-the-node
			return (p);  
		}
		
		//insert-at-front
		void insertAtFront(struct node **front, struct node **rear)
		{
			//get-the-data
			int data; 
			printf("\nEnter the data: "); 
			scanf("%d", &data); 
			//invoke-the-createNode-pointer
			struct node *p = createNode(data); 
			//check-if-the-list-was-empty
			if((*front) == NULL && (*rear) == NULL)
			{
				(*front) = p; 
				(*rear) = p;
				printf("\nQueue was empty. Now has one node."); 
			}
			//if-was-not-empty-then-add-at-front
			else 
			{
				p->next = (*front); 
				(*front)->prev = p; 
				(*front)= p; 
				printf("\nQueue had already some node. Insertion at Front done."); 
			}
		}
		
		//function-to-add-at-rear
		void insertAtRear(struct node **front, struct node **rear)
		{
			//get-data
			int data; 
			printf("\nEnter the data: "); 
			scanf("%d", &data); 
			//invoke-the-createNode-pointer
			struct node *p = createNode(data); 
			//check-if-the-list-was-empty
			if((*front) == NULL && (*rear) == NULL)
			{
				(*front) = p; 
				(*rear) = p;
				printf("\nQueue was empty. Now has one node."); 
			}
			//if-was-not-empty-then-add-at-rear
			else 
			{
				p->prev = (*rear); 
				(*rear)->next = p; 
				(*rear) = p; 
				printf("\nQueue had already some node. Insertion at Front done."); 
			}
		}
		
		//function-for-deleting-front-element
		void deleteAtFront(struct node **front, struct node **rear)
		{
			//check-if-the-queue-has-any-element-to-delete-element
			if ((*front) == NULL && (*rear) == NULL)
			{
				printf("\nQueue Empty. Can't delete"); 
			}
			//check-if-the-queue-has-only-one-element
			else if((*front) == (*rear))
			{
				printf("\nDeleted Node is: %d", (*front)->data); 
				free(*front); 
				(*front) = NULL; 
				(*rear) = NULL; 
				printf("\nDeQueue Had only one element. Now it is empty.."); 
			}
			//if-more-then-one-element-delete-first-element
			else
			{
				printf("\nDeleted Node is: %d", (*front)->data);
				(*front) = (*front)->next; 
				free((*front)->prev); 
				(*front)->prev = NULL; 
				printf("\nNode Deletion successfull.."); 
			}
		}
		
		//function-for-deleting-rear-element
		void deleteAtRear(struct node **front, struct node **rear)
		{
			//check-if-the-queue-has-any-element-to-delete-element
			if((*front) == NULL && (*rear) == NULL)
			{
				printf("\nDeQueue is empty. Deletion not possible"); 
			}
			//check-if-the-queue-has-only-one-element
			else if((*front) == (*rear))
			{
				printf("\nDeleted Node is: %d", (*rear)->data); 
				free(*front); 
				(*front) = NULL; 
				(*rear) = NULL; 
				printf("\nDeQueue had only one element. It is empty now.."); 
			}
			//if-more-then-one-element-delete-rear-element
			else 
			{
				printf("\nDeleted Node is: %d", (*rear)->data); 
				(*rear) = (*rear)->prev; 
				free((*rear)->next); 
				(*rear)->next = NULL; 
				printf("\nNode deletion successfull..."); 
			}
		}
		
		//display-function
		void display(struct node **front)
		{
			//check-if-the-list-is-empty
			if((*front) == NULL)
			{
				printf("\nDeQueue is empty.."); 
			}
			//if-not-then-print-the-queue
			else 
			{
				struct node *temp = (*front); 
				printf("\nNode are:\n"); 
				while(temp)
				{
					printf("%d ", temp->data); 
					temp = temp->next; 
				}
			}
		}
		
		//to-get-first-element-function
		void getfront(struct node **front)
		{
			if((*front) == NULL)
			{
				printf("\nDeQueue is Empty"); 
			}
			else 
			{
				printf("Data at front is: %d", (*front)->data); 
			}
		}
		
		//to-get-rear-element-function
		void getrear(struct node **rear)
		{
			if((*rear) == NULL)
			{
				printf("\nDeQueue is Empty"); 
			}
			else 
			{
				printf("Data at front is: %d", (*rear)->data); 
			}
		}
		
		//menu-for-program
		int menu()
		{
			//display-menu-content-and-get-operation
			int ch; 
			printf("\n1.Insert at Front"); 
			printf("\n2.Insert at Rear"); 
			printf("\n3.Delete at Front"); 
			printf("\n4.Delete at Rear"); 
			printf("\n5.Display");
			printf("\n6.Get front element"); 
			printf("\n7.Get rear element"); 
			printf("\n8.Exit");
			printf("\nChoice: "); 
			scanf("%d", &ch); 
			return ch; 
		}
		
		//main-function
		int main()
		{
			int breakInfiniteLoop; 
			system("clear");
//			menu(); 
			//declare-front-rear-structure-variables-for-deletion-insertion-display
			struct node *front = NULL, *rear = NULL;  
			//invoke-function-on-the-basis-of-choices-made-by-user
			while(1)
			{
				system("clear"); 
				printf("\n----------------------------------------------------------------\n"); 
				switch(menu())
				{
					case 1:
						insertAtFront(&front, &rear); 
						getchar(); 
						break; 
					case 2:
						insertAtRear(&front, &rear); 
						getchar(); 
						break; 
					case 3:
						deleteAtFront(&front, &rear); 
						getchar(); 
						break; 
					case 4:
						deleteAtRear(&front, &rear); 
						getchar();
						break;
					case 5:
						display(&front); 
						getchar(); 
						break; 
					case 6: 
						getfront(&front); 
						getchar(); 
						break; 
					case 7: 
						getrear(&rear); 
						getchar(); 
						break; 
					case 8:
						//get-out-of-switch-case
						breakInfiniteLoop = 1; 
						break; 
					default: 
						printf("\nInvalid Choice.."); 
				}
				//get-out-of-loop
				if(breakInfiniteLoop == 1)
				{
					break; 
				}
			}
			return 0; 
		}
