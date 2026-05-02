/*题目描述
一个正整数,如果它能被 7 整除,
或者它的十进制表示法中某个位数上的数字为 7,
则称其为与 7 相关的数。求所有小于等于 n (n<100)的与 7无关的正整数的平方和。
输入
输入为一行，正整数 n(n<100)。
输出
输出一行，包含一个整数，即小于或等于 n 的所有与 7 无关的正整数的平方和。
样例输入
21
样例输出
2336
*/
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
		arr[i]=i;
		if(i%7==0){
			arr[i]=0;
		}else if(i%10==7){
			arr[i]=0;
		}else{
			sum=sum+arr[i]*arr[i];
		}
	}
	printf("%d",sum);
	
	
	return 0;
} 
