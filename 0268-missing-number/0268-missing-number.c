int missingNumber(int* nums, int numsSize) {
    // 0 ~ n 을 돌면서
    for (int i=0; i<numsSize+1; i++) {
        // nums에 없으면 return
        int cnt = 0;
        for (int j=0; j<numsSize; j++) {
            if (nums[j] == i) {
                cnt++;
            }
        }
        if (cnt == 0) {
            return i;
        }
    }
    return numsSize;
}