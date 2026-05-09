/*
你拥有n种标准钢轨长度，它们已经按照从小到大的顺序排列好(非降序列)。
现在有m次查询，每次给出一个理论最佳长度x。
你需要编写程序，从标准长度表中找出与x最接近的那个标准长度
注意:如果有两个标准长度与x的距离相等(例如x=5，标准长度有4和6)，
为了保证轨道的通用性和安全性，我们遵循“取小不取大”的原则(输出较小的那个，即4)，
这体现了工程中保守且稳健的设计思维
输入
第一行包含一个整数n，为标准钢轨长度的数量。1<=n<=100000。
第二行包含n个整数，为标准钢轨的长度(非降序列)。所有长度的大小均在0-1,000,000,000之间。
第三行包含一个整数m，为查询次数。1<=m<=10000。
接下来m行，每行一个整数，为设计部门给出的理论最佳长度。所有给定值的大小均在0-1,000.000.000之间。
输出
m行，每行一个整数，为最接近相应给定值的标准钢轨长度，
保持输入顺序。若有多个值满足条件，输出最小的一个。
样例输入
3 
2 5 8
2
10
5
样例输出
8
5
*/
#include<stdio.h>
#include<stdlib.h>  // 用于 abs 函数

int main() {
    int n;
    scanf("%d", &n);
    int a[100010];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int m;
    scanf("%d", &m);
    
    while (m--) {
        int x;
        scanf("%d", &x);
        
        // 二分查找：找到第一个 >= x 的位置
        int lo = 0, hi = n - 1;
        int pos = -1;  // 记录 >= x 的第一个位置
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] >= x) {
                pos = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        // 处理边界情况
        if (pos == -1) {
            // 所有数都小于 x
            printf("%d\n", a[n - 1]);
        } else if (pos == 0) {
            // 所有数都大于等于 x，第一个就是答案
            printf("%d\n", a[0]);
        } else {
            // 比较 a[pos] 和 a[pos-1] 哪个更接近 x
            int left = a[pos - 1];
            int right = a[pos];
            
            int diff_left = x - left;
            int diff_right = right - x;
            
            if (diff_left < diff_right) {
                printf("%d\n", left);
            } else if (diff_left > diff_right) {
                printf("%d\n", right);
            } else {
                // 距离相等，取较小的（左边的）
                printf("%d\n", left);
            }
        }
    }
    
    return 0;
}
