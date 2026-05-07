/*
[入门]因子求和
已知一个正整数N(20<=N<=1000000)，请你编写程序求出该数的全部因子(不包括1和本身)的和。
输入
N
输出
一个整数(因子和)
样例输入
24
样例输出
35
*/

#include<stdio.h>
int main (){
	int N;
	int b=0;
	scanf("%d",&N);
	int a=N;
	while(a>2){
		a--;
		if(N%a==0){
			b+=a;
		}
	}
	printf("%d",b);
	
	return 0;
}
