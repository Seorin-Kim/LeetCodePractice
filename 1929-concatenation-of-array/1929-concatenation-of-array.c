/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * numsSize * 2);

    // nums의 모든 원소를 ans에 추가 -> 2회 반복
    for (int i=0; i<2; i++) {
        for (int j=0; j<numsSize; j++) {
            ans[i*numsSize + j] = nums[j];
        }
    }

    *returnSize = numsSize * 2;
    return ans;
}