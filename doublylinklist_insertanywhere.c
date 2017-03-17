// Program for Inserting Data in a Doubly Linklist

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


void insertfirst(int a)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	//struct node *next_position;
	struct node *position = head;
	
	//next_position = position->next
	
	temp->data = a;
	temp->next = position;
	temp->prev = NULL;
	
	head = temp;
	position->prev = temp;
}


void insertlast(int a)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	struct node *last;
	
	last = lastposition();	
	
	printf("\nLast Position\t:%d\n",last);
	
	temp->data = a;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
	
/*	printf("\nNext\t:%d\n",temp->next);
	printf("\nPREV\t:%d\n",temp->prev);
	printf("\nDATA\t:%d\n",temp->data);*/
	
}


void insertbtw(int p, int a)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *current_position;
	struct node *previous_position;
	struct node *position_pointer = head;
	int i;
	                                                                                                                                     
	for(i=1;i<=p;i++)
	{
		if (i==p)
		{
			current_position = position_pointer;	
		}	
		else if(i==p-1)
		{
			previous_position = position_pointer;
		}
	
		position_pointer = position_pointer->next;
	}
	
	
	temp->data = a;
	temp->prev = previous_position;
	temp->next = current_position;
	
	current_position->prev = temp;
	//current_position->next = position_pointer;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   p;
	previous_position->next = temp;
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


void insertanywhere(int p,int a)
{
	int cp = checkposition(p);
	bool e = empty();
	
	if (cp == 0)
	{
		if (e)
		{
			printf("\nList Is Empty\n");
		}
		else
		{
			printf("\nInvalid Position\n");
		}
	}
				
	
	else if (cp == 1)
	{
		insertfirst(a);
	}
	
	else if (cp == 2)
	{
		insertlast(a);
	}
	
	else if (cp == 3)
	{
		insertbtw(p,a);
	}
	
	
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
	create(10);
	create(8);
	create(5);
	create(15);
	create(18);
	
	printlist();
	
/*	insertfirst(100);
	insertlast(500);
	insertbtw(2,576);
	insertfirst(357);
	printlist();
	
	insertbtw(3,144);
	printlist();

	insertfirst(111);	
	printlist();
			
	insertbtw(5,140);*/
	
	insertanywhere(2,576);
	insertanywhere(1,357);  
	l= length();
	insertanywhere(l,121);
	insertanywhere(4,144);
	insertanywhere(15,169);
	
/*	insertanywhere(1,100);
	l= length();
	insertanywhere(l,500);
	insertanywhere(2,576);
	insertanywhere(1,357);
	insertanywhere(3,144);
	insertanywhere(1,111);
	insertanywhere(5,144);
	insertanywhere(6,140);*/
	
	
	
	printlist();
	
}

