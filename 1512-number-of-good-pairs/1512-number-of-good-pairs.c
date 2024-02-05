int numIdenticalPairs(int* nums, int numsSize) {
    int ans = 0;

    // i,j 차례대로 for문 돌면서,
    for (int i=0; i<numsSize; i++) {
        for (int j=0; j<numsSize; j++) {
            // 조건에 맞으면 ans++
            if ((i < j) && (nums[i] == nums[j])) {
                ans++;
            }
        }
    }

    return ans;
}