#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		if(a%2!=0){
			printf("0 0");
		}else{
			
		if(a%4==0){
			printf("%d",a/4);
		}else{
			printf("%d",a/4+a%4/2);
		}
		printf(" %d",a/2);
	}
 }
} 
