#include<stdio.h>
int main(){
	long long n;
	scanf("%lld",&n);
	long long current=1;
	int student=1;
	while (current<n){
		current=current*2+3;
		student++;
	}
	printf("%d",student);
	
	
	return 0;
}
