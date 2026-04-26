#include<stdio.h>
int count(int M,int N){
	if (M==0) return 1;
	if(N==0) return 0;
	if(M<N) return count(M,M);
	else return count(M-N,N)+count(M,N-1);	
}
int main(){
	int t,M,N;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&M,&N);
		printf("%d",count(M,N));
	}
	/*
	while(t>0){
		scanf("%d %d",&M,&N);
		printf("%d",count(M,N));
		t--;
	}
	*/
	return 0;
} 
