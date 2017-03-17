// Program for Deleting Data in a Doubly Linklist

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


int length()
{
	int l=0;
	int i;
	
	struct node *position = head;
	
	while(position != NULL)
	{
		l++;
		position = position->next;
		
	}
	return l;
}


struct node *lastposition()
{
	int i;
	int l  = length();
	struct node *temp = head;
	
	for (i=1;i<=l-1;i++)
	{
		temp = temp->next;

	}
	
	return temp;
	
}


bool empty()
{
	struct node *temp = head;
	
	return(temp == NULL);	
}


int checkposition (int x)
{
	int l = length();
	bool e = empty();
	
	if( e || x<1 || x>l)
	return 0;
	
	else if (x==1)
	{
	 return 1;
	}
	
	else if (x==l)
	 return 2;
	
	else if(x>1 && x<l)
	 return 3;
		
}


void deletefirst()
{
	struct node* position_pointer = head;
	struct node* newfirst_pointer;
	
	newfirst_pointer = position_pointer->next;
	newfirst_pointer -> prev = NULL;

	position_pointer -> next = NULL;

	head = newfirst_pointer;
		
}


void deletelast()
{
	struct node* newlast_pointer;
	struct node* position_pointer = lastposition();
	
	newlast_pointer = position_pointer -> prev;
	
	position_pointer -> prev = NULL;
	newlast_pointer -> next = NULL;
	
}


void deletebtw(int p)
{
	struct node* position_pointer = head;
	struct node* previous_pointer;
	struct node* current_pointer;
	int i;
	
	for (i=1;i<=p;i++)
	{
		if (i==p-1)
		{
			previous_pointer = position_pointer;
		}
		else if(i==p)
		{
			current_pointer = position_pointer;
		}

		position_pointer = position_pointer->next;
				
	}

 	previous_pointer->next = position_pointer;
	position_pointer->prev = previous_pointer;
	
	current_pointer->next = NULL;
	current_pointer->prev = NULL;	
	
}


void deleteanywhere(int p)
{
	int l = length();
	bool e = empty();
	int pos_check = checkposition(p);
	
	if (pos_check == 0)
	{
		if(e)
		printf("\n----- List is Empty ------\n");
		
		else if(p<1 || p>l)
		printf("\n---- Invalid Position ----\n");
	}
	else if(pos_check == 1)
	deletefirst();
	
	else if(pos_check == 2)
	deletelast();
	
	else if(pos_check == 3)
	deletebtw(p);
	
	
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
	int l;
    create(100);
	create(10);
	create(8);
	create(144);
	create(5);
	create(15);
	create(18);
	create(500);
	
	printlist();
	
	
/*	deletebtw(3);
	printlist();
	
	deletefirst();
	printlist();	
	
	deletelast();*/
	
	deleteanywhere(1);
	printlist();
	
	l=length();
	deleteanywhere(l);
	printlist();
	
	deleteanywhere(5);
	printlist();
	
	deleteanywhere(10);
//	printlist();			
	
	deleteanywhere(-8);
//	printlist();
		
	printlist();
	
}

