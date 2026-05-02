/*
为传承红色精神、凝聚青年力量，学校组织 “红色故事接力宣讲” 活动。宣讲规则如下：
只有 1 名同学时，只能讲 1 个红色故事；
每增加 1 名同学，所有人讲的故事总数会变成 上一轮总数的 2 倍再多 3 个。
现在知道最终讲了多少个红色故事，请问总共有多少同学讲故事？

输入
一个正整数 n（1 ≤ n ≤ 2^32-1）表示总共讲了n个红色故事。
输出
一个整数，表示讲故事的同学数。
样例输入
5
样例输出
2 
*/ 


#include<stdio.h>
int main(){
	long long n;
	scanf("%lld",&n);
	long long current=1;
	int student=1;
	while (current<n){
		current=current*2+3;
		student++;
	}
	printf("%d",student);
	
	
	return 0;
}
