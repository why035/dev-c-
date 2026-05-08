/*
孙膑将赛马的方案从“上等马对上等马、中等马对中等马、下等马对下等马“
转变为“下等马对上等马、上等马对中等马、中等马对下等马”，
决策方案的选择不同直接导致比赛结果的不同，我们要善于用局部的牺牲去换取全局的胜利，
从而达到以弱胜强的目的。
话说齐王和田忌又要赛马了，他们各派出N匹马，
每场比赛，输的一方将要给赢的一方200两黄金，如果是平局的话，
双方都不必拿出钱。现在每匹马的速度值是固定而且已知的，
而齐王出马也不管田忌的出马顺序。请问田忌该如何安排自己的马去对抗齐王的马，才能赢取最多的钱?
输入
第一行为一个正整数n(n<=2000)，表示双方马的数量。
第二行有N个整数表示田忌的马的速度。
第三行的N个整数为齐王的马的速度
输出
仅有一行，为田忌赛马可能赢得的最多的钱，结果有可能为负。
样例输入
3
92 83 71 
95 87 74
样例输出
200
*/

#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	int x=*(int*)a;
	int y=*(int*)b;
	return (x>y)-(x<y);
} 
int main(){
	int n;
	scanf("%d",&n);
	int t[2005],q[2005];
	for (int i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	for (int i=0;i<n;i++){
		scanf("%d",&q[i]);
	}
	qsort(t,n,sizeof(int),cmp);
	qsort(q,n,sizeof(int),cmp);
	
	int tl=0;
	int tr=n-1;
	int ql=0;
	int qr=n-1;
	int sum=0;
	for (int i=0;i<n;i++){
	if (t[tl]>q[ql]){
		tl++;
		ql++;
		sum+=200;
	}else{
		if(t[tr]>q[qr]){
			tr--;
			qr--;
			sum+=200;
		}else if(t[tr]<q[qr]){
			tl++;
			qr--;
			sum-=200;
		}
	}
}
	printf("%d",sum);
	
	return 0;
}
