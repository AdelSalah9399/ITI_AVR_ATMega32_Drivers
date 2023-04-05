#include <stdio.h>
#include <stdli.h>
#include "STD_TYPES.h"


/*--------------------------------------------------------------1-creat the struct datatype---------------------------------------------------*/
typedef struct node_t
{
	u8 data;
	struct node_t* next;
}node;
/*--------------------------------------------------------------2-creat head of linkedlist----------------------------------------------------*/
node* head=NULL;
/*--------------------------------------------------------------3-function to creat node------------------------------------------------------*/
node* Creat_Node(void)
{
	return (node*)malloc(sizeof(node));
}
/*--------------------------------------------------------------4-function to add new node from the end----------------------------------------*/
void Add_node_end(node)
{
	printf("please enter data:");
	scanf("%d",&new->data);
	node* new=Creat_Node();
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{	node* temp=head;
		while(temp->next!=NULL)
		{
		temp=temp->next;
		}
		temp->next=new;
	}
}
/*--------------------------------------------------------------5-function to search for an element----------------------------------------*/
node* Search(u8 search_data)
{
	node* temp=head;
	while(temp->data!=search_data)
	{	
		if(temp==NULL)
		{
			return NULL;
		}
		temp=temp->next;
	}
	return temp;
}
/*--------------------------------------------------------------5-function to delete an element from anywhere--------------------------------*/
void Delete_node(u8 deleted_data)
{	
	node* temp=Search(deleted_data);
	node* temp2=head;
/*1-linkedlist has only one element*/
	if((temp==head)&&(temp->next=NULL))
	{
		free(temp);
	}
/*2-delete the first element*/
	else if (temp==head)
	{
		head=temp->next;
	}
/*3-delete the last element*/
	else if (temp->next==NULL)
	{
		while(temp2->next!=temp)
		{
			temp2=temp2->next;
		}
		temp2->next=NULL;
	}
/*4-delet any element in the middle*/
	else
	{
		while(temp2->next!=temp)
		{
			temp2=temp2->next;
		}
		temp2->next=temp->next;
	}
	free(temp);
}


