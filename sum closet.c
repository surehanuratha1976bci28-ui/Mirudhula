#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Safe comparison function to prevent integer overflow
int compare(const void* a, const void* b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // Sort the array first
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Initialize closest sum with the first three elements
    int closest_sum = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            
            // If we found the exact target, return it immediately
            if (current_sum == target) {
                return current_sum;
            }
            
            // Update closest_sum if the current one is closer to the target
            if (abs(target - current_sum) < abs(target - closest_sum)) {
                closest_sum = current_sum;
            }
            
            // Move pointers based on how current_sum compares to target
            if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return closest_sum;
}
