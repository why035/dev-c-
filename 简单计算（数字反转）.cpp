/*题目描述
给定一个整数，请将该数各个位上数字反转得到一个新数。
新数也应满足整数的常见形式，即除非给定的原数为零，
否则反转后得到的新数的最高位数字不应为零
输入
输入共1行，一个整数N
输出
输出共1行，一个整数，表示反转后的新数。
样例输入
-380
样例输出
-83 
数据范围
1,000,000,000≤N≤1,000,000,000
*/

#include<stdio.h> 
int main(){
	int N;
	scanf("%d",&N);
	if(N==0){
		printf("0\n");
		return 0;
	}
	int reverse=0;
	while(N!=0){
		reverse=reverse*10+N%10;
		N/=10;
	}
	printf("%d",reverse);
	
	return 0;
}
