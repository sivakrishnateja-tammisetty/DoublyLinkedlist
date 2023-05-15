#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
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
	display(&head);
	return 0;
}
