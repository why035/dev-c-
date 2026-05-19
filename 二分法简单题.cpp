#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止溢出
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // 循环结束时，left 就是 target 应该插入的位置
    return left;
}

int main() {
    int nums1[] = {1,3,5,6};
    int target1 = 5;
    printf("示例1输出：%d\n", searchInsert(nums1, 4, target1));

    int nums2[] = {1,3,5,6};
    int target2 = 2;
    printf("示例2输出：%d\n", searchInsert(nums2, 4, target2));

    int nums3[] = {1,3,5,6};
    int target3 = 7;
    printf("示例3输出：%d\n", searchInsert(nums3, 4, target3));

    return 0;
}
