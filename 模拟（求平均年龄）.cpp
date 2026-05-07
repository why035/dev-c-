#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int total_age=0;
	double avg;
	int a=n;
	while(n--){
		int age;
		scanf("%d",&age);
		total_age+=age;
	}
	avg=(double)total_age/a;
	printf("%.2f",avg); 
	return 0;
}
