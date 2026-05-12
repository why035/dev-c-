// 任务3-5-数制转换系统-顺序栈.cpp : 定义控制台应用程序的入口点。
#include<stdio.h>
#define StackSize 100 /*分配的栈空间大小*/
typedef int ElemType; /*假定栈元素的数据类型为整型*/
typedef struct
{
	ElemType data[StackSize];
	int top;
}SeqStack;
void Init_Stack(SeqStack *s)
{
	s->top = -1;
}

int Push(SeqStack *s,ElemType x)//压栈
{
	if(s->top == StackSize - 1)
	{
		printf("栈满\n");
		return 0;
	}
	else
	{
		s->data[++s->top] = x; // 只保留这一行自增
		return 1;
	}
}
int Pop(SeqStack *s,ElemType *x)//弹栈
{
	if(s->top == -1) // 修正判空条件：top=-1 才是空栈
	{
		printf("栈空\n");
		return 0;
	}
	else
	{
		*x = s->data[s->top];
		s->top--;
		return 1;
	}
}
int Empty_Stack(SeqStack *s)
{
	if(s->top < 0)
		return 1;
	else
		return 0;
}
void conversion(int N,int R)
{
	SeqStack s;
	int x;
	char c;
	Init_Stack(&s);
	while(N > 0) // 明确 N>0 避免 0 输入时死循环
	{
		Push(&s, N % R);
		N = N / R;
	}
	while(!Empty_Stack(&s))
	{
		Pop(&s,&x);
		if(x < 10)
			printf("%d",x);
		else
		{ 
			c = 'A' + x - 10;
		    printf("%c", c);
		}
	}
}
int  main( )
{
	int number, n;
    scanf("%d", &number);
    scanf("%d", &n);
    printf("%d需转换为%d进制\n",number,n);
    printf("转换后的结果为：\n");
    if (number == 0) { // 特殊处理输入 0 的情况
        printf("0");
    } else {
        conversion(number, n);
    }
    printf("\n");
    return 0;
}

