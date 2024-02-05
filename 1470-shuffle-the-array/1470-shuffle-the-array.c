

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * numsSize);

    // 반복문 n번 돌면서, nums[i], nums[i+n] 을 result에 차례로 추가
    for (int i=0; i<n; i++) {
        result[2*i] = nums[i];
        result[2*i+1] = nums[i+n];
    }

    *returnSize = numsSize;
    return result;
}