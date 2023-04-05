#include <stdio.h>
#include <stdlib.h>
#include "Std_types.h"
#include "Linkedlist.h"


Player* Create_Element(void)
{
	return 	(Player*)malloc(sizeof(Player));
}

void Add_PlayerFromLast(void)
{
	Player* User = Create_Element() ; 
	if(User != Null)
	{
		Sacn_PlayerInfo(User);
		User->next = Null ; 
		
		if (Head == Null && Tail ==Null)
		{
		User->prev = Null ; 
		Head = User ; 
		Tail = User ; 
		}
		else
		{
		User->prev = Tail ; 
		Tail -> Next = User ; 
		Tail = User ; 
		} 
	}
	
}

Player* Search_Player(u8 ID) 
{
	Player*Temp = Null ; 
	/*case the linked list is not exist*/
	/*case the linked list have one element*/
	/*case the linked list have Players*/
	if (Head)//(Head != NULL )
	{
		Temp =Head ;
		while(Temp->ID != ID && Temp != Null)
		{
			Temp = Temp->next ;
		}
		if (Temp == Null) 
		{
			printf("Don't Found this ID \n");
			return Null ; 
		}
		else if (Temp->ID == ID)
		{
			return Temp ;
		}
	
		
	}
	else 
	{
		printf("Don't have linked list\n");
		return Null ; 
	}
} 



void  Sacn_PlayerInfo(Player* User1) 
{
	printf("Enter Player ID");
	scanf (" %d",&User1->ID);
	printf("Enter Player Name");
	scanf (" %s",&User1->PlayerName);
	printf("Enter Player Number");
	scanf (" %d",&User1->Number);
	printf("Enter Player Age");
	scanf (" %d",&User1->Age);

}

void Display_PlayerInfo(u8 ID) 
{
	Player* Display = Search_Player(ID);
	if(Display)
	{
		printf("Player ID :%d\n",Display->ID);
		printf("Player Name :%s\n",Display->PlayerName);
		printf("Player Number :%d\n",Display->Number);
		printf("Player Age :%d\n",Display->Age);
		
	}
}  

void Display_PlayersInfoall()
{
	Player* Display =Head ; 
	while (Display !=Null)
	{
		Display_PlayerInfo(Display->ID);
		Display = Display-Next ; 
	}
	
}