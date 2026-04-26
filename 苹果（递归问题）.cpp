/*
 把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
 
输入
第一行是测试数据的数目t（0≤t≤20）。以下每行均包含二个整数M和N，以空格分开。1≤M，N≤10。
 
输出
对输入的每组数据M和N，用一行输出相应的K。
 
样例输入
1
7 3
 
样例输出
8

*/



#include<stdio.h>
int count(int M,int N){
	if (M==0) return 1;
	if(N==0) return 0;
	if(M<N) return count(M,M);
	else return count(M-N,N)+count(M,N-1);	
}
int main(){
	int t,M,N;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&M,&N);
		printf("%d",count(M,N));
	}
	/*
	while(t>0){
		scanf("%d %d",&M,&N);
		printf("%d",count(M,N));
		t--;
	}
	*/
	return 0;
} 
