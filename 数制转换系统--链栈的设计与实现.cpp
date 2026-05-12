// 任务3-6-数制转换-链式栈.cpp : 定义控制台应用程序的入口点。
#include "stdio.h"
#include "stdlib.h"
typedef int ElemType;
typedef struct snode
{
	ElemType data;
	struct snode *next;
}linkStack;

linkStack *Init_Stack()
{
	linkStack *top;
	top=NULL;
	return top;
}
int Empty_Stack(linkStack *top)
{
	if (top== NULL)      // 1
		return 1;
	else
		return 0;
}

linkStack *Push(linkStack *top,ElemType x)
{
	linkStack *s;
	s=(linkStack *)malloc(sizeof(linkStack));
	s->data=x;//
	s->next=top;
	top=s;
	return top;
}
linkStack *Pop(linkStack *top,ElemType *e)
{
	linkStack *x;
	if(top==NULL)
		printf("Underflow!\n");
	else
	{
		*e=top-> data;   // 2
		x=top;
		top=top-> next;   // 3
		free(x);
	}
	return top;
}
int Get_Top(linkStack *top)
{
	int x;
	if(top==NULL)
		printf("underflow!\n");
	else
		x=top->data;
	return x;
}
int Length_Stack(linkStack *top)
{
	int x=0;
	linkStack *s=top;
	while(s!=NULL)
	{
		x=x+1;
		s=s->next;
	}
	return x;
}
void clear(linkStack *top)
{
	linkStack *x;
	while(top!=NULL)
	{
		x=top;
		top=top->next;
		free(x);        // 4
	}
}
void conversion(int N,int R)
{
	linkStack *s;
	int x;
	char c;
	s=Init_Stack();
	while(N)
	{
		s= Push(s,N% R); // 5 和 6
		N=N/ R;		  // 7
	}
	while(!Empty_Stack(s))
	{
		s= Pop(s,&x);    // 8
		if(x<10)
			printf("%d",x);
		else{
			c='A'+x-10;
		    printf("%c",c);
		}
	}
}
int main( )
{
	int N,R;
    printf("输入十进制的整数:\n");
	scanf("%d",&N);
    printf("输入数制:\n");
	scanf("%d",&R);
	conversion(N,R);
	return 0;
}

