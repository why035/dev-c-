/*
题目描述
两个质数的和是S，它们的积最大是多少?
输入
一个不大于10000的正整数S，为两个质数的和。
输出
一个整数，为两个质数的最大乘积。数据保证有解。
样例输入
50
样例输出
89
*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool Is_prime(int n){
	if(n<2)return false;
	if(n==2)return false;
	if(n%2==0)return false;
	int limit=(int)sqrt(n);
	for(int i=3;i<=limit;i++){
		if(n%i==0)return false;
	}
	return true;
} 

int Max_product(int s){
	int p=s/2;
	while(p>=2){
		int q=s-p;
		if(Is_prime(p)&&Is_prime(q)){
			return p*q;
		}
		p--;
	}
	return -1;
}

int main(){
	int s;
	scanf("%d",&s);
	printf("%d",Max_product(s));
	return 0;
}
