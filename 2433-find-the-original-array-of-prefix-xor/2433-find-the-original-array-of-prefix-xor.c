/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int prefSize, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * prefSize);
    
    // pref 돌면서, 다음 것과 ^ 연산한 결과를 arr에 저장
    for (int i=0; i<prefSize; i++) {
        if (i == 0) {
            arr[i] = 0 ^ pref[i];
        } else {
            arr[i] = pref[i-1] ^ pref[i];
        }
    }

    *returnSize = prefSize;
    return arr;
}