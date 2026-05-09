/*
问题 D：好斗的奶牛
题目描述
农夫约翰新建了一个长牛棚，有 N（2 ≤ N ≤ 100,000）个牛栏。
这些牛栏位于一条直线上，位置分别为 x1, ..., xN（0 ≤ xi ≤ 1,000,000,000）。
他有 C（2 ≤ C ≤ N）头奶牛。奶牛不喜欢这个牛棚的布局，一旦被关进牛栏，
就会变得好斗。为了防止奶牛互相伤害，FJ 想把奶牛分配到牛栏中，
使得任意两头奶牛之间的最小距离尽可能大。请问这个最大的最小距离是多少？
输入
第 1 行：两个空格分隔的整数 N 和 C
第 2 到第 N+1 行：第 i+1 行包含一个整数，表示第 i 个牛栏的位置 xi
输出
第 1 行：一个整数，表示最大的最小距离
样例输入
5 3
1 2 8 4 9
样例输出
3
提示
输出说明：
FJ 可以将 3 头奶牛放在位置 1、4 和 8 的牛栏中，此时最小距离为 3。
输入数据量大，建议使用 scanf。
*/
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	int x=*(int*)a;
	int y=*(int*)b;
	return(x>y)-(x<y);
	
}
int n,c;
int a[100005];

int check(int d){
	int cnt=1;
	int last=a[0];
	for(int i=1;i<n;i++){
		if(a[i]-last>=d){
		cnt++;
		last=a[i];
		if(cnt>=c) return 1;
}
	}
	return 0;
}

int main(){
	scanf("%d %d",&n,&c);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}	
	qsort(a,n,sizeof(int),cmp);
	int lo=0;
	int hi=a[n-1];
	int ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(check(mid)){
			ans=mid;
			lo=mid+1;
		}else{
			hi=mid-1;
		}
	}	
	printf("%d",ans);
	
	return 0;
}


