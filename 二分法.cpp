#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left=0;
    int right=numsSize-1;
    while(left<=right){
        int middle=left+(right-left)/2;
        if(nums[middle]<target){
            left=middle+1;
        }else if(nums[middle]>target){
            right=middle-1;
        }else{
            return middle;
        }
    }
    return -1;
}

int main()
{
    // 测试数组
    int arr[] = {-1,0,3,5,9,12};
    int len = sizeof(arr)/sizeof(arr[0]);
    int aim;
    printf("请输入要查找的数字：");
    scanf("%d",&aim);
    
    int res = search(arr, len, aim);
    printf("下标：%d\n",res);
    return 0;
}
