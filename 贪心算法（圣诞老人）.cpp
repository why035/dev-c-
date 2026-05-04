/*圣诞节来临了，在城市A中圣诞老人准备分发糖果，现在有多箱不同的糖果，
每箱糖果有自己的价值和重量，每箱糖果都可以拆分成任意散装组合带走。
圣诞老人的驯鹿最多只能承受一定重量的糖果，请问圣诞老人最多能带走多大价值的糖果。
输入
第一行由两个部分组成，分别为糖果箱数正整数n(1 <=n<=100)，
驯鹿能承受的最大重量正整数 w(0<w<100)，两个数用空格隔开。
其余 n行每行对应一箱糖果，由两部分组成，分别为一箱糖果的价值正整数v和重量正整数 w，中间用空格隔开。
输出
输出圣诞老人能带走的糖果的最大总价值，保留1位小数。输出为一行，以换行符结束。
样例输入
4 15
100 4
412 8
266 7
591 2
样例输出 
1193.0
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int value;
	int weight;
	double unit;
}Candy;
int cmp (const void *a,const void *b){
	Candy *pa=(Candy*)a;
	Candy *pb=(Candy*)b;
	double x=pa->unit;
	double y=pb->unit;
	return (y>x)-(y<x);
}
int main(){
	int n,w;
	scanf ("%d %d",&n,&w);
	Candy boxes[100];
	for (int i=0; i<n;i++){
		scanf("%d %d",&boxes[i].value,&boxes[i].weight);
		boxes[i].unit=(double)boxes[i].value/boxes[i].weight;		
	}
	qsort(boxes,n,sizeof(Candy),cmp);
	double total_value=0.0;
	int remain=w;
	for (int i=0;i<n&&remain>0;i++){
		if(boxes[i].weight<=remain){
			total_value+=boxes[i].value;
			remain-=boxes[i].weight; 
		}else{
			total_value+=remain*boxes[i].unit;
			remain=0;
		}
	}
	printf("%.1f\n",total_value);
	
	return 0;
}
