/*
输入一个正整数 n。
要求把 n 拆成 若干个正奇数相加。
拆分不考虑顺序，问一共有多少种不同拆分方案。
 
限制
 
1.?只能用奇数：1,3,5,7……

2.?不能使用偶数

3.?组合不看顺序（1+3 和 3+1 算同一种）

4.?结果对 10^9+7 取模
 
样例
 
输入：4
合法拆分：
 
1.?1+1+1+1

2.?1+3
输出：2
*/

#include<stdio.h>
#define mod 1000000007
int f(int n,int max){
	if (n==0) return 1;
	if (n<0||max<0) return 0;
	if(max==0) return 0;
	if(max>n) return f(n,n)%mod;
	
	if (max%2==0) return f(n,max-1)%mod;
	return (f(n,max-2)+f(n-max,max))%mod;
	
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n,n));
	
	
	
	return 0;
}
