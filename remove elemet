int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Pointer to track the position of elements not equal to val
    
    for (int i = 0; i < numsSize; i++) {
        // If the current element is not equal to val, keep it
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k; // Return the count of valid elements
}
