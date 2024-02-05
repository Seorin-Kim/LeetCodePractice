/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * numsSize);

    // for문 돌며 주어진 조건에 맞는 수를 ans에 추가
    for (int i=0; i<numsSize; i++) {
        ans[i] = nums[nums[i]];
    }

    *returnSize = numsSize;
    return ans;
}