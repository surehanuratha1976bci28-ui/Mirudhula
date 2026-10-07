int removeDuplicates(int* nums, int numsSize) {
    // If the array is empty, there are 0 unique elements
    if (numsSize == 0) {
        return 0;
    }
    
    // 'k' tracks the index where the next unique element should be placed
    int k = 1; 
    
    // Iterate through the array starting from the second element
    for (int i = 1; i < numsSize; i++) {
        // If the current element is different from the previous one, it's unique
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i]; // Move the unique element forward
            k++;               // Increment the unique element count
        }
    }
    
    // Return the total number of unique elements
    return k;
}
