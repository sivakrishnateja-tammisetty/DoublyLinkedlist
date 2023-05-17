#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
/*
//DISPLAYING ELEMENTS OF A DOUBLY LINKED LIST
void display(struct node **head)
{
	struct node *p=*head;
	if(p==NULL)
	{
		printf("Elements was not there\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			p=p->right;
		}
	}
}


//INSERTION END AT THE END OF DOUBLY LINKED LIST
void insertAtEnd(struct node **head)
{
	struct node *fourth=(struct node*)malloc(sizeof(struct node*));
	int value;
	printf("Enter a value:");
	scanf("%d",&value);
	fourth->data=value;
	fourth->left=NULL;
	fourth->right=NULL;
	struct node *p=*head;
	if(p==NULL)
	{
		*head=fourth;
	}
	else
	{
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=fourth;
		fourth->left=p;
	}
}
*/
//INSERT AT SPECIFIED POSITION
void insertAtSpecifiedPosition(struct node **head)
{
	int position,value;
	printf("Enter position and value:");
	scanf("%d%d",&position,&value);
	struct node *temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
	struct node *p=*head;
	int count=1;
	while(p!=NULL)
	{
		if(count==position)
		{
			break;
		}
		p=p->right;
		count++;
	}
	if(p==NULL)
	{
		printf("Invalid posititon\n");
	}
	else
	{
		temp->right=p->right;
		p->right->left=temp;
		p->right=temp;
		temp->left=p;
	}
	printf("Inserting element at specified position in doubly linkedlist was successfully completed\n");
}
	int main()
{
	struct node *head=NULL;
	struct node *first=(struct node*)malloc(sizeof(struct node *));
	struct node *sec=(struct node *)malloc(sizeof(struct node*));
	struct node *third=(struct node *)malloc(sizeof(struct node *));
	head=first;
	first->left=NULL;
	first->data=10;
	first->right=sec;
	sec->left=first;
	sec->data=20;
	sec->right=third;
	third->left=sec;
	third->data=30;
	third->right=NULL;
	while(1)
	{
		int choice;
		printf("1) Insert at end 2) Insert at specified position 3) Delete at specified position 4) searching 5) Display 6) Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			insertAtEnd(&head);
		}
		
		else if(choice==2)
		{
			insertAtSpecifiedPosition(&head);
		}
		/*
		else if(choice==3)
		{
			deleteAtSpecifiedPosition(&head);
		}
		else if(choice==4)
		{
			searching(&head);
		}
		*/
		else if(choice==5)
		{
			display(&head);
		}
		else
		{
			break;
		}
	}
	return 0;
}
