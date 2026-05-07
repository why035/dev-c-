/*
求矩阵的两对角线上的元素之和
输入
矩阵的行数N
和一个N*N的整数矩阵a[N][N](N<=10)
输出
所输矩阵的两对角线上的元素之和
样例输入
3
1 2 3
4 5 6
7 8 9
样例输出
25 
*/

#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int a[N][N];
	int b=N-1;
	int c=0;
	int d=0;
	int ans=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<N;i++){
			c+=a[i][i];
			d+=a[i][N-1-i];
	}
	if(N%2!=0){
		ans=c+d-a[N/2][N/2];
		
	}else{
		ans=c+d;
	}

	printf("%d",ans);
	return 0;
}
