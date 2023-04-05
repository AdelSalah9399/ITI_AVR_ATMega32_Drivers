

	

u8 DataArry[Max_Size]={0} ; 
u8 Head=0 ; 
u8 Tail=-1 ; 
u8 size=0 ;


void EnQueue(u8 Data)
{
	if (IsFul()==Fully)
	{	printf("full\n");
		return ; 
	}
	else
	{
		if (tail==Max_Size-1)
		{
			tail=0;
		}	
		tail++;
		DataArry[tail] ;
		size++;
		/* --OR--
		tail = (tail+1) % Max_Size;
		DataArry[tail] = data ;
		size++;
		*/
	}
}


void DeQueue(DataArry) //no argument or entering data just action
{
	if (IsEmpty()==Empty)
	{
		printf("empty\n");
		return ;
	}
	else 
	{
		if (head==Max_Size-1)
		{
			head=0;
		}
		printf("%d\n",DataArry[head]);
		head++;
		size--;
		/*--OR--
		head = (head+1) % Max_Size;
		size--;*/
	}
}



u8 IsEmpty(void)  
{
	 if (size==0) //or head == tail
	 {	printf("empty\n");
		 return Empty ;
	 }
	 else 
	 {
		 return NotEmpty ; 
	 }
}

u8 IsFul(void) 
{
	if (size==Max_Size-1)//or   head==tail+1    
	{	printf("full\n");
		return Fully ; 
	}
	else 
	{
		return NotFully ; 
	}
}



void Print_Q(DataArry)
{	int i;
	if (tail>head)
	{
		for(i=head;i<tail;i++)
		printf("%d\n",DataArry[i]);
	}
	else
	{
		for(i=head;i<Max_Size-1;i++)
		{
		printf("%d\n",DataArry[i]);
		}
		for(i=0;i<tail;i++)
		{
		printf("%d\n",DataArry[i]);
		}
	}
}
