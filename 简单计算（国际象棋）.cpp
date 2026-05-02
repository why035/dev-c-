/*王、后、车、象的走子规则如下
王:横、直、斜都可以走，但每步限走一格。
后:横、直、斜都可以走，每步格数不受限制。
车:横、竖均可以走，不能斜走，格数不限。
象:只能斜走，格数不限。
写一个程序，给定起始位置和目标位置，
计算王、后、车、象从起始位置走到目标位置所需的最少步数。
输入
第一行是测试数据的组数:(0<=t<=20)。以下每行是一组测试数据，每组包括棋盘上的两个位置，
第一个是起始位置，
第二个是目标位置。位置用"字母-数字"的形式表示，字母从"a"到"h"，数字从"!"到"8"。
输出
对输入的每组测试数据，输出王、后、车、象所需的最少步数。如果无法到达,就输出"In”.
样例输入
a1 c3
f5 f8
样例输出
2 1 2 1
3 1 1 Inf
*/


#include<stdio.h>
#include<stdlib.h>
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		char start[3],end[3];
		scanf("%s %s",start,end);
		int x1=start[0]-'a';
		int y1=start[1]-'1';
		int x2=end[0]-'a';
		int y2=end[1]-'1';
		int dx=abs(x1-x2);
		int dy=abs(y1-y2);
		int king=dy>dx?dy:dx;
		int queen;
		int rook;
		int xia;
		if (dx==0&&dy==0) {
		queen=0;
		rook=0;
		xia=0;
		printf("0 0 0 0");
		continue;
		
}
		if (dx==dy||dx==0||dy==0) {
		queen=1;
		}
		else queen=2;
		if (dx==0 ||dy==0) rook=1;
		else rook=2;
		if((x1+y1)%2!=(x2+y2)%2) {
		printf("%d %d %d Inf",king,queen,rook);
		}else if(dx==dy) {
		xia=1;
		printf("%d %d %d %d",king,queen,rook,xia);
		}else {
		xia=2;	
		printf("%d %d %d %d",king,queen,rook,xia);
		
		}
		

		
	}
	
	
	return 0;
}
