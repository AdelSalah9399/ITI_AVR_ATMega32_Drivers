#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Q_array.h"



void main ()
{	u8 choose;
	u8 data;
	printf("please choose what do you want:\nchoose [1] to enqueue\nchoose [2] to dequeue\nchoose [3] to clear queue\nchoose [4] to print queue\n");
	scanf("%d",&choose);
	
	switch(choose)
	{
	case 1 :
		printf("enter the data:");
		scanf("%d",&data);
		EnQueue(data);
		break;
	case 2 :
		DeQueue(DataArry);
		break;
	//case 3 :
		//Clear_Q(&Q);
		//break;
	case 4 :
		void Print_Q(DataArry);
		break;
	
	}
}