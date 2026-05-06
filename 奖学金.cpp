#include<stdio.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	int max_money=-1;
	int total_sum=0;
	int N=n;
	 char max_name[21]; 
	int sum[100]={0};
	while(n--){
	char name[21];
	int avg,class_num,lun;
	char stu,xi;
	scanf("%s %d %d %c %c %d",name,&avg,&class_num,&stu,&xi,&lun);
	int cnt=0;
	if (avg>80 && lun>0){
		cnt+=8000;
	}
	if(avg>85 && class_num>80){
		cnt+=4000;
	}
	if(avg>90){
		cnt+=2000;
	}
	if(avg>85 && xi=='Y'){
		cnt+=1000;
		
	}	
	if(class_num>80 && stu=='Y'){
		cnt+=850;
	}	
	total_sum+=cnt;
	sum[n]=cnt;
	if (cnt>max_money){
		max_money=cnt;
		strcpy(max_name,name);
	}
	
	}
	printf("%s\n%d\n%d\n",max_name,max_money,total_sum);
	return 0;
}
