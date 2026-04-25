#include<stdio.h>
int main(){
	long long cell;
	scanf("%lld",&cell);
	int day=1;
	long long daycell=2;
	 while(daycell<cell){
		daycell=daycell*2-1;
		day++;
	}
	printf("%d",day);
	return 0;
}
