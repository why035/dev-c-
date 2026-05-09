/*题目描述
n个人围成一圈，并依次编号1~n。从编号为1的人开始，
按顺时针方向每隔一人选出一个，剩下的人重新围成一圈，
如此循环直到剩下两人，这剩下的两人就是幸运儿。如果你想成为最后两个幸运儿，
请问开始时应该站在什么位置？（设3<=n<=50）
输入
有多个测试序列。每行是开始时的人数n。
输出
第1行是选出顺序，位置编号之间用一个空格分开，包括末尾空格。
第2行是两名幸运儿的开始位置（按升序排列）。
样例输入
12
20
45
样例输出
2 4 6 8 10 12 3 7 11 5 
1 9
2 4 6 8 10 12 14 16 18 20 3 7 11 15 19 5 13 9 17 
1 11
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 3 7 11 15 19 23 27 31 35 39 43 5 13 21 29 37 45 1 9 25 33 41 17 
7 31
*/


#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
	int a[55],out[55],next[55];
	int len=n;
	int out_cnt=0;
	int next_cnt=0;
	for (int i=0;i<n;i++){
		a[i]=i+1;
	}
	while(len>2){
		next_cnt=0;
	for (int i=0;i<len;i++){
		if(i%2==1){
			out[out_cnt++]=a[i];
			
		}else{
			next[next_cnt++]=a[i];
		}
	}
		for(int i=0;i<next_cnt;i++){
			a[i]=next[i];
		}
		len = next_cnt;
		
}
		for(int i=0;i<out_cnt;i++){
			printf("%d ",out[i]);
		}
		if(a[0]>a[1]){
			printf("\n%d %d",a[1],a[0]);
		}else{
			printf("\n%d %d",a[0],a[1]);
		}
}
	return 0;
}
