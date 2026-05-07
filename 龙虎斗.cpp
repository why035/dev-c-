#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int m,p1,s1,s2;
	scanf("%d %d %d %d",&m,&p1,&s1,&s2);
	int l=0;
	int h=0;
	int b=0;
	
	b=m;
	while(b>0){
		l += (m - b) * a[b-1];
		b--;
	}
	
	b = m;
	while(b < n){
		b++;
		h += (b - m) * a[b-1];
	}
	
	if(p1>m){
		h += s1*(p1-m);
	}else if(p1<m){
		l += s1*(m-p1);
	}

	int ans = m;
	int min_gap = abs(l - h);

	for(int p2=1; p2<=n; p2++){
		int now_l = l;
		int now_h = h;
		
		if(p2 < m){
			now_l += s2 * (m - p2);
		}else if(p2 > m){
			now_h += s2 * (p2 - m);
		}
		
		int gap = abs(now_l - now_h);
		if(gap < min_gap){
			min_gap = gap;
			ans = p2;
		}
	}

	printf("%d", ans);
	return 0;
}
