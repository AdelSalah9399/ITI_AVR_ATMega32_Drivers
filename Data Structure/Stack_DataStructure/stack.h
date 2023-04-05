#ifndef STACH_H_
#define STACH_H_

#define MaxStack 5
typedef int StackEntry ;

typedef struct 
{	
	u8 top;
	StackEntry entry[MaxStack];
	
}Stack;

void  GetTop            (StackEntry* pe,Stack* ps);
void  POP               (StackEntry* pe,Stack* ps);
void  PUSH              (StackEntry e,Stack *ps);
void  ClearStack        (Stack* ps);
void  Initialize_Stack  (Stack* ps);
void  Display           (Stack* ps);
u8    StackFull         (Stack* ps);
u8    EMPTY             (Stack* ps);
u8    GetSize           (Stack* ps);





#endif