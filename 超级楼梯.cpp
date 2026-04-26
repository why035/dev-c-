/*
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？

输入

输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。

输出

对于每个测试实例，请输出不同走法的数量

样例输入
2 2 3 

样例输出
1 2 
*/



#include<stdio.h>
int main(){
 int N , M;
  int i; 
 int dp[45];
 scanf("%d",&N);
 dp[1]=0;
 dp[2]=1;
 dp[3]=2;
 for (i=4;i<45;i++){
	dp[i]=dp[i-1]+dp[i-2];
 }
 /*
 for (i=0;i<N;i++){
	scanf("%d",&M);
	printf("%d\n",dp[M]);
 }
*/
while(N--){
	scanf("%d",&M);
	printf("%d\n",dp[M]);
}

return 0;
}
