#include<stdio.h>
int main(){
	int N,M;
	scanf("%d",&N);
	int dp[45];
	dp [1]=0;
	dp [2]=1;
	dp [3]=2;
	for (int i=4;i<45;i++){
		dp[i]=dp[i-1]+dp[i-2];
	} 
	while(N--){
		scanf("%d",&M);
		printf("%d",dp[M]);
	}
	
	return 0;
} 
