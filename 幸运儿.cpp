#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[55], out[55];
        int len = n, outCnt = 0;
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        } 
        while (len > 2) {
            int next[55], nextLen = 0;
            for (int i = 0; i < len; i++) {
                if (i % 2 == 1) { 
                    out[outCnt++] = a[i];
                } else {
                    next[nextLen++] = a[i];
                }
            }
            for (int i = 0; i < nextLen; i++) {
                a[i] = next[i];
            }
            len = nextLen;
        } 
        for (int i = 0; i < outCnt; i++) {
            printf("%d ", out[i]);
        }
        printf("\n");
        if (a[0] < a[1]) {
            printf("%d %d\n", a[0], a[1]);
        } else {
            printf("%d %d\n", a[1], a[0]);
        }
    }
    return 0;
}
