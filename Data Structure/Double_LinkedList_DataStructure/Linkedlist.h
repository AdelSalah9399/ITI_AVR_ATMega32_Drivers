#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#define Null   (void*)0

struct node
{
	u8 PlayerName[20];
	u8 Number ; 
	u8 ID ;
	u16 Age ; 
	
	struct node *next ; //
	struct node *prev ; //
};

typedef struct node   Player ; 


Player* Head = Null ; 

Player* Tail = Null ;  


Player* Create_Element(void);

void Add_PlayerFromLast(void); 

Player* Search_Player(u8 ID) ; 

void Remove_Player(u8 ID) ; 


void  Sacn_PlayerInfo(Player* User1) ; 


void Display_PlayerInfo(u8 ID) ;  




#endif