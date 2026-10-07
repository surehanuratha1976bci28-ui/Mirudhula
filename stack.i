#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    // Set the return size to 2 as we need to return [start, end]
    *returnSize = 2; 
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;
    if (numsSize == 0) {
        return result;
    }
    int low = 0, high = numsSize - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result[0] = mid; 
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (result[0] == -1) {
        return result;
    }
    low = 0;
    high = numsSize - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result[1] = mid; // Record potential ending position
            low = mid + 1;   // Keep searching right to find the absolute last index
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}
