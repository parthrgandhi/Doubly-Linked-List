// Program for Creating a Doubly Linklist

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;
struct node *previous = NULL;


void create (int a)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	
	temp->data = a;
	temp->prev = NULL;
	temp->next = head;
	
	if(previous!=NULL)
	previous->prev = temp;
	
	head = temp;
	previous = temp;	
}

void printlist()
{
	struct node *position = head;
	
	printf("\nData\t:Current\t:Previous\n");
	
	while (position !=NULL)
	{
		printf("%d\t:%d\t:%d\n",position->data,position,position->prev);
		position = position->next;
	}
}

void main()
{
	create(10);
	create(8);
	create(5);
	create(15);
	create(18);
	
	
	printlist();
	
}

