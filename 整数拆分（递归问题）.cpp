#include<stdio.h>
#define mod 1000000007
int f(int n,int max){
	if (n==0) return 1;
	if (n<0||max<0) return 0;
	if(max==0) return 0;
	if(max>n) return f(n,n)%mod;
	
	if (max%2==0) return f(n,max-1)%mod;
	return (f(n,max-2)+f(n-max,max))%mod;
	
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n,n));
	
	
	
	return 0;
}
