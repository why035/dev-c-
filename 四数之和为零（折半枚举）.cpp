#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	int x=*(int*)a;
	int y=*(int*)b;
	return (x>y)-(x<y);
} 
//qsort(数组名，数量，sizeof(数据类型),cmp);
int low_bound(int*arr,int len,int x){
	int lo=0;//lo就是low最小值 
	int hi=len;//hi就是high最大值 
	while(lo<hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]>=x)
		hi=mid;
		else lo=mid+1;
		
	}
	return lo;
} 

int up_bound(int*arr,int len ,int x){
	int lo=0;
	int hi=len;
	while(lo<hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]>x)hi=mid;
		else lo=mid+1;
	}
	return lo;
}

int main(){
	int n;
	scanf("%d",&n);
	int*A=(int*)malloc(n*sizeof(int));//malloc是分配内存用的，malloc（数量*sizeof（数据类型））； 
	int*B=(int*)malloc(n*sizeof(int));
	int*C=(int*)malloc(n*sizeof(int));
	int*D=(int*)malloc(n*sizeof(int));
	for (int i=0;i<n;i++)scanf("%d",&A[i]);
	for (int i=0;i<n;i++)scanf("%d",&B[i]);
	for (int i=0;i<n;i++)scanf("%d",&C[i]);
	for (int i=0;i<n;i++)scanf("%d",&D[i]);
	
	int total=n*n;
	int*sumAB=(int*)malloc(total*sizeof(int));
	int idx=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			sumAB[idx++]=A[i]+B[j];	
		}
	}
	qsort (sumAB,total,sizeof(int),cmp);
	long long ans = 0;
	for ( int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			int target=-(C[i]+D[j]);
			int left=low_bound(sumAB,total,target);
			int right=up_bound(sumAB,total,target);
			ans=ans+(right-left);
		} 
		
	}	
	printf("%lld\n",ans);
	free(A);free(B);free(C);free(D);
	return 0;
}
