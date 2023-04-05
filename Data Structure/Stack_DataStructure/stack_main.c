#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "stack.h"

/****************************IMPORTANT*********************************/
/*you need to enter MaxStack & StackEntry*/


void main()
{
	u8 q;
	Stack s;
	StackEntry e;
	Initialize_Stack(&s);
	u8 shoose;
	do {
	
	printf("to push          press 1 :\n");
	printf("to pop           press 2 :\n");
	printf("to get top       press 3 :\n");
	printf("to get size      press 4 :\n");
	printf("to clear stack   press 5 :\n");
	printf("to Display stack press 6 :\n");
	scanf("%d",&shoose);
	
	switch(shoose)
	{
		case 1 :
			if(!StackFull(&s))
			{
				printf("enter the data:");
				scanf("%d",&e);
				PUSH(e,&s);
			}
			break;
		case 2 :
			if(!EMPTY(&s))
			{
				POP(&e,&s);
				printf("%d\n",e);
			}
			break;
		case 3 :
			GetTop(&e,&s);
			printf("the top element is %d\n",e);
			break;
		case 4 :
			printf("the size is %d\n",GetSize(&s));
			break;
		case 5 :
			ClearStack(&s);
			break;
		case 6 :
			Display(&s);
			break;
		default:
			printf("wrong answer\n");
			break;
	}
		printf("\n\n\nto exit enter 0 press 1 to contiue:");
		scanf("%d",&q);
	}while(q!=0);
	
	
}