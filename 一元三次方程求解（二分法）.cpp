/*
有形如 ax^3+bx^2+cx+d=0 这样的一元三次方程。给出该方程中各项的系数
（a,b,c,d 均为实数），并约定该方程存在三个不同实根（根的范围在 -100 至
100 之间），且根与根之差的绝对值>=1。要求由小到大依次在同一行输出这三
个实根（根与根之间留有空格），并精确到小数点后2位。
*/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>//使用qsort时要使用的行头 
double a,b,c,d;
double f(double x){
	double result=a*x*x*x+b*x*x+c*x+d;
	return result;
}

int cmp(const void*a,const void*b){
	double x=*(double*)a;//整数就改 double 为 int 
	double y=*(double*)b;//整数就改 double 为 int
	return (x>y)-(x<y);//这是升序，降序就写成 return (y>x)-(y<x); 
} 


int main (){
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	double roots[3];
	int cnt=0; 
	for (int i=-100;i<100;i++){
		double l=(double)i;
		double r=(double)i+1.0;
		if(fabs(f(l))<1e-6){
			roots[cnt]=l;
			cnt++;
			continue;
		}
		if (f(l)*f(r)<0){
			double left=l;
			double right=r;
			while(right-left>1e-6){
				double mid=(right+left)/2;
				if(f(left)*f(mid)<0)
				right=mid;
				else
				left=mid;
			}
			roots[cnt]=(right+left)/2.0;
			cnt++;	
			
		}
		if (cnt==3) break;
		
	} 
	qsort(roots,3,sizeof(double),cmp);
	printf("%.2f %.2f %.2f",roots[0],roots[1],roots[2]); 
	return 0;
} 
