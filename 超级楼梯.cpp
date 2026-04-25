#include<stdio.h>
int main(){
 int N , M;
  int i; 
 int dp[45];
 scanf("%d",&N);
 dp[1]=0;
 dp[2]=1;
 dp[3]=2;
 for (i=4;i<45;i++){
	dp[i]=dp[i-1]+dp[i-2];
 }
 /*
 for (i=0;i<N;i++){
	scanf("%d",&M);
	printf("%d\n",dp[M]);
 }
*/
while(N--){
	scanf("%d",&M);
	printf("%d\n",dp[M]);
}

return 0;
}
