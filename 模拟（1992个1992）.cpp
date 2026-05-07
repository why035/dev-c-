/*
1992个1992
题目描述
求1992个1992的乘积的末两位数是多少?
输入

输出
输出只有一行，包括1个整数。
*/

#include<stdio.h>
#include<math.h>
int main(){
	int ans=1;
	for (int i=0;i<1992;i++){
		ans=(ans*92)%100;
	}
	
	printf("%d",ans);
	return 0;
}
